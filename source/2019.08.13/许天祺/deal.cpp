#include<bits/stdc++.h>
#define int long long
#define mo 1000000007
using namespace std;
int read(){
	int num=0,f=1; char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar();}
	while(isdigit(c)){num=num*10+c-'0'; c=getchar();}
	return num*f;
}
int n,X,a[1005],b[1005],c[1005],opt[50005],x[50005];
signed main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=read();
	X=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=read();
		c[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		memset(x,0,sizeof(x));
		opt[X]=1;
		if (a[i]*c[i]>X)
		{
			opt[X-(X/a[i]*a[i])]++;
			x[X-(X/a[i]*a[i])]=-X/a[i];
		}
		else
		{
			opt[X-a[i]*c[i]]++;
			x[X-a[i]*c[i]]=-c[i];
		}
		for(int j=-a[i]*(c[i]-1);j<=X;j++)
		{
			if (j==0) continue;
			if (x[X+j-a[i]]<b[i])
			{
				opt[X+j]+=opt[X+j-a[i]];
//				if (x[X+j-a[i]])
				opt[X+j]%=mo;
				x[X+j]=min(x[X+j],x[X+j-a[i]]+1);
			}
			
		}
//	for(int i=0;i<=X*2;i++)
//		cout<<i-X<<" "<<opt[i]<<" "<<x[i]<<endl;
//	cout<<endl;
	}
	cout<<opt[X+X]<<endl;
	return 0;
}

