#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dp[300][300];
int n,m;
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	dp[1][1]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]){
				continue;
			}
			for(int k=1;k<i;k++){
				dp[i][j]=(dp[i][j]+(dp[k][j]*dp[i-k][j])%mod)%mod;
			}
			for(int k=1;k<j;k++){
				dp[i][j]=(dp[i][j]+(dp[i][k]*dp[i][j-k])%mod)%mod;
			}
			dp[j][i]=dp[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dp[i][j]<<"\t";
//		}
//		cout<<endl;
//	}
	cout<<dp[n][m];
	return 0;
}
