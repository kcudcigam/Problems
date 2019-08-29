#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[500][500],p=1000000007;
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int i,j,k;
	cin>>n>>m;
	dp[1][1]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			for(k=1;k<=j;k++){
				dp[i][j]=(dp[i][j]+(dp[i][j-k]*dp[i][k]%p))%p;
			}
			for(k=1;k<=i;k++){
				dp[i][j]=(dp[i][j]+(dp[i-k][j]*dp[k][j])%p)%p;
			}
		}
	cout<<dp[n][m];
	return 0;
}

