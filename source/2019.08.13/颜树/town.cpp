#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
using namespace std;
template <typename T> void chkmin(T &x, T y) {x = x < y ? x : y;}
template <typename T> void chkmax(T &x, T y) {x = x > y ? x : y;}
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
const int N = 300010;
int ret, d[N], p[N], tx[N], ty[N], ans[N][2], f[N][21];
vector <int> e[N];
int Find(int x) {return p[x] == x ? x : p[x] = Find(p[x]);}
void dfs(int x, int fa) {
	d[x] = d[fa] + 1;
	for (int i = 1; i <= 20; i++)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for (int y : e[x]) {
		if (y == fa) continue;
		f[y][0] = x, dfs(y, x);
	}
}
int lca(int x, int y) {
	if (!x || !y) return 0;
	if (d[x] < d[y]) swap(x, y); int tx = x, ty = y;
	for (int i = d[x] - d[y], j = 0; i; i >>= 1, j++)
		if (i & 1) x = f[x][j];
	if (x == y) return d[tx] + d[ty] - 2 * d[x];
	for (int i = 20; ~i; i--)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	int z = f[x][0]; return d[tx] + d[ty] - 2 * d[z];
}
void Merge(int x, int y) {
	int len = 0, tx = 0, ty = 0;
	int t = lca(ans[x][0], ans[x][1]);
	if (len < t) len = t, tx = ans[x][0], ty = ans[x][1];
	t = lca(ans[y][0], ans[y][1]);
	if (len < t) len = t, tx = ans[y][0], ty = ans[y][1];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			int tl = lca(ans[x][i], ans[y][j]);
			if (len < tl) tx = ans[x][i], ty = ans[y][j], len = tl;
		}
	p[x] = y, ans[y][0] = tx, ans[y][1] = ty, cout << len << '\n';
}
int main() {
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	int n; read(n);
	for (int i = 1; i < n; i++) {
		read(tx[i]), read(ty[i]);
		e[tx[i]].pb(ty[i]), e[ty[i]].pb(tx[i]);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) p[i] = i, ans[i][0] = i, ans[i][1] = 0;
	for (int i = 1; i < n; i++) {
		int x = tx[i], y = ty[i];
		if (d[x] > d[y]) swap(x, y);
		int fx = Find(x), fy = Find(y);
		Merge(fx, fy);
	}
	return 0;
}
