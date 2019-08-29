#include<bits/stdc++.h>
#define ll long long
const ll maxn=5000+5,INF=-0x3f3f3f3f;
using namespace std;
int dp[maxn][maxn];
int n;
int a[5];
int work(int x){
	return a[0]+a[1]*x+a[2]*x*x+a[3]*x*x*x;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&a[3],&a[2],&a[1],&a[0]);
	int h;
	for(int i=1;i<=n;i++){scanf("%d",&h);dp[i][i]=work(h);}
	for(int j=1;j<=n;j++)
		for(int i=1;i<j;i++)
			dp[i][j]=INF;
if(n<=5000){
	for(int j=1;j<=n;j++)
		for(int i=j-1;i>=1;i--)
			for(int k=1;k<=j-i;k++){
			dp[i][j]=max(max(dp[i][i+k-1],dp[i+k][j]),max(dp[i][j],dp[i][i+k-1]+dp[i+k][j]));
		
			}
	printf("%d\n",dp[1][n]);}
else {
	int ans=0,jk=INF;
	for(int i=1;i<=n;i++){
		if(dp[i][i]>jk)jk=dp[i][i];
		ans+=dp[i][i];
	}
	printf("%d",max(jk,ans));;
	
}
	return 0;
}
/*		printf("%d %d\n",i,j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",dp[i][j]);
			printf("\n");}
			
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",dp[i][j]);
		printf("\n");}*/
/**/
