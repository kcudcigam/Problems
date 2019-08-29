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

enum {
	Maxn = 100005
};

const ll Inf = -1047483647;
int n, a[Maxn]; ll ans;

struct SegmentTree {
	struct Node {
		ll lmax, rmax, sum, allmax;
		inline Node operator + (const Node&rhs) {
			return (Node) {
				max(lmax, rhs.lmax + sum),
				max(rhs.rmax, rmax + rhs.sum),
				sum + rhs.sum, rmax + rhs.lmax
			};
		}
	} t[Maxn << 2 | 1], tt;
	
	inline void build(int pos, int l, int r) {
		t[pos].lmax = t[pos].rmax = t[pos].allmax = Inf, t[pos].sum = 0;
		if (l == r) { t[pos] = (Node) {a[l], a[l], a[l], a[l]}; return; }
		register int mid = l + r >> 1;
		build(pos << 1, l, mid), build(pos << 1 | 1, mid + 1, r);
		t[pos] = t[pos << 1] + t[pos << 1 | 1];
	}
	
	inline Node query(int pos, int l, int r, int L, int R) {
		if (L <= l && R >= r) return t[pos];
		register int mid = l + r >> 1;
		if (R <= mid) return query(pos << 1, l, mid, L, R);
		else if (L > mid) return query(pos << 1 | 1, mid + 1, r, L, R);
		else return query(pos << 1, l, mid, L, mid) + query(pos << 1 | 1, mid + 1, r, mid + 1, R);
	}
	
	inline ll query(int l, int r) {
		tt = query(1, 1, n, l, r); return tt.allmax;
	}
} sgt;

int main(void) {
	file("sum");
	read(n); 
	for (int i = 1; i <= n; i++) read(a[i]);
	sgt.build(1, 1, n);
	for (int i = 1; i < n; i++)
		chkmax(ans, sgt.query(1, i) + sgt.query(i + 1, n));
	writeln(ans);
	return 0;
}

