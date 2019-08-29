#include <bits/stdc++.h>
#define ll long long
#define PI pair <ll, int>
#define mp make_pair
using namespace std;
template <typename T> void chkmin(T &x, T y) {x = x < y ? x : y;}
template <typename T> void chkmax(T &x, T y) {x = x > y ? x : y;}
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
const int N = 4010; const ll inf = 1ll << 60;
int n, m, l, cnt, tim, tot, st[N], ban[N], dfn[N], col[N], low[N], pre[N], head[N], used[N]; ll ans[N], dis[N];
struct Edge {int next, num, v;} e[N * 10];
void add(int x, int y, int v) {e[++cnt] = (Edge) {head[x], y, v}, head[x] = cnt;}
void dijkstra(int s) {
	for (int i = 1; i <= n; i++) dis[i] = inf, used[i] = 0;
	priority_queue <PI, vector <PI>, greater <PI> > h;
	h.push(mp(0, s)), dis[s] = 0;
	while (!h.empty()) {
		PI tmp = h.top(); h.pop();
		int x = tmp.second; if (used[x]) continue;
		used[x] = 1;
		for (int p = head[x]; p; p = e[p].next) {
			int k = e[p].num, v = e[p].v;
			if (dis[k] > dis[x] + v && !ban[p]) dis[k] = dis[x] + v, pre[k] = p, h.push(mp(dis[k], k));
		}
	}
}
int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	int num; read(num), read(n), read(m), cnt = 1;
	for (int i = 1; i <= m; i++) {
		int x, y, v; read(x), read(y), read(v);
		add(x, y, v), add(y, x, v);
	}
	for (int i = 1; i <= n; i++) {
		ll ans = -inf;
		for (int p = head[i]; p; p = e[p].next) {
			ban[p] = ban[p ^ 1] = 1;
			dijkstra(1), chkmax(ans, dis[i]);
			ban[p] = ban[p ^ 1] = 0;
		}
		cout << (ans == inf ? -1 : ans) << (i == n ? '\n' : ' ');
 	}
	return 0;
}
