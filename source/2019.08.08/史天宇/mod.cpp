#include<cstdio>
#define MaxN 10000010

typedef long long LL;

int T, n, p;
LL f[MaxN];

int main() {
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	scanf("%d", &T);
	for (; T; T--) {
		scanf("%d %d", &n, &p); f[1] = 0;
		for (int i = 2; i <= n; ++i) {
			f[i] = f[i - 1] * i % p;
			f[i] = i & 1 ? (f[i] + 1LL * i * (i - 1)) % p : (f[i] + 1LL * (i - 2) * (i - 1) + i) % p;
		}
		printf("%lld", f[n]);
	}
	return 0;
}
