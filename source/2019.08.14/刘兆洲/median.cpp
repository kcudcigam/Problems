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

//	#define gc() getchar()

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

	inline void readch(char&x) { while (isspace(x = gc())); }

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

	template <class T> inline void writeln(T x) { write(x); puts(""); }
	template <class T> inline void writeln(T x, char c) { write(x); putchar(c); }
	template <class T> inline void writeln(char c, T x) { putchar(c); write(x); }

	template <class T> inline void chkmax(T &x, const T y) { x > y ? x = x : x = y; }
	template <class T> inline void chkmin(T &x, const T y) { x < y ? x = x : x = y; }
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
	Maxn = 500005
};

int n, m, arr[2][Maxn], l1, l2, r1, r2, opt;

inline int divide(void) {
	int l = l1, r = r1, pos = r1 - l1 + r2 - l2 + 3 >> 1, ret = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		int _l = lower_bound(arr[1] + l2, arr[1] + r2 + 1, arr[0][mid]) - arr[1];
		if (arr[1][_l] > arr[0][mid] || _l == r2 + 1) {
			if (mid - l1 + 1 + _l - l2 == pos) { ret = mid; break; }
			else if (mid - l1 + 1 + _l - l2 < pos) l = mid + 1;
			else r = mid - 1;
		} else {
			int _r = upper_bound(arr[1] + l2, arr[1] + r2, arr[0][mid]) - arr[1] - 1;
			if (mid - l1 + 1 + _l - l2 <= pos && mid - l1 + 2 + _r - l2 >= pos) { ret = mid; break; }
			else if (mid - l1 + 1 + _l - l2 > pos) r = mid - 1;
			else l = mid + 1;
		}
	} if (ret) return arr[0][ret];
	l = l2, r = r2, ret = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		int _l = lower_bound(arr[0] + l1, arr[0] + r1 + 1, arr[1][mid]) - arr[0];
		if (arr[0][_l] > arr[1][mid] || _l == r1 + 1) {
			if (mid - l2 + 1 + _l - l1 == pos) { ret = mid; break; }
			else if (mid - l2 + 1 + _l - l1 < pos) l = mid + 1;
			else r = mid - 1;
		} else {
			int _r = upper_bound(arr[0] + l1, arr[0] + r1, arr[1][mid]) - arr[0] - 1;
			if (mid - l2 + 1 + _l - l1 <= pos && mid - l2 + 2 + _r - l1 >= pos) { ret = mid; break; }
			else if (mid - l2 + 1 + _l - l1 > pos) r = mid - 1;
			else l = mid + 1;
		}
	} return arr[1][ret];
}

int c[Maxn * 2];

int main(void) {
	file("median");
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(arr[0][i]);
	for (int i = 1; i <= n; i++) read(arr[1][i]);
	
//	if (n <= 1000 && m <= 2000) {
//		while (m--) {
//			read(opt), read(l1), read(r1), read(l2);
//			if (opt == 1) arr[l1][r1] = l2;
//			else { read(r2);
//				merge(arr[0] + l1, arr[0] + r1 + 1,
//				arr[1] + l2, arr[1] + r2 + 1, c + 1);
//				int tmp = r1 - l1 + r2 - l2 + 3 >> 1;
//				writeln(c[tmp]);
//			}
//		} return 0;
//	}
	
	while (m--) {
		read(opt), read(l1), read(r1), read(l2);
		if (opt == 1) arr[l1][r1] = l2;
		else { read(r2);
			writeln(divide());
		}
	}
//	fwrite(pf, 1, o1 - pf, stdout);
	return 0;
}

/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/

