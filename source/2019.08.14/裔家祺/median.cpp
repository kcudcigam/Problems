#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n, m;
int a[3][N];

template <typename T> void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { a = a * 10 + c - '0'; c = getchar(); }
	a *= f;
}

int Binary_search(int x, int L, int R, int tot, int LL, int RR) {
	int l = L, r = R, ans = -1, y = x ^ 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int tmp = mid - L + 1;
		int Tho = LL + (tot - tmp) - 1;
		if (Tho > RR) { l = mid + 1; continue; }
		if (Tho < LL - 1) { r = mid - 1; continue; }
		if (Tho < RR && a[y][Tho + 1] < a[x][mid]) r = mid - 1;
		else if (Tho >= LL && a[y][Tho] > a[x][mid]) l = mid + 1;
		else return a[x][mid];
	}
	return -1;
}

int solve(int l1, int r1, int l2, int r2) {
	int tot = (r1 - l1 + r2 - l2 + 3) / 2;
	int ans = Binary_search(0, l1, r1, tot, l2, r2);
	if (ans != -1) return ans;
	ans = Binary_search(1, l2, r2, tot, l1, r1);
	return ans;
}

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	read(n); read(m);
	for (int i=1;i<=n;++i) read(a[0][i]);
	for (int i=1;i<=n;++i) read(a[1][i]);
	while (m--) {
		int type, x, y, z, w;
		read(type); read(x); read(y); read(z);
		if (type == 1) a[x][y] = z;
		else {
			read(w);
			cout << solve(x, y, z, w) << '\n';
		}
	}
	return 0;
}
