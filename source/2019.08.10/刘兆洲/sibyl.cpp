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
	Maxn = 300005
};

int n, m, q, cnt = 0, head[Maxn];
int ver[Maxn], nxt[Maxn];

inline void AddEdge(int u, int v) {
	ver[++cnt] = v, nxt[cnt] = head[u];
	head[u] = cnt, ver[++cnt] = u;
	nxt[cnt] = head[v], head[v] = cnt;
}

int tag[Maxn], val[Maxn], ret; bool vis[Maxn];

inline void query(int u) {
	ret = tag[u];
	for (register int i = head[u]; i; i = nxt[i])
		if (!vis[ver[i]]) ret += tag[ver[i]], vis[ver[i]] = true;
	for (register int i = head[u]; i; i = nxt[i]) vis[ver[i]] = false;
}

int type, x, y;

signed main(void) {
	file("sibyl");
	read(n), read(m), read(q); Ms(tag, 0);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		if (u == v) continue; AddEdge(u, v);
	}
		
	while (q--) {
		read(type), read(x);
		if (type == 0) {
			query(x); writeln(ret);
		} else {
			read(y); tag[x] += y;
		}
	}
//	fwrite(pf, 1, o1 - pf, stdout);
	return 0;
}

/*
5 5 9
1 2
1 3
1 4
2 3
3 4
1 1 1
1 4 2
0 2
1 3 3
0 4
1 2 3
0 3
0 1
0 5
*/

