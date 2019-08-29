#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {
		if(c == '-') f = -f;
	}
	for(; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {
	write(x); putchar(sp);
}
int n, m, l, r, s, e, pos[500010];
LL arr[500010], ans;
struct node {
	LL val, add;
} tree[500010 << 2];
void push_up(int o) {
	tree[o].val = tree[o << 1].val + tree[o << 1 | 1].val;
}
void push_down(int o, int ll, int rr) {
	int mid = (ll + rr) >> 1;
	tree[o << 1].val = tree[o << 1].val + 1ll * (mid - ll + 1) * tree[o].add;
	tree[o << 1 | 1].val = tree[o << 1 | 1].val + 1ll * (rr - mid) * tree[o].add;
	tree[o << 1].add = 1ll * tree[o << 1].add + tree[o].add;
	tree[o << 1 | 1].add = 1ll * tree[o << 1 | 1].add + tree[o].add;
	tree[o].add = 0;
}
void build(int o, int l, int r) {
	tree[o].add = 0;
	if(l == r) {
		pos[l] = o;
		tree[o].val = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	push_up(o);
	return;
}
void modify_add(int o, int l, int r, int xl, int xr, int delta) {
	if(xr < l || r < xl) return;
	if(l == r) {
		if(xl <= l && r <= xr) {
			tree[o].val = tree[o].val + 1ll * delta * (r - l + 1);
			tree[o].add = tree[o].add + delta;
			return;
		}	
	}
	push_down(o, l, r);
	int mid = (l + r) >> 1;
	modify_add(o << 1, l, mid, xl, xr, delta);
	modify_add(o << 1 | 1, mid + 1, r, xl, xr, delta);
	push_up(o);
	return;
}
int query(int o, int l, int r, int xl, int xr) {
	if(xr < l || r < xl) return 0;
	if(xl <= l && r <= xr) {
		return tree[o].val;
	}
	push_down(o, l, r);
	int mid = (l + r) >> 1;
	return query(o << 1, l, mid, xl, xr) + query(o << 1 | 1, mid + 1, r, xl, xr);
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m);
	build(1, 1, n);
	_rep(i, 1, m) {
		read(l); read(r); read(s); read(e);
		int delta = (e - s) / (r - l);
		modify_add(1, 1, n, l + 1, r, delta);
		tree[pos[l]].val += s; 
		if(r + 1 <= n) tree[pos[r + 1]].val -= e;
	}
	int pre = 0;
	_rep(i, 1, n) {
		ans = ans ^ (pre = pre + tree[pos[i]].val);
	}
	writesp(ans);
	return 0;
}

