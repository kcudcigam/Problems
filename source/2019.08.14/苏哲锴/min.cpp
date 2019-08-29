#include<bits/stdc++.h>
using namespace std;
int n,A,B,C,D;
const int N=5001;
int   dp[N][N];
int a[100001];
int fun (int x){
	return A*x*x*x+B*x*x+C*x+D;
}
int mi(int i,int j){
	int ans=1e9;
	for(int k=i;k<=j;k++){
		ans=min(ans,a[k]);
	}
	return ans;
}
bool sub1;
int main(){
freopen("min.in","r",stdin);
freopen("min.out","w",stdout);
cin>>n>>A>>B>>C>>D;
if(A==0&&B==0&&C<=0) sub1=true;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	
} 
if(sub1||A>=0&&B>=0&&C>=0) {long long ansa=0;
	for(int i=1;i<=n;i++) {
	if(fun(a[i])>0)
	ansa+=fun(a[i]);}
	cout<<ansa<<endl;
	exit(0);
}

for(int i=1;i<=n;i++){
	dp[i][i]=fun(a[i]);}
for(int i=1;i<=n;i++){
	for(int j=i+1;j<=n;j++){
		for(int k=i;k<=j;k++)
		dp[i][j]=max(fun(mi(i,j)),dp[i][k]+dp[k][j] );
		
	}}
  cout<<dp[1][n]<<endl;
	return 0;
}


