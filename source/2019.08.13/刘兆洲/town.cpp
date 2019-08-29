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

enum {
	Maxn = 300005,
	Maxm = 600005
};

int n, cnt = 0, head[Maxn], dep[Maxn], d1[Maxn], d2[Maxn];
int ver[Maxm], nxt[Maxm], s[Maxn], t[Maxn], f[Maxn][26], T;

inline void AddEdge(int u, int v) {
	ver[++cnt] = v, nxt[cnt] = head[u],
	head[u] = cnt, ver[++cnt] = u,
	nxt[cnt] = head[v], head[v] = cnt;
}

inline void bfs(void) {
	queue <int> q;
	q.push(1); dep[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = nxt[i]) {
			if (dep[ver[i]]) continue;
			dep[ver[i]] = dep[u] + 1;
			f[ver[i]][0] = u;
			for (int j = 1; j <= T; j++)
				f[ver[i]][j] = f[f[ver[i]][j - 1]][j - 1];
			q.push(ver[i]);
		}
	}
}

inline int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = T; i >= 0; i--)
		if (dep[f[y][i]] >= dep[x]) y = f[y][i];
	if (x == y) return x;
	for (int i = T; i >= 0; i--)
		if (f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

int F[Maxn];
inline int getf(int x) {
	return F[x] == x ? x : F[x] = getf(F[x]);
}

inline int unionf(int x, int y) {
	int rx = getf(x), ry = getf(y);
	F[rx] = ry;
}

int main(void) {
	file("town");
//	merge(u, v) == max(dep[u] - dep[rt[u]] - dep[v] + dma[v] + 1, max(tmax[rt[u]], tmax[rt[v]]))
	read(n); Ms(dep, 0); T = (int) (log(n) / log(2)) + 1;
	for (int i = 1; i < n; i++) {
		read(s[i]), read(t[i]);
		AddEdge(s[i], t[i]);
	} bfs();
	
	for (int i = 1; i <= n; i++) F[i] = d1[i] = d2[i] = i;
	
	for (int i = 1; i < n; i++) {
		int u = s[i], v = t[i], ret = 0, tmp, tnp;
		int fu = getf(u), fv = getf(v);
		if (dep[d1[fu]] + dep[d1[fv]] - 2 * dep[lca(d1[fu], d1[fv])] > ret) {
			ret = dep[d1[fu]] + dep[d1[fv]] - 2 * dep[lca(d1[fu], d1[fv])],
			tmp = d1[fu], tnp = d1[fv];
		}
	
		if (dep[d1[fu]] + dep[d2[fv]] - 2 * dep[lca(d1[fu], d2[fv])] > ret) {
			ret = dep[d1[fu]] + dep[d2[fv]] - 2 * dep[lca(d1[fu], d2[fv])],
			tmp = d1[fu], tnp = d2[fv];
		}
		
		if (dep[d1[fu]] + dep[d2[fu]] - 2 * dep[lca(d1[fu], d2[fu])] > ret) {
			ret = dep[d1[fu]] + dep[d2[fu]] - 2 * dep[lca(d1[fu], d2[fu])],
			tmp = d1[fu], tnp = d2[fu];
		}
		
		if (dep[d2[fu]] + dep[d2[fv]] - 2 * dep[lca(d2[fu], d2[fv])] > ret) {
			ret = dep[d2[fu]] + dep[d2[fv]] - 2 * dep[lca(d2[fu], d2[fv])],
			tmp = d2[fu], tnp = d2[fv];
		}
		
		if (dep[d2[fu]] + dep[d1[fv]] - 2 * dep[lca(d2[fu], d1[fv])] > ret) {
			ret = dep[d2[fu]] + dep[d1[fv]] - 2 * dep[lca(d2[fu], d1[fv])],
			tmp = d2[fu], tnp = d1[fv];
		}
		
		if (dep[d1[fv]] + dep[d2[fv]] - 2 * dep[lca(d1[fv], d2[fv])] > ret) {
			ret = dep[d1[fv]] + dep[d2[fv]] - 2 * dep[lca(d1[fv], d2[fv])],
			tmp = d1[fv], tnp = d2[fv];
		}
		
		if (dep[fv] < dep[fu]) unionf(fu, fv), d1[fv] = tmp, d2[fv] = tnp;
		else unionf(fv, fu), d1[fu] = tmp, d2[fu] = tnp;
		
		writeln(ret);
	}
	
//	fwrite(pf, 1, o1 - pf, stdout);
	return 0;
}

/*
5
3 5
3 4
1 2
1 3
*/

