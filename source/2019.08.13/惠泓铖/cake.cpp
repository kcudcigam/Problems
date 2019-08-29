#include <bits/stdc++.h>
using namespace std;

long long f[301][301], n, m;

int main(){
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	cin>>n>>m;
	memset(f, 0, sizeof(f));
	f[2][1] = f[1][2] = f[1][1] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 1; k < i; k++){
				f[i][j] += f[k][j] * f[i-k][j];
				f[i][j] %= 1000000007;
			}
			for (int k = 1; k < j; k++){
				f[i][j] += f[i][k] * f[i][j-k];
				f[i][j] %= 1000000007;
			}
			f[2][1] = f[1][2] = f[1][1] = 1;
			f[i][j] %= 1000000007;
		}
	}
	printf("%lld", f[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
