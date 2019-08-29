#include<bits/stdc++.h>
using namespace std;
int n,mod,dp[2];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>mod;
		dp[1]=0;
		for(int i=2;i<=n;i++){
			int t1=i%2,t2=!t1;
			dp[t1]=(dp[t2]+i)*i-i;
			if(!t1){
				dp[t1]-=i-2;
			}
			dp[t1]%=mod;
		}
		cout<<dp[n%2]<<endl;
	}
	return 0;
}
