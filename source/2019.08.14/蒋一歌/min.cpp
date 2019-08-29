#include <bits/stdc++.h>
#define LL		long long
#define Maxn	300500
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const LL inf = 5e18;

struct node{ LL x; int id; }; stack <node> stk;
LL f[Maxn], a[Maxn];
int n; LL A, B, C, D;

struct Segment_tree{
	LL val[Maxn << 2];
	void init(){ for (int i = 1; i <= (Maxn * 4 - 55); i++) val[i] = -inf; }
	void modify(int pos, int P, LL x, int l, int r){
		if (l == r){ val[pos] = x; return; }
		int son1 = pos << 1, son2 = pos << 1 | 1, mid = (l + r) >> 1;
		if (P <= mid) modify(son1, P, x, l, mid);
		else modify(son2, P, x, mid + 1, r);
		val[pos] = max(val[son1], val[son2]);
	}
	LL query(int pos, int L, int R, int l, int r){
		if (L > R) return 0;
		if (L <= l && R >= r) return val[pos];
		int son1 = pos << 1, son2 = pos << 1 | 1, mid = (l + r) >> 1; LL ans = -inf;
		if (L <= mid) ans = query(son1, L, R, l, mid);
		if (R > mid) ans = max(ans, query(son2, L, R, mid + 1, r));
		return ans;
	}	
} Sgt;

LL F(LL x){ return x * x * x * A + x * x * B + x * C + D; }

int main(){
	freopen("min.in", "r", stdin); freopen("min.out", "w", stdout);
	read(n), read(A), read(B), read(C), read(D);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	Sgt.init();
	stk.push((node) {-inf, 0});
	Sgt.modify(1, 0, 0, 0, n);
	f[0] = -inf;
	for (int i = 1; i <= n; i++){
		LL x = a[i], w = F(x);
		while (x <= stk.top().x) stk.pop();
		int p = stk.top().id, t = 0;
		f[i] = max(f[p], Sgt.query(1, p, i - 1, 0, n) + w);
		Sgt.modify(1, i, f[i], 0, n), stk.push((node) {a[i], i});
	}
	cout << f[n] << '\n';
	return 0;
}
