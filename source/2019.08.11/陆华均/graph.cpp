#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	T f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	w(x);
	putchar(c);
}
const int M = 3e5 + 5;
struct info{
	int to, v, nex;
}l[M << 1], g[M << 1];
priority_queue <pair <int, pair <int, int > > > heap;
int sum, f[M], h[M], he_ad[M], anc[M][20], dfn[M], son[M];
bool vis[M];
inline int grand(int x) {
	if (f[x] == x) return x;
	return f[x] = grand(f[x]);
}
inline void dfsf(int p, int fa) {
	sum ++;
	for (int e = h[p]; e; e = l[e].nex) {
		int u = l[e].to, val = l[e].v;
		if (p < u) heap.push(make_pair(-val, make_pair(p, u)));
		if (!vis[u]) {
			vis[u] = true;
			dfsf(u, p);
		}
	}
}
inline void dfs(int p, int fa) {
	dfn[p] = dfn[fa] + 1;
	anc[p][0] = fa;
	for (int i = 1; i <= 19; i ++) {
		anc[p][i] = anc[anc[p][i - 1]][i - 1];
	}
	for (int e = he_ad[p]; e; e = g[e].nex) {
		int u = g[e].to;
		if (u != fa) {
			son[u] = g[e].v;
			dfs(u, p);
		}
	}
}
inline int lca(int x, int y) {
	if (dfn[x] < dfn[y]) {
		swap(x, y);
	}
	for (int i = 19; i >= 0; i --) {
		if (dfn[anc[x][i]] >= dfn[y]) x = anc[x][i];
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i --) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
int main(){
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	int n, m, q, len = 0;
	read(n); read(m); read(q);
	for (int i = 1; i <= m; i ++) {
		int x, y, z;
		read(x); read(y); read(z);
		l[++ len] = (info) {y, z, h[x]};
		h[x] = len;
		l[++ len] = (info) {x, z, h[y]};
		h[y] = len;
	}
	for (int i = 1; i <= n; i ++) f[i] = i;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			vis[i] = true;
			sum = 0;
			dfsf(1, 0);
			int ti = 0, len = 0;
			while(ti < sum - 1) {
				int u = heap.top().second.first, v = heap.top().second.second, val = -heap.top().first; 
				heap.pop();
				if (grand(u) != grand(v)) {
					f[grand(u)] = grand(v);
					ti ++;
					g[++ len] = (info) {v, val, he_ad[u]};
					he_ad[u] = len;
					g[++ len] = (info) {u, val, he_ad[v]};
					he_ad[v] = len;
				}
			}
			while(!heap.empty()) heap.pop();
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (!dfn[i]) dfs(i, 0);
	}
	for (int i = 1; i <= q; i ++) {
		int x, y, z, ans = -1;
		read(x); read(y);
		if (grand(x) == grand(y)) {
			z = lca(x, y);
			while(x != z) {
				ans = max(ans, son[x]);
				x = anc[x][0];
			} 
			while(y != z) {
				ans = max(ans, son[y]);
				y = anc[y][0];
			}
		}
		write(ans, '\n');
	}
	return 0;
}

