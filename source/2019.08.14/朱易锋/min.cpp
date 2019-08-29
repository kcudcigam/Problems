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
const int N=3007;
int st[N][30];
int bin[30];
int a[N],n=0,A=0,B=0,C=0,D=0;
ll f[1007][1007];
I ll F(R int x)
{
	return A*x*x*x+B*x*x+C*x+D;
}
I V pre()
{
	for(R int i=1;i<=n;i++)
	{
		st[i][i]=a[i];
	}
	for(R int k=1;k<=30;k++)
	{
		for(R int i=1;i<=n;i++)
		{
			if(i+bin[k]>n)continue;
			st[i][k]=min(st[i][k-1],st[i+bin[k-1]][k-1]);
		}
	}
}
I int get(R int l,R int r)
{
	R int len=(r-l+1);
	R int k=0;
	while(bin[k]<=len)k++;
	k--;
	return min(st[l][k],st[r-bin[k]][k]);
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=read();
	A=read(),B=read(),C=read(),D=read();
	bin[0]=1;
	for(R int i=1;i<=n;i++)bin[i]=bin[i-1]<<1;
	for(R int i=1;i<=n;i++)
	{
		a[i]=read();
		f[i][i]=F(a[i]);
	}
	pre();
	for(R int len=2;len<=n;len++)
	{
		for(R int i=1;i<=n;i++)
		{
			if(i+len-1>n)continue;
			for(R int j=i+1;j<=i+len-1;j++)
			{
				f[i][i+len-1]=max(F(get(i,i+len-1)),f[i][j-1]+f[j][i+len-1]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}
