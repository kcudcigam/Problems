#include<cstdio>
#define MOD 1000000007
#define MaxN 310

typedef long long LL;

int n, m;
LL f[MaxN][MaxN];

int main() {
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	scanf("%d %d", &n, &m);
	f[1][1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (i == 1 && j == 1) continue;
			for (int k = 1; k < j; ++k) f[i][j] = (f[i][j] + f[i][k] * f[i][j - k]) % MOD;
			for (int k = 1; k < i; ++k) f[i][j] = (f[i][j] + f[k][j] * f[i - k][j]) % MOD;
		}
	printf("%lld\n", f[n][m]);
	return 0;
}
