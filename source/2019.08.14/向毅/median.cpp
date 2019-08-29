#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000;
int n, m, a[maxn + 10], b[maxn + 10];
inline int rd() {
	int x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x;
}
void wt(int x) { if (x / 10) wt(x / 10); putchar((x % 10) ^ 48); }
int search(int *t1, int *t2, int l1, int r1, int l2, int r2, int pla) {
	int l = l1, r = r1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int lb1 = lower_bound(t1 + l1, t1 + r1 + 1, t1[mid]) - t1;
		int ub1 = upper_bound(t1 + l1, t1 + r1 + 1, t1[mid]) - t1;
		int lb2 = lower_bound(t2 + l2, t2 + r2 + 1, t1[mid]) - t2;
		int ub2 = upper_bound(t2 + l2, t2 + r2 + 1, t1[mid]) - t2;
		int L = lb1 - l1 + lb2 - l2 + 1, R = ub1 - l1 + ub2 - l2;
		if (L <= pla && R >= pla) return mid;
		if (R <= pla) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return 0;
}
int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	n = rd(); m = rd();
	for (int i = 1; i <= n; i++) a[i] = rd();
	for (int i = 1; i <= n; i++) b[i] = rd();
	for (int i = 1; i <= m; i++) {
		int type = rd();
		if (type == 1) {
			int x = rd(), y = rd(), z = rd();
			if (x == 0) a[y] = z;
			if (x == 1) b[y] = z;
		} else {
			int l1 = rd(), r1 = rd(), l2 = rd(), r2 = rd(), pla = (r1 - l1 + r2 - l2 + 3) >> 1;
			int x = search(a, b, l1, r1, l2, r2, pla);
			if (x) {
				wt(a[x]); printf("\n");
			} else {
				int x = search(b, a, l2, r2, l1, r1, pla);
				wt(b[x]); printf("\n");
			}
		}
	}
	return 0;
}


