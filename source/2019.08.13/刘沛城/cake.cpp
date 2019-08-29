#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
#define im INT_MAX
#define mo 1000000007
ak dp[333][333];
int main(){
	#ifndef lpcak
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	#endif
	ak n,m;
	ios::sync_with_stdio(0);
	cin>>n>>m;dp[1][1]=1;
	F(i,1,m)dp[0][i]=1;F(i,1,n)dp[i][0]=1;
	F(i,1,n)F(j,1,m){
		if(i*j==1)continue;
		F(k,1,i-1){
			if(!(i-1))break;
			dp[i][j]+=dp[k][j]*dp[i-k][j]%mo;
			dp[i][j]%=mo;
		}
		F(k,1,j-1){
			if(!(j-1))break;
			dp[i][j]+=dp[i][k]*dp[i][j-k]%mo;
			dp[i][j]%=mo;
		}
	}
	cout<<dp[n][m]<<"\n";
	return 0;
}
