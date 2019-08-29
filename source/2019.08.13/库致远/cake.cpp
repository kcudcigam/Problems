#include <cstdio>
#include <iostream>

using namespace std;

const int mod=1000000007;

long long dp[301][301][3];
int n,m;
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	dp[1][1][0]=dp[1][1][1]=dp[1][1][2]=1;
	for ( int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			if (i==1 && j==1)
				continue;
			for (int k=1;k<i;++k)
				dp[i][j][1]=(dp[i][j][1]+dp[k][j][0]*dp[i-k][j][0]%mod)%mod;
			for (int k=1;k<j;++k)
				dp[i][j][2]=(dp[i][j][2]+dp[i][k][0]*dp[i][j-k][0]%mod)%mod;
			dp[i][j][0]=(dp[i][j][1]+dp[i][j][2])%mod;	
		}
	}
	cout<<dp[n][m][0]<<endl;
	return 0;
}
