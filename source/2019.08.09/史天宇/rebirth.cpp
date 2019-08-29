#include<cstdio>
#include<cctype>
#include<queue>
#include<algorithm>
#include<cstring>
#define MaxN 200010
#define MaxM 1000010
#define INF 0x3f3f3f3f

struct edge {int u, v, w, nxt;} e[MaxM];

int dis[MaxN], ans[MaxN], n, m, x, y, z, Num, tot, head[MaxN];
bool vis[MaxN], del[MaxN];

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

void addedge(int x, int y, int z) {
	e[++tot] = (edge) {x, y, z, head[x]};
	head[x] = tot;
}

void spfa() {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	std::queue<int> q;
	q.push(1);
	dis[1] = 0;
	vis[1] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for (int i = head[x]; i; i = e[i].nxt) {
			if (del[i]) continue;
			int y = e[i].v;
			if (dis[x] + e[i].w < dis[y]) {
				dis[y] = dis[x] + e[i].w;
				if (!vis[y]) {
					q.push(y);
					vis[y] = 1;
				}
			}
		}
	}
}
 
int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	Num = read();
	n = read(); m = read();
	for (int i = 1; i <= m; ++i) {
		x = read(); y = read(); z = read();
		addedge(x, y, z);
		addedge(y, x, z);
	}
	for (int i = 1; i <= tot; i += 2) {
		del[i] = del[i + 1] = 1;
		spfa();
		ans[e[i].u] = std::max(ans[e[i].u], dis[e[i].u]);
		ans[e[i].v] = std::max(ans[e[i].v], dis[e[i].v]);
		del[i] = del[i + 1] = 0;
	}
	printf("0 ");
	for (int i = 2; i < n; ++i) printf("%d ", ans[i] == INF ? -1 : ans[i]);
	printf("%d\n", ans[n] == INF ? -1 : ans[n]);
	return 0;
}
