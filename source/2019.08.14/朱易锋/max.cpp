#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
    R int f=1,num=0;
    R char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
const int N=100000+7;
const ll mod=1e9+7;
int X[N],Y[N];
double p[N];
int n,m,q;
double Ans=0.00;
bool v[107];
int flag1=0,flag2=0;
int l[N],r[N];
int val[107];
V dfs(R int now)
{
	if(now==n+1)
	{
		memset(val,0,sizeof(val));
		double ans=1.00;
		for(R int i=1;i<=m;i++)
		{
			if(v[i]==0)ans*=(1.00-p[i]);
			else
			{
				ans*=p[i];
				val[X[i]]+=Y[i];
			}
		}
		R int res=0;
		for(R int i=1;i<=q;i++)
		{
			R int mixx=0;
			for(R int j=l[i];j<=r[i];j++)
			{
				mixx=max(val[j],mixx);
			}
			res+=mixx;
		}
		Ans+=(double)res*(double)ans;
		return;
	}
	if(p[now]==1.00)v[now]=1,dfs(now+1);
	else
	{
		v[now]=1;
		dfs(now+1);
		v[now]=0;
		dfs(now+1);
	}
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=read();m=read();q=read();
	for(R int i=1;i<=m;i++)
	{
		X[i]=read(),Y[i]=read();
		R int P=read();
		if(P>1)p[i]=(double)P/mod;
		else p[i]=(double)P;
	}
	for(R int i=1;i<=q;i++)
	{
		l[i]=read(),r[i]=read();
		if(l[i]!=r[i])flag1=1,flag2=i;
	}
	if(q==n)
	{
		for(R int i=1;i<=m;i++)
		{
			val[X[i]]+=Y[i];
			Ans+=(double)p[i]*(double)Y[i];
		}
	}
//	else if(q==n-1)
//	{
//		R int val1=0,val2=0;
//		for(R int i=1;i<=m;i++)
//		{
//			if(X[i]>=l[flag2]&&X[i]<=r[flag2])
//			{
//				if(X[i]==l[flag2])val1=Y[i];
//				else val2=Y[i];
//				continue;
//			}
//			Ans+=(double)p[i]*(double)Y[i];
//		}
//		Ans+=(double)p[l[flag2]]*p[r[flag2]]*val1*val2;
//		Ans+=(double)(1.00-p[l[flag2]])*p[r[flag2]]*val2;
//		Ans+=(double)(1.00-p[r[flag2]])*p[l[flag2]]*val1;
//	}
	else
	{
		dfs(1);
	}
	while(Ans>mod)Ans-=mod;
	cout<<Ans<<endl;
	return 0;
}
