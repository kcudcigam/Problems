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

	template <class T> void read(T &x){
		T flg = 1; x = 0; static char ch = getchar();
		for (; !isdigit(ch); ch = getchar()) if (ch == '-') flg = -flg;
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
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

int n, q, opt, X, Y;

int f[6005], a[6005];

inline int getf(int x) {
	return f[x] == x ? x : getf(f[x]);
}

inline void unionf(int x, int y) {
	int rx = getf(x), ry = getf(y);
	f[rx] = ry; return;
}

int main(void) {
	file("merge");
	read(n), read(q);
	for (int i = 1; i <= n; i++) f[i] = i;
	while (q--) {
		read(opt), read(X), read(Y);
		if (opt == 1) unionf(X, Y);
		else {
			for (register int i = 1; i <= n; i++)
				if (getf(i) == getf(X)) a[i] += Y;
		}
	} for (int i = 1; i <= n; i++)
		if (i == n) writeln(a[i]);
		else writeln(a[i], ' ');
	return 0;
}

