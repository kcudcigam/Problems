#include<cstdio>
#include<cctype>
#define MaxN 500010

typedef long long LL;

LL n, m, l, r, start, end, interval, f[MaxN], g[MaxN], sum, ans;

inline LL read() {
	LL x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(); m = read();
	for (int i = 1; i <= m; ++i) {
		l = read(); r = read(); start = read(); end = read();
		int interval = (end - start) / (l == r ? 1 : r - l);
		f[l] += start; f[r + 1] -= end;
		g[l] += interval; g[r + 1] -= interval;
	}
	sum = 0; interval = 0;
	for (int i = 1; i <= n; ++i) {
		sum += f[i] + interval; interval += g[i];
		ans = ans ^ sum;
	}
	printf("%lld\n", ans);
	return 0;
}
