#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[305]; 
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	dp[1]=0;
	dp[2]=1;
	if(n==1){
		for(i=3;i<=m;i++)
		{
			for(j=1;j<=i/2;j++)
			{
				dp[i]+=max(dp[i-j],dp[j]);
				dp[i]%=1000000007;	
			}
		}
		printf("%lld",dp[m]);
		return 0;
	}
	return 0;
}


