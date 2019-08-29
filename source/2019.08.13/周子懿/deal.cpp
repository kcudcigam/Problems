#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,x,k,a[N],b[N],c[N],f[N][110],h[N][110],t[N][110],t1[N][110],t2[N][110],back[110][N],ans;
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<x+a[n];j++)
		{
			t1[i][j]=t1[i-1][j];
			t2[i][j]=t2[i-1][j];
		}
		for(int j=1;j<x+a[n];j++)
		{
			for(k=1;k<=b[i]&&j>k*a[i];k++)
				f[i][j]=f[i][j]+t1[i-1][j-k*a[i]];
			if(j==k*a[i]&&k<=b[i])f[i][j]++;
			for(k=1;k<=c[i]&&j>k*a[i];k++)
				h[i][j]=h[i][j]+t2[i-1][j-k*a[i]];
			if(j==k*a[i]&&k<=c[i])h[i][j]++;
			t1[i][j]+=f[i][j];
			t2[i][j]+=h[i][j];
		}
	}
	ans+=t1[n][x];
	for(int j=x+1;j<x+a[n];j++)
	{
		ans+=(t1[n][j]-f[n][j])*t2[n][j-x];
	}
	cout<<ans<<endl;
	return 0;
}


