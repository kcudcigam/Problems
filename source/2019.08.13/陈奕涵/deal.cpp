#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int maxn=110,maxm=210;
int n,X;
int maxv;
int m[maxn],a[maxn],b[maxn];
namespace buyer{
	int dp[maxn][maxm],ans[maxm];
	void init(){
		for(int i=0;i<=maxv;++i){
			ans[i]=dp[n][i];
			for(int k=1;k<=n && m[k]<=i-X;++k){
				ans[i]-=dp[k][i];
			}
		}
	}
	void bag(){
		dp[0][0]=1;
		for(int i=1;i<=n;++i){
			for(int k=1;k<=a[i];++k){
				for(int j=0;j<m[i]+X;++j){
					if(j<k*m[i])
						dp[i][j]=max(dp[i][j],dp[i-1][j]);
					else
						dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i-1][j-k*m[i]]);	
				}
			}
		}
		init();
	}
}
namespace seller{
	int dp[maxn][maxm],ans[maxm];
	void init(){
		for(int i=0;i<=maxv;++i){
			ans[i]=dp[n][i];
			for(int k=1;k<=n && m[k]<=i-X;++k){
				ans[i]-=dp[k][i];
			}
		}	
	}
	void bag(){
		dp[0][0]=1;
		for(int i=1;i<=n;++i){
			for(int k=1;k<=b[i];++k){
				for(int j=0;j<m[i]+X;++j){
					if(j<k*m[i])
						dp[i][j]=max(dp[i][j],dp[i-1][j]);
					else
						dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i-1][j-k*m[i]]);	
				}
			}
		}
		init();
	}
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	cin>>n>>X;
	for(int i=1;i<=n;++i){
		cin>>m[i]>>a[i]>>b[i];
	}
	maxv=X+m[n];
	//DP
	buyer::bag();
	seller::bag();
	//ºÏ²¢´ð°¸ 
	long long ans=0;
	for(int i=X;i<=maxv;++i){
		ans+=buyer::ans[i]*seller::ans[i-X];
		ans%=mod;
	}
	cout<<ans%mod<<endl;
	return 0; 
} 
