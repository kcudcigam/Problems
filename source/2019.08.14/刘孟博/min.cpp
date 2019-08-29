#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
typedef long long ll;
int n;
ll a[MAXN],f[MAXN][20],dp[MAXN][MAXN],ans=-1e14,A,B,C,D;
inline void init(){
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j<=n-(1<<i)+1;j++)f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
}
inline ll calc(int l,int r){
	int t=log2(r-l+1);ll p=min(f[l][t],f[r-(1<<t)+1][t]);
	return A*p*p*p+B*p*p+C*p+D;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d%lld%lld%lld%lld",&n,&A,&B,&C,&D);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),f[i][0]=a[i];
	init();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)dp[i][j]=-1e14;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			for(int k=0;k<i;k++)
			if(dp[k][j-1]!=-1e14)dp[i][j]=max(dp[i][j],dp[k][j-1]+calc(k+1,i));
	for(int i=1;i<=n;i++)ans=max(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;
}
