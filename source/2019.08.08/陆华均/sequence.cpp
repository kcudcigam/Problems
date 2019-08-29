#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	T  f = 1;
	char c = getchar();
	x = 0;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	w(x);
	putchar(c);
}
long long a[500005], sum, t[2000005], d[500005], suf[500005], tag[500005];
inline void down(int p, int l, int r) {
	int mid = (l + r) >> 1;
	tag[p << 1] += tag[p];
	tag[p << 1 | 1] += tag[p];
	t[p << 1] += (mid - l + 1) * tag[p];
	t[p << 1 | 1] += (r - mid) * tag[p];
	tag[p] = 0;
}
inline void query(int p, int l, int r, int ml, int mr) {
	if (l >= ml && r <= mr) sum += t[p];
	else {
		down(p, l, r);
		int mid = (l + r) >> 1;
		if (mid >= ml) query(p << 1, l, mid, ml, mr);
		if (mid < mr) query(p << 1 | 1, mid + 1, r, ml, mr);
	}
}
inline void modify(int p, int l, int r, int mi, long long k) {
	if (l == mi && r == mi) {
		t[p] += k;
	}
	else {
		down(p, l, r);
		int mid = (l + r) >> 1;
		if (mid >= mi) modify(p << 1, l, mid, mi, k);
		if (mid < mi) modify(p << 1 | 1, mid + 1, r, mi, k);
		t[p] = t[p << 1] + t[p << 1 | 1];
	}  
}
inline void update(int p, int l, int r, int ml, int mr, long long k) {
	if (l >= ml && r <= mr) {
		t[p] += (r - l + 1) * k;
		tag[p] += k;
	}
	else {
		int mid = (l + r) >> 1;
		down(p, l, r);
		if (mid >= ml) update(p << 1, l, mid, ml, mr, k);
		if (mid < mr) update(p << 1 | 1, mid + 1, r, ml, mr, k);
		t[p] = t[p << 1] + t[p << 1 | 1];
	}  
}
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int n, m;
	read(n); read(m);
	for (int i = 1; i <= m; i ++) {
		int li, ri, s, e;
		long long u;
		read(li); read(ri); read(s); read(e);
		if (li == ri) u = 0ll;
		else u = (e - s) / (ri - li) * 1ll;
		update(1, 1, n, li + 1, ri, u);
		if (ri + 1 <= n) modify(1, 1, n, ri + 1, - (u * (ri - li)));
		d[li] += s; d[ri + 1] -= s;
	}
	for (int i = 1; i <= n; i ++) suf[i] = suf[i - 1] + d[i];
	for (int i = 1; i <= n; i ++) {
		sum = 0;
		query(1, 1, n, 1, i);
		a[i] = suf[i] + sum;
		cout << a[i] << ' ' ;
	}
	cout << endl;
	long long ans = a[1];
	for (int i = 2; i <= n; i ++) {
		ans ^= a[i];
	}
	write(ans, '\n');
	return 0;
}


