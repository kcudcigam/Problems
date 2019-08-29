#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define R register
const int mod=1e9+7;
int n,m;
#define ll long long
ll dp[330][330]; 
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	dp[1][1]=1;
	for(R int i=2;i<=m;i++){
		for(R int k=1;k<i;k++){
			dp[1][i]+=dp[1][k]*dp[1][i-k]%mod;
			dp[1][i]%=mod;
		}
	}
	for(R int i=2;i<=n;i++){
		for(R int j=1;j<=m;j++){
			for(R int k=1;k<i;k++){
				dp[i][j]+=dp[k][j]*dp[i-k][j]%mod;
				dp[i][j]%=mod;
			}
			for(R int k=1;k<j;k++){
				dp[i][j]+=dp[i][k]*dp[i][j-k]%mod;
				dp[i][j]%=mod;
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
