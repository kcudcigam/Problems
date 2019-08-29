#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define p1 p << 1
#define p2 p << 1 | 1
using namespace std;
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	x *= f;
}

const int N = 500005;

struct Seg{
	int l, r;
	ll d;
	ll sum, add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define d(x) tree[x].d
	#define add(x) tree[x].add
	#define sum(x) tree[x].sum
}tree[N<<2];

void build(int l,int r,int p) {
	l(p) = l, r(p) = r;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, p1);
	build(mid + 1, r, p2);
}

void spread(int p) {
	if (add(p)) {
		sum(p1) += (ll)(r(p1) - l(p1) + 1) * add(p);
		sum(p2) += (ll)(r(p2) - l(p2) + 1) * add(p);
		add(p1) += add(p);
		add(p2) += add(p);
		add(p) = 0;
	}
	if (d(p)) {
		d(p1) += d(p);
		sum(p2) += (ll)(l(p2) - l(p1)) * d(p) * (r(p2) - l(p2) + 1);
		sum(p) += (ll)(r(p) - l(p)) * d(p) * (r(p) - l(p) + 1) / 2; 
		d(p2) += d(p);
		add(p2) += (l(p2) - l(p1)) * d(p);
		d(p) = 0;
	}
}

void change(int l, int r, ll d, ll b, int p) {
	if (l(p) >= l && r(p) <= r) {
		d(p) += d;
		sum(p) += (ll)(b + (l(p) - l) * d) * (r(p) - l(p) + 1);
		add(p) += b + (l(p) - l) * d;
		return;
	}
	spread(p);
	int mid = (l(p) + r(p)) >> 1;
	if (mid >= l) change(l, r, d, b, p1);
	if (mid < r) change(l, r, d, b, p2);
}
	
ll ask(int x,int p) {
	if (l(p) == r(p)) {
		spread(p);
		return sum(p);
	}
	spread(p);
	int mid = (l(p) + r(p)) >> 1;
	if (x > mid) return ask(x, p2);
	return ask(x, p1);
}

int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ll n, m;
	read(n), read(m);
	build(1, n, 1);
	for (int i = 1;i <= m; i++) {
		ll l, r, s, e;
		read(l), read(r), read(s), read(e);
		ll d = (e - s) / (ll) (r - l);
		change(l, r, d, s, 1);
		//for (int i = 1;i <= n; i++) cout << ask(i, 1) << ' ';
		//cout << endl;
	}
	ll ans = 0;
	for (int i = 1;i <= n; i++) 
	ans ^= ask(i, 1);
	cout << ans << endl;
	return 0;
}
	
/*
6 5
1 3 2 6
3 6 1 7
2 5 3 3
4 5 6 9
1 6 1 6

*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
