#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,MOD=1000000007;
long long f[301][301];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	
	f[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k1=1;k1<=i;++k1){
				f[i][j]+=(f[k1][j]*f[i-k1][j])%MOD;
				f[i][j]%=MOD;
			}
			for(int k1=1;k1<=j;++k1){
				f[i][j]+=(f[i][k1]*f[i][j-k1])%MOD;
				f[i][j]%=MOD;
			}
		}
	}
	
	cout<<f[n][m]<<endl;
	return 0;
}


