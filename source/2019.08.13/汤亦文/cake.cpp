#include<bits/stdc++.h>
using namespace std;
int n,m;
long long f[400][400];
#define p 1000000007
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
	  for(int k=1;k<i;k++)
	  f[i][j]+=f[k][j]*f[i-k][j]%p;
	  for(int k=1;k<j;k++)
	  f[i][j]+=f[i][k]*f[i][j-k]%p;
	}
	cout<<f[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
