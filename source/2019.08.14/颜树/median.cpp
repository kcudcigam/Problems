#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
const int N = 500010;
int a[N], b[N];
int geta(int l, int r, int x) {return x <= r ? a[x] : 1 << 30;}
int getb(int l, int r, int x) {return x <= r ? b[x] : 1 << 30;}
int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	int n, m; read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);
	while (m--) {
		int op; read(op);
		if (op & 1) {
			int x, y, z; read(x), read(y), read(z);
			if (x) b[y] = z; else a[y] = z;
		} else {
			int l1, r1, l2, r2; read(l1), read(r1), read(l2), read(r2);
			int len = r1 - l1 + 1 + r2 - l2 + 1, t = (len + 1) >> 1;
			if (r1 - l1 + 1 >= t)
				if (a[l1 + t - 1] <= b[l2]) {cout << a[l1 + t - 1] << '\n'; continue;}
			int l = l1 + max(0, t - (r2 - l2 + 1) - 1), r = min(r1, l1 + t - 1), pos = r;
			while (l <= r) {
				int mid = (l + r) >> 1, tmp = mid - l1 + 1;
				if (a[mid] >= getb(l2, r2, l2 + t - tmp - 1)) pos = mid, r = mid - 1;
					else l = mid + 1;
			}
			int tmp = pos - l1 + 1;
			if (a[pos] <= getb(l2, r2, l2 + t - tmp) && a[pos] >= getb(l2, r2, l2 + t - tmp - 1)) {cout << a[pos] << '\n'; continue;}
			l = l2 + max(0, t - (r1 - l1 + 1) - 1), r = min(r2, l2 + t - 1), pos = r;
			while (l <= r) {
				int mid = (l + r) >> 1, tmp = mid - l2 + 1;
				if (b[mid] >= geta(l1, r1, l1 + t - tmp - 1)) pos = mid, r = mid - 1;
					else l = mid + 1;
			}
			tmp = pos - l2 + 1; cout << b[pos] << '\n';
		}
	}
	return 0;
}

