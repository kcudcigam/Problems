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
	Maxn = 255
};

int n, m, num[6];
int L[Maxn], R[Maxn], a[Maxn], b[Maxn];

inline int F(int x) {
	int ret = 0;
	for (int i = 1; i <= 5; i++)
		ret += num[i] * pow(x, i);
	return ret;
}

struct SegmentTree {
	int tmax[4000005], tag[4000005];
	
	inline void addtag(int pos, int val) {
		tmax[pos] += val, tag[pos] += val;
	}
	
	inline void pushdown(int pos, int l, int r) {
		if (tag[pos]) {
			int mid = l + r >> 1;
			addtag(pos << 1, tag[pos]),
			addtag(pos << 1 | 1, tag[pos]);
			tag[pos] = 0;
		}
	}
	
	inline void pushup(int pos) {
		tmax[pos] = max(tmax[pos << 1], tmax[pos << 1 | 1]);
	}
	
	inline void build(int pos, int l, int r) {
		tmax[pos] = tag[pos] = 0;
		if (l == r) return;
		int mid = l + r >> 1;
		build(pos << 1, l, mid), build(pos << 1 | 1, mid + 1, r);
	}
	
	inline void modify(int pos, int l, int r, int L, int R, int val) {
		if (L <= l && R >= r) addtag(pos, val);
		int mid = l + r >> 1; pushdown(pos, l, r);
		if (L <= mid) modify(pos << 1, l, mid, L, R, val);
		if (R > mid) modify(pos << 1 | 1, mid + 1, r, L, R, val);
		pushup(pos);
	}
	
	inline int query(int pos, int l, int r, int L, int R) {
		if (L <= l && R >= r) return tmax[pos];
		int mid = l + r >> 1, ret = 0; pushdown(pos, l, r);
		if (L <= mid) chkmax(ret, query(pos << 1, l, mid, L, R));
		if (R > mid) chkmax(ret, query(pos << 1 | 1, mid + 1, r, L, R));
		return ret;
	}
} sgt;

signed main(void) {
	file("stand");
	read(n), read(m);
	for (int i = 1; i <= 5; i++) read(num[i]);
	for (int i = 1; i <= n; i++) {
		read(R[i]), read(R[i]);
		a[i] = L[i], b[i] = R[i];
	}
	
	bool flg = true;
	for (int i = 1; i <= n; i++) {
		if (L[i] != 1 || R[i] != m) flg = false;
	} if (flg) writeln(F(n));
	
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	int tmp1 = unique(a + 1, a + n + 1) - (a + 1);
	int tmp2 = unique(b + 1, b + n + 1) - (b + 1);
	sgt.build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		R[i] = lower_bound(b + 1, b + tmp2 + 1, R[i]) - b;
		L[i] = lower_bound(a + 1, a + tmp1 + 1, L[i]) - a;
	}
	
	for (int i = 1; i <= n; i++) {
		sgt.modify(1, 1, n, L[i], R[i], 1);
	}
	int s = n - sgt.query(1, 1, n, 1, n), ret = 0;
	while (s--) ret += F(1);
	writeln(ret + F(sgt.query(1, 1, n, 1, n)));
	//fwrite(pf, 1, o1 - pf, stdout);
	return 0;
}

/**/

