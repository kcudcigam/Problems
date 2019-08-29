#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 5e5 + 5;
const int MAXLOG = 20;
const long long INF = 1e18;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
__gnu_pbds :: priority_queue <ll, greater <ll>> Heap[MAXN], Del[MAXN];
int n, m, home[MAXN], x[MAXM], y[MAXM], w[MAXM];
int sum[MAXN], father[MAXN][MAXLOG];
ll dist[MAXN], depth[MAXN], f[MAXN];
bool vis[MAXN], done[MAXN];
vector <pair <int, int>> a[MAXN];
vector <int> b[MAXN];
int lca(int x, int y) {
	if (sum[x] < sum[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (sum[father[x][i]] >= sum[y]) x = father[x][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
		}
	return father[x][0];
}
void dfs(int pos, int fa) {
	sum[pos] = sum[fa] + 1;
	depth[pos] = dist[pos];
	father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (auto x : b[pos])
		dfs(x, pos);
}
void calcf(int pos, int fa) {
	for (auto x : b[pos]) {
		calcf(x, pos);
		Heap[pos].join(Heap[x]);
		Del[pos].join(Del[x]);
	}
	while (!Heap[pos].empty() && !Del[pos].empty() && Heap[pos].top() == Del[pos].top()) {
		Heap[pos].pop();
		Del[pos].pop();
	}
	if (!Heap[pos].empty()) f[pos] = Heap[pos].top() - depth[pos];
	else f[pos] = INF;
	if (fa == 0) f[pos] = 0;
}
void shortestPath(int s) {
	static priority_queue <pair <ll, int>> q;
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0, q.emplace(0, s);
	while (!q.empty()) {
		pair <ll, int> tmp = q.top(); q.pop();
		if (vis[tmp.second]) continue;
		vis[tmp.second] = true;
		for (auto x : a[tmp.second])
			if (-tmp.first + x.second < dist[x.first]) {
				dist[x.first] = -tmp.first + x.second;
				home[x.first] = tmp.second;
				q.emplace(-dist[x.first], x.first);
			}
	}
}
int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	int num; read(num), read(n), read(m); 
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]), read(w[i]);
		a[x[i]].emplace_back(y[i], w[i]);
		a[y[i]].emplace_back(x[i], w[i]);
	}
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	shortestPath(1);
	for (int i = 1; i <= n; i++)
		if (home[i]) b[home[i]].push_back(i);
	dfs(1, 0);
	for (int i = 1; i <= m; i++)
		if (father[x[i]][0] == y[i] && !done[x[i]] && dist[x[i]] == dist[y[i]] + w[i]) {
			done[x[i]] = true;
		} else if (father[y[i]][0] == x[i] && !done[y[i]] && dist[y[i]] == dist[x[i]] + w[i]) {
			done[y[i]] = true;
		} else {
			int tmp = lca(x[i], y[i]);
			Heap[x[i]].push(depth[x[i]] + depth[y[i]] + w[i]);
			Heap[y[i]].push(depth[x[i]] + depth[y[i]] + w[i]);
			Del[tmp].push(depth[x[i]] + depth[y[i]] + w[i]);
			Del[tmp].push(depth[x[i]] + depth[y[i]] + w[i]);
		}
	calcf(1, 0);
	for (int i = 1; i <= n; i++)
		if (f[i] == INF) printf("%d ", -1);
		else printf("%lld ", f[i]);
	printf("\n");
	return 0;
}
