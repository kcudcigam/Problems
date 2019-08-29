#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m,f[301][301];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][1]=1;
	int ma=max(n,m);
	for(int i=2;i<=ma;++i){
		for(int j=1;j<i;++j){
			f[i][1]+=f[j][1]*f[i-j][1]%mod;
			f[1][i]=f[i][1];
		}
		f[i][1]%=mod;
	}
	for(int i=2;i<=m;++i){
		for(int j=2;j<=n;++j){
			for(int k=1;k<i;++k){
				f[i][j]+=f[k][j]*f[i-k][j]%mod;
			}
			for(int k=1;k<j;++k){
				f[i][j]+=f[i][k]*f[i][j-k]%mod;
			}
			f[i][j]%=mod;
		}
	}
	printf("%d",f[m][n]);
	return 0;
}

                            
