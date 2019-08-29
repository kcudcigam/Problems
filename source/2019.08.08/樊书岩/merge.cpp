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
const int maxn = 500010;
int n, q, tot, a[maxn], root;
struct node {
	int parent, lc, rc, val, id;
} heap[maxn * 2];
int getfather(int x) {
	return heap[x].parent == x ? x : heap[x].parent = getfather(heap[x].parent);
}
void unite(int x, int y) {
	int fx = getfather(x), fy = getfather(y);
	if(fx == fy) return;
	root = ++tot;
	heap[tot].lc = fx; heap[tot].rc = fy; heap[tot].parent = tot; heap[tot].val = 0;
	heap[fx].parent = tot; heap[fy].parent = tot;
}
void modify(int x, int delta) {
	heap[getfather(x)].val += delta;
}
void init(int x, LL ans) {
	if(heap[x].id) {
		a[heap[x].id] = ans + heap[x].val;
		return;
	}
	if(heap[x].lc) init(heap[x].lc, ans + heap[x].val);
	if(heap[x].rc) init(heap[x].rc, ans + heap[x].val);
	return;
} 
int query(int x, LL ans) {
	if(heap[x].parent == x) {
		return ans + heap[x].val;
	}
	return query(heap[x].parent, ans + heap[x].val);
}
int main() {
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	read(n); read(q);
	_rep(i, 1, n) {
		heap[i].id = i;
		heap[i].parent = i; heap[i].val = 0;
	}
	tot = n;
	_rep(i, 1, q) {
		int opt, a, b; read(opt); read(a); read(b);
		if(opt == 1) {
			unite(a, b);
		} else {
			modify(a, b);
		}
	}
	init(root, 0);
	_rep(i, 1, n) {
		writesp(a[i], ' ');
	}
	putchar('\n');
	return 0;
}

