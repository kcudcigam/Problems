#include<cstdio>
using namespace std;
const long long mod=1e9+7;
int n,m;long long f[305][305];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	f[1][1]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			for(int k=1;k<i;++k){
				f[i][j]+=f[k][j]*f[i-k][j]%mod;
				f[i][j]%=mod;
			}
			for(int k=1;k<j;++k){
				f[i][j]+=f[i][k]*f[i][j-k]%mod;
				f[i][j]%=mod;
			}
		}
	printf("%lld",f[n][m]);
	return 0;
}

