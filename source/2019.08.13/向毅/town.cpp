#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000;
struct node {
	int to, nxt;
} edge[(maxn << 1) + 10];
int n, head[maxn + 10], tot, dis[maxn + 10], fa[maxn + 10];
int find(int x) { return fa[x] == x? x: fa[x] = find(fa[x]); }
void dfs(int u, int last) {
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v == last) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}
void add(int from, int to) {
	edge[++tot].nxt = head[from];
	edge[tot].to = to;
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
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	n = rd();
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i < n; i++) {
		int x = rd(), y = rd();
		add(x, y);
		add(y, x);
		fa[find(y)] = find(x);
		dis[x] = 0;
		dfs(x, 0);
		int maxx = 0, maxi;
		for (int i = 1; i <= n; i++) if (find(x) == find(i) && dis[i] > maxx) maxx = dis[i], maxi = i;
		dis[maxi] = 0;
		dfs(maxi, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++) if (find(x) == find(i)) ans = max(ans, dis[i]);
		printf("%d\n", ans);
	}
	return 0;
}


