#include<bits/stdc++.h>
using namespace std;
const int N=100001;
const int Mo=1000000007;
int c[N],a[N],b[N];
int dp[101][N];
int main(){
freopen("deal.in","r",stdin);
freopen("deal.out","w",stdout);
int n,X;
cin>>n>>X;
for(int i=1;i<=n;i++) 
scanf("%d%d%d",&a[i],&b[i],&c[i]);
for(int i=1;i<=n;i++){

	dp[i][a[i]]=1;
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=X;j++){
		for(int k=-c[i];k<=b[i];k++){
			if(j-k*a[i]>0||j-k*a[i]<=X)
			dp[i][j-k*a[i]]+=dp[i-1][j];
		}
	}
}
cout<<dp[n][X]%Mo<<endl;
	return 0;
}


