#include <bits/stdc++.h>
using namespace std;

const int N = 600010;
int n, lg;
int f[N][24], Father[N], fa[N], d[N];
struct e {
	int x, y;
} Edge[N];
vector<int> E[N];
e a[N];
int t[10];

template <typename T> void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { a = a * 10 + c - '0'; c = getchar(); }
	a *= f;
}

void dfs(int u) {
	for (int i=0;i<E[u].size();++i) {
		int v = E[u][i];
		if (Father[u] == v) continue;
		Father[v] = f[v][0] = u;
		d[v] = d[u] + 1;
		dfs(v);
	}
}

int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i=lg;i>=0;--i)
		if (d[f[u][i]] >= d[v]) u = f[u][i];
	if (u == v) return u;
	for (int i=lg;i>=0;--i)
		if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

int dis(int x, int y) {
	return d[x] + d[y] - 2 * d[lca(x, y)];
}

void Init() {
	f[1][0] = 1;
	for (int i=1;i<=lg;++i)
		for (int j=1;j<=n;++j) f[j][i] = f[f[j][i - 1]][i - 1];
}

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

e Doit(int P, int Q) {
	int xx, yy, Max = 0;
	t[1] = a[P].x, t[2] = a[P].y;
	t[3] = a[Q].x, t[4] = a[Q].y;
	for (int i=1;i<5;++i)
		for (int j=1;j<i;++j) {
			int D = dis(t[i], t[j]);
			if (D > Max) Max = D, xx = t[i], yy = t[j];
		}
	return (e){xx, yy};
}

int main() {
	freopen("town.in", "r", stdin); freopen("town.out", "w", stdout);
	read(n);
	while ((1 << lg) < n) ++lg;
	for (int i=1;i<n;++i) {
		int x, y; read(x); read(y);
		Edge[i].x = x, Edge[i].y = y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1);
	Init();
	for (int i=1;i<=n;++i) fa[i] = i, a[i] = (e){i, i};
	for (int i=1;i<n;++i) {
		int x = Edge[i].x, y = Edge[i].y;
		int fx = find(x), fy = find(y);
		e tmp = Doit(fx, fy);
		cout << dis(tmp.x, tmp.y) << '\n';
		fa[fx] = fy;
		a[fy] = tmp;
	}
	return 0;
}
