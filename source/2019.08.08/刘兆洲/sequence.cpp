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
	Maxn = 500005
};

int n, m, lpos, rpos; ll s, e, ans = 0, sss[Maxn];

struct SegmentTree {
	ll sum[Maxn << 2], tags[Maxn << 2], tage[Maxn << 2];
	
	SegmentTree(void) { Ms(sum, 0), Ms(tags, 0), Ms(tage, 0); }
	
	inline void pushup(int pos) {
		sum[pos] = sum[pos << 1] + sum[pos << 1 | 1];
	}
	
	inline void addtag(int pos, int l, int r, ll S, ll E) {
		sum[pos] += (ll) 1ll * (S + E) * (r - l + 1) / 2;
		tags[pos] += S, tage[pos] += E; return;
	}
	
	inline void pushdown(int pos, int l, int r) {
		if (tags[pos]) {
			int mid = l + r >> 1;
			ll gc = (tage[pos] - tags[pos]) / (r - l);
			addtag(pos << 1, l, mid, tags[pos], tags[pos] + (ll) 1ll * (mid - l) * gc);
			addtag(pos << 1 | 1, mid + 1, r, tags[pos] + (ll) 1ll * (mid - l + 1) * gc, tage[pos]);
			tags[pos] = tage[pos] = 0ll;
		}
	}
	
	inline void modify(int pos, int l, int r, int L, int R, ll S, ll E) {
		if (L <= l && R >= r) {
			ll gc = (ll) 1ll * (E - S) / (R - L);
			addtag(pos, l, r, S + (l - L) * gc, E - (R - r) * gc); 
			return;
		}
		register int mid = l + r >> 1; pushdown(pos, l, r);
		if (L <= mid) modify(pos << 1, l, mid, L, R, S, E);
		if (R > mid) modify(pos << 1 | 1, mid + 1, r, L, R, S, E);
		pushup(pos);
	}
	
	inline ll query(int pos, int l, int r, int L, int R) {
		if (L <= l && R >= r) return sum[pos];
		register int mid = l + r >> 1; pushdown(pos, l, r); ll ret = 0ll;
		if (L <= mid) ret += query(pos << 1, l, mid, L, R);
		if (R > mid) ret += query(pos << 1 | 1, mid + 1, r, L, R);
		return ret;
	}
} sgt;

int main(void) {
	file("sequence");
	read(n), read(m);
	if (n <= 1000 && m <= 1000) {
		while (m--) {
			read(lpos), read(rpos), read(s), read(e);
			ll gc = (e - s) / (rpos - lpos);
			for (int i = 0; i <= rpos - lpos; i++)
				sss[i + lpos] += (ll) (1ll * i * gc + s);
		}
		for (int i = 1; i <= n; i++) ans ^= sss[i];
		writeln(ans); return 0;
	}
	while (m--) {
		read(lpos), read(rpos), read(s), read(e);
		sgt.modify(1, 1, n, lpos, rpos, s, e);
	}
	for (int i = 1; i <= n; i++) ans ^= sgt.query(1, 1, n, i, i);
	writeln(ans);
	return 0;
}

