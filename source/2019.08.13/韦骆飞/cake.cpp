#include <bits/stdc++.h>
using namespace std;
long long f[1000][1000],n,m;
int maxn=1000000007;
int main()
{
	ios::sync_with_stdio(false);
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	f[1][1]=1;
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++)
	    {
	    	for (int k=1;k<i;k++)
	    	  f[i][j]=(long long)(f[i][j]+f[k][j]*f[i-k][j])%maxn;
	    	for (int k=1;k<j;k++)
	    	  f[i][j]=(long long)(f[i][j]+f[i][k]*f[i][j-k])%maxn;
		}
	cout<<f[n][m]<<endl;
	return 0;
}
