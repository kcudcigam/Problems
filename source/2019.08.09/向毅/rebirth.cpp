#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll ll_inf = 0x7f7f7f7f7f7f7f7f;
struct node {
	int to, nxt;
	ll val;
} edge[1000010];
struct info {
	int v;
	ll val;
	bool operator <(const info x) const { return val > x.val; }
} tmp;
int num, n, m, head[500010], tot, del;
ll ans, dis[500010];
bool vis[500010];
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
inline ll RD() {
	ll x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
void add(int from, int to, ll val) {
	edge[++tot].nxt = head[from];
	edge[tot].to = to;
	edge[tot].val = val;
	head[from] = tot;
}
void dij(int s, int e) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	priority_queue <info> q;
	dis[s] = 0;
	tmp.v = s;
	tmp.val = 0;
	q.push(tmp);
	while (!q.empty()) {
		int u = q.top().v;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = edge[i].nxt) {
			if (i == del) continue;
			int v = edge[i].to;
			ll val = edge[i].val;
			if (dis[u] + val < dis[v]) {
				dis[v] = dis[u] + val;
				tmp.v = v;
				tmp.val = dis[v];
				q.push(tmp);
			}
		}
	}
}
int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	num = rd(); n = rd(); m = rd();
	for (int i = 1; i <= m; i++) {
		int x = rd(), y = rd();
		ll z = RD();
		add(x, y, z);
		add(y, x, z);
	}
	printf("0");
	for (int i = 2; i <= n; i++) {
		ans = 0;
		for (int j = head[i]; j; j = edge[j].nxt) {
			del = j;
			dij(i, 1);
			if (dis[1] == ll_inf) {
				ans = -1;
				break;
			} else if (dis[1] > ans) {
				ans = dis[1];
			}
		}
		printf(" %lld", ans);
	}
	printf("\n");
	return 0;
}

