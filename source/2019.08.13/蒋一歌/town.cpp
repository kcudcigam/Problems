#include <bits/stdc++.h>
#define Maxn	300500
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

int n;

struct Tree{

	struct Edge{ int v, next; } edge[Maxn * 2];
	int up[Maxn][19], first[Maxn], dep[Maxn], Top;

	void add(int u, int v){
		edge[++Top] = (Edge) {v, first[u]};
		first[u] = Top;
	}
	void dfs(int u, int fa){
		for (int i = first[u], v; i; i = edge[i].next)
			if ((v = edge[i].v) != fa)
				dep[v] = dep[u] + 1, up[v][0] = u, dfs(v, u);
	}
	void init(){
		dfs(1, 0);
		for (int j = 1; j <= 18; j++)
		for (int i = 1; i <= n; i++)
			up[i][j] = up[up[i][j - 1]][j - 1];
	}
	int lca(int u, int v){
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = 18, c = dep[u] - dep[v]; ~i; i--)
			if (c >= (1 << i)) c -= (1 << i), u = up[u][i];
		if (u == v) return u;
		for (int i = 18; ~i; i--)
			if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
		return up[u][0];
	}
	int dis(int u, int v){ return dep[u] + dep[v] - dep[lca(u, v)] * 2; }
	
} T;

struct Cpt{ int a, b, len; } c[Maxn];
int p[Maxn], A[Maxn], B[Maxn];

int fa(int u){ return u == p[u] ? u : p[u] = fa(p[u]); }
int merge(int u, int v){
	int p1 = fa(u), p2 = fa(v), l1 = c[p1].len, l2 = c[p2].len;
	int d1 = T.dis(c[p1].a, u), d2 = T.dis(c[p1].b, u), d = max(d1, d2), x, y;
	x = d1 > d2 ? c[p1].a : c[p1].b;
	d1 = T.dis(c[p2].a, v), d2 = T.dis(c[p2].b, v), d += max(d1, d2);
	y = d1 > d2 ? c[p2].a : c[p2].b, d++;
	int len = max(d, max(l1, l2));
	if (len == l2) c[p1] = (Cpt) {c[p2].a, c[p2].b, c[p2].len};
	else if (len == d) c[p1] = (Cpt) {x, y, d};
	p[p2] = p1;
	return c[p1].len;
}

int main(){
	freopen("town.in", "r", stdin); freopen("town.out", "w", stdout);
	read(n);
	for (int i = 1; i < n; i++)
		read(A[i]), read(B[i]);
	for (int i = 1, u, v; i < n; i++)
		u = A[i], v = B[i], T.add(u, v), T.add(v, u);
	T.init();
	for (int i = 1; i <= n; i++)
		p[i] = i, c[i] = (Cpt) {i, i, 0};
	for (int i = 1; i < n; i++)
		cout << merge(A[i], B[i]) << '\n';
	return 0;
}
