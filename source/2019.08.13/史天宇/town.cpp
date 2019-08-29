#include<cstdio>
#include<cctype>
#define MaxN 300010
#define MaxM 600010

struct edge {int v, nxt;} e[MaxM];

int n, x, y, tot, head[MaxN], len, len_x;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

void addedge(int x, int y) {
	e[++tot] = (edge) {y, head[x]};
	head[x] = tot;
}

void dfs(int x, int dep, int last) {
	if (dep > len) len = dep, len_x = x;
	for (int i = head[x]; i; i = e[i].nxt) {
		int y = e[i].v;
		if (y != last) dfs(y, dep + 1, x);
	}
}

int main() {
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	n = read();
	for (int i = 1; i < n; ++i) {
		x = read(); y = read();
		addedge(x, y);
		addedge(y, x);
		len = 0; len_x = x; dfs(x, 0, 0);
		len = 0; dfs(len_x, 0, 0);
		printf("%d\n", len);
	}
	return 0;
}
