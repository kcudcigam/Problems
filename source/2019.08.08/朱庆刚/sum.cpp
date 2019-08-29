#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 100005;
const long long INF = 4223372036854775807;

struct tg {
	long long a;
	long long b;
	long long c;
};

int n;
long long a[MAXN], qsa[MAXN], t[MAXN * 4][3];
//0:ÄÚ²¿  1:×ó±ß  2:ÓÒ±ß 

inline long long qs(int l, int r) {
	return qsa[r] - qsa[l - 1];
}

void bt(int o, int l, int r) {
	if(l == r) {
		t[o][0] = t[o][1] = t[o][2] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	int lc = o << 1;
	int rc = (o << 1) + 1;
	bt(lc, l, mid);
	bt(rc, mid + 1, r);
	t[o][0] = max(t[lc][2], t[rc][1]);
	t[o][0] = max(t[o][0], t[lc][2] + t[rc][1]);
	t[o][0] = max(t[o][0], max(t[lc][0], t[rc][0]));
	t[o][1] = a[l];
	for(int ir = l + 1; ir <= r; ++ir)
		t[o][1] = max(t[o][1], qs(l, ir));
	t[o][2] = a[r];
	for(int il = l; il < r; ++il)
		t[o][2] = max(t[o][2], qs(il, r));
}

tg ft(int o, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr)
		return (tg){t[o][0], t[o][1], t[o][2]};
	int mid = (l + r) >> 1;
	int lc = o << 1;
	int rc = (o << 1) + 1;
	int sl = max(l, ql);
	int sr = min(r, qr);
	tg lres = (tg){-INF, -INF, -INF}, rres = (tg){-INF, -INF, -INF};
	
	if(ql <= mid && qr > mid) {
		lres = ft(lc, l, mid, ql, qr);
		rres = ft(rc, mid + 1, r, ql, qr);
		tg res = (tg){-INF, -INF, -INF};
		res.a = max(lres.c, rres.b);
		res.a = max(res.a, lres.c + rres.b);
		res.a = max(res.a, max(lres.a, rres.a));
		res.b = a[sl];
		for(int ir = sl + 1; ir <= sr; ++ir)
			res.b = max(res.b, qs(sl, ir));
		res.c = a[sr];
		for(int il = sl; il < sr; ++il)
			res.c = max(res.c, qs(il, sr));
		return res;
	}
	if(ql <= mid) return ft(lc, l, mid, ql, qr);
	if(qr > mid) return ft(rc, mid + 1, r, ql, qr);
}

int main() {
	
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		qsa[i] = qsa[i - 1] + a[i];
	}
	bt(1, 1, n);
	//1~i  i+1~n
	long long ans = -INF;
	for(int i = 1; i < n; ++i) {
		ans = max(ans, ft(1, 1, n, 1, i).a + ft(1, 1, n, i + 1, n).a);
	}
	printf("%lld", ans);
	return 0;
}

