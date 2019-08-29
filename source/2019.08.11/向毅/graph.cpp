#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
const int int_inf = 0x7f7f7f7f;
struct node {
	int to, nxt, val;
} edge[maxn << 1];
int n, m, q, head[maxn], tot, ans;
bool vis[maxn];
void dfs(int u, int e, int maxx) {
	if (u == e) {
		if (maxx < ans) ans = maxx;
		return;
	}
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (!vis[v]) {
			vis[v] = 1;
			dfs(v, e, max(maxx, edge[i].val));
			vis[v] = 0;
		}
	}
}
void add(int from, int to, int val) {
	edge[++tot].nxt = head[from];
	edge[tot].to = to;
	edge[tot].val = val;
	head[from] = tot;
}
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	n = rd(); m = rd(); q = rd();
	for (int i = 1; i <= m; i++) {
		int x = rd(), y = rd(), z = rd();
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 1; i <= q; i++) {
		int x = rd(), y = rd();
		ans = int_inf;
		memset(vis, 0, sizeof(vis));
		vis[x] = 1;
		dfs(x, y, 0);
		if (ans == int_inf) {
			printf("-1\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}

