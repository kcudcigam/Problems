#include<bits/stdc++.h>
using namespace std;
const long long p=1000000007;
int n,m,i,j,k,l,s,d,r;
long long f[400][400];
int main() {
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d %d",&n,&m);
	f[1][1]=1;
	for(i=1;i<=n;++i){
		for (j=1;j<=m;++j){
			if(i==1&&j==1){
				continue;
			}
			for(k=1;k<j;++k){
				f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%p;
			}
			for(k=1;k<i;++k){
				f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%p;
			}
		}
	}
	printf("%lld\n", f[n][m]);
	return 0;
}
