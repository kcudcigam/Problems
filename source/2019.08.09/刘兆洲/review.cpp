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

ll y, lim = 1, n = 1, m = 0;
bool vis[70][70];
bool isbit[70]; int cnt = 0;

inline void splitnum(ll x) {
	while (x) {
		isbit[cnt++] = x & 1;
		x >>= 1;
	} cnt--; return;
}

int main(void) {
	file("review");
	for (read(y); lim << 1 < y; lim <<= 1, ++n);
	n += 2;
	writeln(n, ' '); splitnum(y);
	for (int i = 1; i <= cnt + 2; i++)
		for (int j = i + 1; j <= cnt + 2; j++)
			vis[i][j] = 1, ++m;
	for (int i = 0; i <= cnt; i++)
		if (isbit[i]) vis[i + 2][n] = 1, ++m;
	writeln(m);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (vis[i][j]) {
				writeln(i, ' '), writeln(j);
			}
	return 0;
}


