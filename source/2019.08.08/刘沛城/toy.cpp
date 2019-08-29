#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
ak a[1111],dp[1111][1111];
int main(){
	#ifndef lpcak
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	#endif
	int n,m,ans=0;
	ios::sync_with_stdio(0);
	cin>>n>>m;F(i,1,n)cin>>a[i];
	F(i,0,n)F(j,1,n)dp[i][j]=im;
	dp[0][0]=0,dp[1][1]=a[1],dp[2][1]=a[2];
	F(i,3,n){
		dp[i][1]=min(a[i],dp[i-1][1]);
		F(j,2,i+1>>1)
			dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+a[i]);
	}
	F(i,1,n+1>>1)if(dp[n][i]<=m)ans=i;cout<<ans<<"\n";
	return 0;
}
