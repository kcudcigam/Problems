#include<cstdio>
#define p 1000000007
using namespace std;
int n,m;
int f[500][500];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][1] = 1;
	for (int i = 2; i <= m; ++ i)
		for (int j = 1; j < i; ++ j)
			f[1][i] = (f[1][i]+f[1][j]*f[1][i-j]) % p;
	for (int i = 2; i <= n; ++ i)
		for (int j = 1; j < i; ++ j)
			f[i][1] = (f[i][1]+f[j][1]*f[i-j][1]) % p;
	for (int i = 2; i <= n; ++ i)
		for (int j = 2; j <= m; ++ j){
			for (int k = 1; k < i; ++ k)
				f[i][j] = (f[i][j]+f[k][j]*f[i-k][j])%p;
			for (int k = 1; k < j; ++ k)
				f[i][j] = (f[i][j]+f[i][k]*f[i][j-k])%p;
		}
	printf("%d",f[n][m]%p);
	return 0;
}


