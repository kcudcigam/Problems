#include<cstdio>
#include<cctype>
#define MaxN 500010

int n, q, tot, opt, x, y, fa[MaxN], f[MaxN], val[MaxN];
bool vis[MaxN];

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x =  x * 10 + c - '0';
	return x * f;
}

inline int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int tx = find(x), ty = find(y);
	if (tx == ty) return ;
	f[x] = fa[x] = f[y] = fa[y] = ++tot;
	fa[tot] = tot;
}

void getval(int x) {
	if (vis[x]) return ;
	if (f[x]) getval(f[x]);
	val[x] += val[f[x]];
	vis[x] = 1;
}

int main() {
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	n = read(); q = read(); tot = n;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= q; ++i) {
		opt = read(); x = read(); y = read();
		if (opt == 1) merge(x, y);
		else val[find(x)] += y;
	}
	for (int i = 1; i <= n; ++i) getval(i);
	for (int i = 1; i < n; ++i) printf("%d ", val[i]);
	printf("%d\n", val[n]);
	return 0;
}
