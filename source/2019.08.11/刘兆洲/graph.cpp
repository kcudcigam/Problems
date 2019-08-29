//Program written by Liu Zhaozhou ~~~
#include <bits/stdc++.h>

#define lowbit(x) x & -x
#pragma GCC optimize("Ofast,inline")

using namespace std;

namespace Base {
	inline char gc(void)
	{
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}

	#define gc() getchar()

	template <class T> inline void read(T &x)
	{
		T flag = (T) 1; x = 0; static char ch = gc();
		for (; ch > '9' || ch < '0'; ch = gc())
			flag = ch == '-' ? -1 : 1;
		for (; ch >= '0' && ch <= '9'; ch = gc())
			x = (x << 1) + (x << 3) + (ch & 15);
		x *= flag; return;
	}

	inline void readstr(string&x) {
		x = ""; static char ch;
		while (isspace(ch = gc()));
		while (x += ch, !isspace(ch = gc()));
	}

	inline void readstr(char *s) {
		do *s = gc(); while ((*s == ' ') || (*s == '\n') || (*s == '\r'));
		do *(++s) = gc(); while ((~*s) && (*s != ' ') && (*s != '\n') && (*s != '\r'));
		*s = 0; return;
	}

	inline void printstr(string x, int num = 0, char ch = '\n') {
		for (int i = num; i < x.size(); ++i)
			putchar(x[i]); putchar(ch);
	}

	inline void readch(char&x) {while (isspace(x = gc()));}

	char pf[100000], *o1 = pf, *o2 = pf + 100000;
	#define ot(x) (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf) ++= x : *o1 ++= x)
	template <class T>
	inline void println(T x, char c = '\n') {
		if (x < 0) ot(45), x = -x;
		static char s[15], *b; b = s;
		if (!x) *b ++= 48;
		for (; x; * b ++= x % 10 + 48, x /= 10);
		for (; b-- != s; ot(*b)); ot(c);
	}

	template <class T> inline void write(T x)
	{
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0'); return;
	}

	template <class T> inline void writeln(T x) {write(x); puts("");}
	template <class T> inline void writeln(T x, char c) {write(x); putchar(c);}
	template <class T> inline void writeln(char c, T x) {putchar(c); write(x);}

	template <class T> inline void chkmax(T &x, const T y) {x > y ? x = x : x = y;}
	template <class T> inline void chkmin(T &x, const T y) {x < y ? x = x : x = y;}
	template <class T> inline T max(const T&x, const T&y, const T&z) {
		return x > y ? (x > z ? x : z) : (y > z ? y : z);
	}

	typedef long long ll;
	typedef unsigned long long ull;
	typedef long double ld;

	#define Ms(arr, opt) memset(arr, opt, sizeof(arr))
	#define Mp(x, y) make_pair(x, y)

	inline void file(string str) {
		freopen((str + ".in").c_str(), "r", stdin);
		freopen((str + ".out").c_str(), "w", stdout);
	}
}

using namespace Base;

int n, m, q, cnt = 0, dis[1005][1005];
namespace Floyd {
	inline void dp(void) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = 1 << 30;
		for (int i = 1; i <= n; i++) dis[i][i] = 0;
		
		for (int i = 1, u, v, w; i <= m; i++) {
			read(u), read(v), read(w);
			chkmin(dis[u][v], w), dis[v][u] = dis[u][v];
		}
		
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					chkmin(dis[i][j], max(dis[i][k], dis[k][j]));
		
		while (q--) {
			int x, y;
			read(x), read(y);
			writeln(dis[x][y] == (1 << 30) ? -1 : dis[x][y]);
		}
	}
}

enum {
	Maxn = 300005,
	Maxm = 600005
};

int head[Maxn], ver[Maxm], nxt[Maxm], edge[Maxm];
inline void AddEdge(int u, int v, int w) {
	ver[++cnt] = v, edge[cnt] = w;
	nxt[cnt] = head[u], head[u] = cnt;
	ver[++cnt] = u, edge[cnt] = w;
	nxt[cnt] = head[v], head[v] = cnt;
}

struct Edge {
	int u, v, w;
	Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
	inline bool operator < (const Edge&rhs) const { return w < rhs.w; }
} line[Maxm];

int f[Maxm];
inline int getf(int x) {
	return f[x] == x ? x : f[x] = getf(f[x]);
}

inline void unionf(int x, int y) {
	int rx = getf(x), ry = getf(y);
	f[rx] = ry; return;
}

int top[Maxn], dep[Maxn], fat[Maxn], tot = 0, _timer = 0;
int dfn[Maxn], sze[Maxn], son[Maxn], bel[Maxn], val[Maxn];

inline void DfsFir(int u, int T) {
	bel[u] = T; sze[u] = 1;
	for (int i = head[u]; i; i = nxt[i]) {
		if (ver[i] == fat[u]) continue;
		fat[ver[i]] = u; dep[ver[i]] = dep[u] + 1;
		val[ver[i]] = edge[i];
		DfsFir(ver[i], T); sze[u] += sze[ver[i]];
		if (sze[son[u]] < sze[ver[i]]) son[u] = ver[i];
	}
}

inline void DfsSec(int u, int tp) {
	dfn[u] = ++_timer; top[u] = tp;
	if (son[u]) DfsSec(son[u], tp);
	for (int i = head[u]; i; i = nxt[i]) {
		if (ver[i] == fat[u] || ver[i] == son[u]) continue;
		DfsSec(ver[i], ver[i]);
	}
}

struct SegmentTree {
	int tmax[Maxn << 2 | 1];
	inline void build(int pos, int l, int r) {
		tmax[pos] = 0;
		if (l == r) { tmax[pos] = val[dfn[l]]; return; }
		int mid = l + r >> 1;
		build(pos << 1, l, mid), build(pos << 1 | 1, mid + 1, r);
		tmax[pos] = max(tmax[pos << 1], tmax[pos << 1 | 1]); 
	}
	
	inline int query(int pos, int l, int r, int L, int R) {
		if (L <= l && R >= r) return tmax[pos];
		int mid = l + r >> 1, ret = 0;
		if (L <= mid) chkmax(ret, query(pos << 1, l, mid, L, R));
		if (R > mid) chkmax(ret, query(pos << 1 | 1, mid + 1, r, L, R));
		return ret;
	}
} sgt;

inline int query(int x, int y) {
	int ret = 0;
	while (top[x] ^ top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		chkmax(ret, sgt.query(1, 1, n, dfn[top[x]], dfn[x]));
		x = fat[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	chkmax(ret, sgt.query(1, 1, n, dfn[x], dfn[y]));
	return ret;
}

int main(void) {
	file("graph");
	read(n); read(m); read(q);
	if (n <= 1000 && m <= 1000) { Floyd :: dp(); return 0; }
	for (int i = 1, u, v, w; i <= m; i++)
		read(u), read(v), read(w), line[i] = Edge(u, v, w);
	sort(line + 1, line + m + 1);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		if (getf(line[i].u) == getf(line[i].v)) continue;
		AddEdge(line[i].u, line[i].v, line[i].w), unionf(line[i].u, line[i].v);
	}// DfsFir(1, 1); DfsSec(1, 1); return 0;
	for (int i = 1; i <= n; i++)
		if (!bel[i]) DfsFir(i, ++tot), DfsSec(i, i);
	sgt.build(1, 1, n);
	while (q--) {
		int x, y; read(x), read(y);
		if (bel[x] ^ bel[y]) puts("-1");
		else writeln(query(x, y));
	}
//	fwrite(pf, 1, o1 - pf, stdout);
	return 0;
}

/*
*/

