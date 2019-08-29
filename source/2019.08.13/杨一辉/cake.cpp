#include<bits/stdc++.h>
using namespace std;
int n,m;
int p=1000000007;
long long f[305],dp[305][305];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	f[1]=1;f[2]=1;
	for(int i=3;i<=300;i++)
	{
		for(int j=1;j<i;j++)
		{
			f[i]=(f[i]+(f[j]%p*f[i-j]%p)%p)%p;
		}
	}
	for(int i=1;i<=300;i++)
	{
		dp[1][i]=f[i];
		dp[i][1]=f[i];
	}
	for(int k=2;k<=300;k++)
	{
		for(int i=k;i<=300;i++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i][k]=(dp[i][k]+(dp[j][k]%p*dp[i-j][k]%p)%p)%p;
			}
			for(int j=1;j<k;j++)
			{
				dp[i][k]=(dp[i][k]+(dp[i][j]%p*dp[i][k-j]%p)%p)%p;
			}
			dp[k][i]=dp[i][k];
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
