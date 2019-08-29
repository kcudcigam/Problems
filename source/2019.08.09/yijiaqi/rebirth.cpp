#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> P;
const int N = 500010;
int NUM, n, m, inf;
struct e {
	int v, w, p;
};
vector<e> E[N];
priority_queue<P, vector<P>, greater<P> > q;
int X[N], Y[N], ans[N], dis[N];

template <typename T> void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { a = a * 10 + c - '0'; c = getchar(); }
	a *= f;
}

void dij(int x) {
	memset(dis, 0x3f, sizeof(dis));
	inf = dis[0];
	dis[1] = 0;
	q.push(P(0, 1));
	while (!q.empty()) {
		int u = q.top().second, d = q.top().first; q.pop();
		if (d > dis[u]) continue;
		for (int i=0;i<E[u].size();++i) {
			int v = E[u][i].v, w = E[u][i].w;
			if (E[u][i].p == x) continue;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push(P(dis[v], v));
			}
		}
	}
}

void solve_bf() {
	for (int i=1;i<=m;++i) {
		dij(i);
		ans[X[i]] = max(dis[X[i]], ans[X[i]]), ans[Y[i]] = max(dis[Y[i]], ans[Y[i]]);
	}
	for (int i=1;i<=n;++i)
		if (ans[i] >= inf) cout << -1 << ' ';
		else cout << ans[i] << ' ';
}

void solve1() {
	dij(0);
	for (int i=1;i<=n;++i) {
		int ans = -1;
		for (int j=0;j<E[i].size();++j) {
			int v = E[i][j].v, w = E[i][j].w;
			if (v < i && v != i - 1) ans = max(ans, dis[v] + w);
		}
		cout << ans << ' ';
	}
}

signed main() {
	freopen("rebirth.in", "r", stdin); freopen("rebirth.out", "w", stdout);
	read(NUM); read(n); read(m);
	for (int i=1;i<=m;++i) {
		int x, y, len; read(x); read(y); read(len);
		X[i] = x, Y[i] = y;
		E[x].push_back((e){y, len, i});
		E[y].push_back((e){x, len, i});
	}
	solve_bf();
	return 0;
}
