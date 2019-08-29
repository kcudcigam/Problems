#include<bits/stdc++.h>
using namespace std;

int read()
{
	int n=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n*f;
}

int a[1001],b[1001],c[1001],f1[20001],f2[20001];
int f[501][501],p[501][501];

int main()
{
    freopen("deal.in","r",stdin);
    freopen("deal.out","w",stdout);
	memset(f,-1,sizeof(f));
	memset(p,-1,sizeof(p));
	int n,m;
	long long ans=0;
	long long maxn=1000000007;
	n=read();m=read();
	for (int i=n;i>=1;i--)
	{
		a[i]=read();b[i]=read();c[i]=read();
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=a[i];j<=m+a[i]-1;j++)
		{
			int t=0;
			for (int k=1;k<=b[i];k++)
			{
				if (a[i]*k>j) break;
				if (j-a[i]*k==0||f[i-1][j-a[i]*k]>0) t++;
			}
			f[i][j]=t;
			if (f[i][j]>0) f1[j]+=f[i][j];
			f[i][j]=max(t,f[i-1][j]);
		//	cout<<"!!!  "<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=a[i];j<=a[1];j++)
		{
			int t=0;
			for (int k=1;k<=c[i];k++)
			{
				if (a[i]*k>j) break;
				if (j-a[i]*k==0||p[i-1][j-a[i]*k]>0) t++;
			}
			p[i][j]=t;
			if (p[i][j]>0) f2[j]+=p[i][j];
			p[i][j]=max(p[i-1][j],t);
			//if (f[i][j]==-1) break;
		}
	}
	for (int i=m;i<=m+a[n];i++)
	{
	//	cout<<i<<" "<<f1[i]<<" "<<f2[i-m]<<endl;
		if (i==m) ans=(ans+f1[i])%maxn;
 		else ans=(ans+(f1[i]*f2[i-m]%maxn))%maxn;
	}
	cout<<ans<<endl;
	return 0;
}
