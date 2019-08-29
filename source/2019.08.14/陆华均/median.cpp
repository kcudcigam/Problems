#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	T f = 1;
	char c = getchar();
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
const int M = 5e5 + 5;
int ans, a[M], b[M], opt, xi, yi, zi, la, ra, lb, rb, sum;
inline int checka(int p) {
	int x = upper_bound(b + lb, b + rb + 1, a[p]) - b, y = lower_bound(b + lb, b + rb + 1, a[p]) - b;
	if (b[y] == a[p]) {
		if (y - lb + p - la > sum) return 3;
		if (x - 1 - lb + p - la < sum) return 2; 
		else return 1;
	}
	else{
		if (rb - x + 1 + ra - p > sum) return 2;
		else if (rb - x + 1 + ra - p < sum) return 3;
		return 1;
	}
}
inline void bina() {
	int l = la, r = ra;
	while(l < r) {
		int mid = (l + r) >> 1;
		int num = checka(mid);
		if (num == 1) {
			ans = a[mid];
			return;
		}
		else if (num == 3){
			r = mid - 1;
		}
		else if (num == 2) {
			l = mid + 1;
		}
	}
	if (l >= la && l <= ra && checka(l) == 1) ans = a[l];
	if (r >= la && r <= ra && checka(r) == 1) ans = a[r];
}
inline int checkb(int p) {
	int x = upper_bound(a + la, a + ra + 1, b[p]) - a, y = lower_bound(a + la, a + ra + 1, b[p]) - a;
	if (a[y] == b[p]) {
		if (y - la + p - lb > sum) return 3;
		else if (x - 1 - la + p - lb < sum) return 2; 
		else return 1;
	}
	else{
		if (ra - x + 1 + rb - p > sum) return 2;
		else if (ra - x + 1 + rb - p < sum) return 3;
		return 1;
	}
}
inline void binb() {
	int l = lb, r = rb;
	while(l < r) {
		int mid = (l + r) >> 1;
		int num = checkb(mid);
		if (num == 1) {
			ans = b[mid];
			return;
		}
		else if (num == 3){
			r = mid - 1;
		}
		else if (num == 2) {
			l = mid + 1;
		}
	}
	if (l >= lb && l <= rb && checkb(l) == 1) ans = b[l];
	if (r >= lb && r <= rb && checkb(r) == 1) ans = b[r];
}
int d[2001];
int main(){
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	int n, m;
	read(n); read(m);
	for (int i = 1; i <= n; i ++) read(a[i]);
	for (int i = 1; i <= n; i ++) read(b[i]);
	if (n <= 1000 && m <= 2000) {
		for (int i = 1; i <= m; i ++) {
			read(opt);
			if (opt == 1) {
				read(xi); read(yi); read(zi);
				if (!xi) {
					a[yi] = zi;
				}
				else b[yi] = zi;
			}
			else {
				read(la); read(ra); read(lb); read(rb);
				sum = (ra - la + rb - lb + 2) >> 1;
				int len = 0;
				for (int i = la; i <= ra; i ++) {
					d[++len] = a[i];
				}
				for (int j = lb; j <= rb; j ++) {
					d[++ len] = b[j];
				}
				sort(d + 1, d + len + 1);
				write(d[sum + 1], '\n');
			}
		}
	}
	else {
		for (int i = 1; i <= m; i ++) {
			read(opt);
			if (opt == 1) {
				read(xi); read(yi); read(zi);
				if (!xi) {
					a[yi] = zi;
				}
				else b[yi] = zi;
			}
			else {
				read(la); read(ra); read(lb); read(rb);
				sum = (ra - la + rb - lb + 2) >> 1;
				bina();
				binb();
				write(ans, '\n');
			}
		}
	}
	return 0;
}

