#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

inline int read() {
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 1e3 + 10, M = 1e4;
int num, n, m, tim, inn[N], ot[N], h[N], fa[N], tot = 1;
struct edge{int len, nxt, v;} e[M << 1];
ll dis[N], ans[N], nmd[N];
bool del[M << 1];
vector<int>v[N];
struct node{
	int x; ll dis;
	inline bool operator < (const node r) const 
		{return dis > r.dis;} 
};

inline void add(int x, int y, int len) {
	e[++tot] = (edge) {len, h[x],y};
	h[x] = tot;
}

priority_queue<node>q;
inline void dij() {
	memset(dis, 100, sizeof dis);
	dis[1] = 0;
	node x, o;
	x.x = 1, x.dis = 0;
	q.push(x);
	while (!q.empty()) {
		x = q.top(); q.pop();
		if (x.dis ^ dis[x.x]) continue;
		for (int i = h[x.x]; i; i = e[i].nxt) {
			o.x = e[i].v, o.dis = e[i].len + x.dis;
			if (dis[o.x] <= o.dis) continue;
			dis[o.x] = o.dis, q.push(o), fa[o.x] = x.x;
		}
	}
}

inline void ddij() {
	memset(nmd, 100, sizeof nmd);
	nmd[1] = 0;
	node x, o;
	x.x = 1, x.dis = 0;
	q.push(x);
	while (!q.empty()) {
		x = q.top(); q.pop();
		if (x.dis ^ nmd[x.x]) continue;
		for (int i = h[x.x]; i; i = e[i].nxt) {
			if (del[i]) continue;
			o.x = e[i].v, o.dis = e[i].len + x.dis;
			if (nmd[o.x] <= o.dis) continue;
			nmd[o.x] = o.dis, q.push(o);
		}
	}
}

void dfs(int x) {
	inn[x] = ++tim;
	for (int i = 0; i < v[x].size(); ++i) dfs(v[x][i]);
	ot[x] = ++tim;
}

void dfs2(int x) {
	if (x == 1) ans[x] = 0;
	else ans[x] = dis[n + 1];
	bool f = 0;
	for (int i = 0; i < v[x].size(); ++i) dfs2(v[x][i]);
	for (int i = h[x]; i; i = e[i].nxt) {
		if (e[i].v == fa[x]) {
			if (f || e[i].len + dis[x] != dis[fa[x]]) ans[x] = min(ans[x], dis[fa[x]] + e[i].len);
			else f = 1;
		}
		if (fa[e[i].v] == x) ans[x] = min(ans[x], nmd[e[i].v] + e[i].len);
		else ans[x] = min(ans[x], dis[e[i].v] + e[i].len);
	}
	if (ans[x] == dis[n + 1]) ans[x] = -1;
}

int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	num = read(), n = read(), m = read();
	int x, y, len;
	fox (i, 1, m) {
		x = read(), y = read(), len = read();
		if (x ^ y) add(x, y, len), add(y, x, len);
	}
	
	dij();
	
	if (num <= 7) {
		printf("0 ");
		fox (i, 2, n) {
			for (int j = h[i]; j; j = e[j].nxt) 
				if (fa[i] == e[j].v && dis[fa[i]] + e[j].len == dis[i]) {
					del[j] = del[j ^ 1] = 1;
					ddij();
					del[j] = del[j ^ 1] = 0;
				}
			if (!fa[i] || nmd[i] == dis[n + 1]) printf("-1");
			else printf("%lld", nmd[i]);
			putchar(i == n ? '\n' : ' ');
		}
	} else {
		fox (i, 2, n) v[fa[i]].push_back(i);
		dfs(1);
	
		fox (i, 2, n) {
			nmd[i] = dis[n + 1];
			for (int j = h[x]; j; j = e[j].nxt) {
				if (inn[fa[x]] <= inn[e[j].v] && ot[e[j].v] <= ot[fa[x]]) continue;
				nmd[i] = min(nmd[i], e[j].len + dis[e[j].v]);
			}
		}
	
		dfs2(1);
	
		fox (i, 1, n) printf("%lld%c", ans[i], (i == n ? '\n' : ' '));
	}
	return 0;
}
