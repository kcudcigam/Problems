#include <bits/stdc++.h>
#define Maxn	500500
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

int a[Maxn], b[Maxn];
int n, m;

int bfind(int x){
	int lft = 1, rgt = n, ret = 0;
	while (lft <= rgt){
		int mid = (lft + rgt) >> 1;
		if (b[mid] > x) rgt = mid - 1;
		else lft = mid + 1, ret = mid;
	}
	return ret;
}
int afindl(int x){
	int lft = 1, rgt = n, ret = 0;
	while (lft <= rgt){
		int mid = (lft + rgt) >> 1;
		if (a[mid] < x) lft = mid + 1;
		else rgt = mid - 1, ret = mid;
	}
	return ret;
}
int afindr(int x){
	int lft = 1, rgt = n, ret = 0;
	while (lft <= rgt){
		int mid = (lft + rgt) >> 1;
		if (a[mid] >= x) rgt = mid - 1;
		else lft = mid + 1, ret = mid;
	}
	return ret;
}

struct node{ int x, y; };

struct Segment_tree{
	int val[Maxn << 2], tag[Maxn << 2];
	void push_down(int pos, int son1, int son2){
		int x = tag[pos]; tag[pos] = 0;
		tag[son1] += x, tag[son2] += x;
		val[son1] += x, val[son2] += x;
	}
	void build(int pos, int l, int r){
		if (l == r){ val[pos] = bfind(a[l]); return; }
		int son1 = pos << 1, son2 = pos << 1 | 1, mid = (l + r) >> 1;
		build(son1, l, mid), build(son2, mid + 1, r);
		val[pos] = val[son2];
	}
	void modify(int pos, int P, int x, int l, int r){
		if (l == r){ val[pos] = bfind(a[l]); return; }
		int son1 = pos << 1, son2 = pos << 1 | 1, mid = (l + r) >> 1;
		if (tag[pos]) push_down(pos, son1, son2);
		if (P <= mid) modify(son1, P, x, l, mid);
		else modify(son2, P, x, mid + 1, r);
		val[pos] = val[son2];
	}
	void add(int pos, int L, int R, int x, int l, int r){
		if (L <= l && R >= r){ val[pos] += x, tag[pos] += x; return; }
		int son1 = pos << 1, son2 = pos << 1 | 1, mid = (l + r) >> 1;
		if (tag[pos]) push_down(pos, son1, son2);
		if (L <= mid) add(son1, L, R, x, l, mid);
		if (R > mid) add(son2, L, R, x, mid + 1, r);
		val[pos] = val[son2];
	}
	node find(int pos, int K, int L, int R, int l, int r){
		if (l == r) return (node) {l, max(L, min(val[pos], R)) + l};
		int son1 = pos << 1, son2 = pos << 1 | 1, mid = (l + r) >> 1;
		if (tag[pos]) push_down(pos, son1, son2);
		return max(L, min(val[son1], R)) + mid < K ? find(son2, K, L, R, mid + 1, r) : find(son1, K, L, R, l, mid); 
	}
} Sgt;

int main(){
	freopen("median.in", "r", stdin); freopen("median.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	Sgt.build(1, 1, n);
	for (int i = 1; i <= m; i++){
		int opt, x, y, z, zz; read(opt), read(x), read(y), read(z);
		if (opt == 1){
			if (!x) a[y] = z, Sgt.modify(1, y, z, 1, n);
			else {
				int lst = b[y], now = z, l, r;
				if (lst < now) l = afindl(lst), r = afindr(now), Sgt.add(1, l, r, -1, 1, n);
				else l = afindl(now), r = afindr(lst), Sgt.add(1, l, r, 1, 1, n);
				b[y] = z;
			}
		}
		else {
			read(zz); int Ans;
			int tot = y - x + 1 + zz - z + 1; tot /= 2;
			node tmp = Sgt.find(1, tot + x + z - 1, z - 1, zz, 1, n); int id = tmp.x, val = tmp.y;
			if (val == tot + x + z - 1 && id >= x && id <= y) Ans = a[id];
			else {
				if (id < x) id = x;
				if (id > y + 1) id = y + 1;
				tot -= (id - x), Ans = b[tot + z];
			}
			cout << Ans << '\n';
		}
	}
	return 0;
}
