#include<cstdio>
#include<cctype>
#include<algorithm>
#define MaxN 100010

typedef long long LL;

LL f[MaxN], g[MaxN], s, ans;
int n, a[MaxN];

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	s = f[1] = a[1];
 	for (int i = 2; i <= n; ++i) {
 		s = s > 0 ? s + a[i] : a[i];
 		f[i] = std::max(f[i - 1], s);
	}
	s = g[n] = a[n];
	for (int i = n - 1; i; --i) {
		s = s > 0 ? s + a[i] : a[i];
		g[i] = std::max(g[i + 1], s);
	}
	for (int i = 1; i < n; ++i) 
		ans = std::max(ans, f[i] + g[i + 1]);
	printf("%lld\n", ans);
	return 0;
}
