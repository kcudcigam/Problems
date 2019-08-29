//Program by Liu Zhaozhou
#include <bits/stdc++.h>

#define lowbit(x) x & -x

using namespace std;

namespace Base {
	inline char gc(void) {
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}

	#define gc() getchar()

	template <class T> void read(T &x) {
		T flg = 1; x = 0; static char ch = gc();
		for (; !isdigit(ch); ch = gc()) if (ch == '-') flg = -flg;
		for (; isdigit(ch); ch = gc()) x = (x << 1) + (x << 3) + ch - '0';
		x *= flg; return;
	}

	template <class T> inline void write(T x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) write(x / 10);
		putchar(x % 10 + 48);
	}

	template <class T> inline void writeln(T x, char c = '\n') { write(x), putchar(c); }

	template <class T> inline void chkmax(T&x, const T y) { x = x > y ? x : y; }
	template <class T> inline void chkmin(T&x, const T y) { x = x < y ? x : y; }
	template <class T> inline T max(const T x, const T y, const T z) { return max(x, max(y, z)); }

	inline void file(string str) {
		freopen((str + ".in").c_str(), "r", stdin);
		freopen((str + ".out").c_str(), "w", stdout);
	}

	#define Ms(arr, opt) memset(arr, opt, sizeof(arr))
	#define Mp(x, y) make_pair(x, y)

	typedef long long ll;
	typedef unsigned long long ull;
	typedef long double lb;
}

using namespace Base;

enum {
	Maxn = 200005,
	Maxm = 500005
};

struct State {
	int dis, dir;
	State(int _dis = 0, int _dir = 0) : dis(_dis), dir(_dir) {}
	inline bool operator < (const State&rhs) const { return dis > rhs.dis; }
};

int num, n, m, dis[Maxn], ans[Maxn];
int imp[Maxn]; bool vis[Maxn];

struct Edge {
	int ver[Maxm], edge[Maxm], nxt[Maxm], head[Maxn], cnt;
	Edge(void) { Ms(head, 0), cnt = 0; }
	inline void AddEdge(int u, int v, int w) {
		ver[++cnt] = v, edge[cnt] = w;
		nxt[cnt] = head[u], head[u] = cnt;
		ver[++cnt] = u, edge[cnt] = w;
		nxt[cnt] = head[v], head[v] = cnt;
	}
} G1, G2;

inline void Setup(void) {
	for (int i = 2; i <= n; i++) dis[i] = 1 << 30, ans[i] = dis[i];
	ans[1] = dis[1] = 0; Ms(vis, false); return;
}

inline void DijFir(void) {
	priority_queue <State> Q;
	Q.push(State(0, 1)); Setup();
	while (!Q.empty()) {
		int u = Q.top().dir; Q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = G1.head[u]; i; i = G1.nxt[i]) {
			int v = G1.ver[i], w = G1.edge[i];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				imp[v] = i; Q.push(State(dis[v], v));
			}
		}
	}
}

inline void DijSec(void) {
	priority_queue <State> Q;
	Q.push(State(0, 1)); Setup();
	while (!Q.empty()) {
		int u = Q.top().dir; Q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = G1.head[u]; i; i = G1.nxt[i]) {
			int v = G1.ver[i], w = G1.edge[i];
			if (i != imp[v] && ans[v] > dis[u] + w)
				ans[v] = dis[u] + w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				Q.push(State(dis[v], v));
			}
		}
	}
}

inline int DijThi(int to) {
	priority_queue <State> Q;
	Q.push(State(0, 1)); Setup();
	while (!Q.empty()) {
		int u = Q.top().dir; Q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = G1.head[u]; i; i = G1.nxt[i]) {
			int v = G1.ver[i], w = G1.edge[i];
			if (i == imp[to]) continue;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				Q.push(State(dis[v], v));
			}
		}
	} return dis[to] == (1 << 30) ? -1 : dis[to];
}

int main(void) {
	file("rebirth");
	read(num), read(n), read(m);
	for (int i = 1, u, v, w; i <= m; i++) {
		read(u), read(v), read(w);
		if (u == v) continue;
		G1.AddEdge(u, v, w);
	} DijFir();
	
	if (n <= 1000) {
		for (int i = 1; i <= n; i++)
			if (i == n) writeln(DijThi(i));
			else writeln(DijThi(i), ' ');
		return 0;
	}
	DijSec();
	for (int i = 1; i <= n; i++) {
		if (ans[i] == (1 << 30)) ans[i] = -1;
		if (i == n) writeln(ans[i]);
		else writeln(ans[i], ' ');
	}
	
	return 0;
}

/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/

