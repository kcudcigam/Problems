#include<bits/stdc++.h>
#define INF 10000000000000000
using namespace std;
long long n,ans,a[100005],dp[100005][3];
long long Max(long long a,long long b){
	if(a>b){
		return a;
	}
	return b;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	ans=-INF;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n+1;i++){
		dp[i][0]=-INF;
		dp[i][1]=-INF;
		dp[i][2]=-INF;
		dp[i][3]=-INF;
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=Max((long long)0,dp[i-1][0])+a[i];
		dp[i][1]=Max(dp[i][0],dp[i-1][1]);
	}
	for(int i=n;i>=1;i--){
		dp[i][2]=Max((long long)0,dp[i+1][2])+a[i];
		dp[i][3]=Max(dp[i][2],dp[i+1][3]);
	}
	for(int i=1;i<n;i++){
		ans=Max(ans,dp[i][1]+dp[i+1][3]);
	}
	cout<<ans;
	return 0;
}
