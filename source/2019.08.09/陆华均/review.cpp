#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &X) {
	X = 0;
	char C = getchar();
	T F = 1;
	for (; !isdigit(C); C = getchar()) if (C == '-')  F = -1;
	for (; isdigit(C); C = getchar()) X = (X << 1) + (X << 3) + (C ^ 48);
	X *= F;
}
template <typename T> inline void w(T X) {
	if (X > 9) w(X / 10);
	putchar(X % 10 + 48);
}
template <typename T> inline void write(T X, char C) {
	if (X < 0) {
		putchar('-');
		X = -X;
	}
	w(X);
	putchar(C);
}
bool vis[65], a[500][500];
int main(){
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	long long num;
	read(num);
	int id = 60, n = 0, m = 0;
	for (long long i = 1152921504606846976; i; i >>= 1) {
		if (num >= i) {
			vis[id] = true;
			num -= i;
		}
		id --;
	}
	for (int i = 60; i >= 0; i --) {
		if (vis[i]) {
			int u = 2 * i + 1;
			if (!n) n = u + 1;
			if (!m) m = i * 3;
			a[u][n] = true;
			m ++;
		}
	}
	write(n, ' '); write(m, '\n');
	for (int i = 1; i <= n - 1; i += 2) {
		if (i != n - 1) printf("%d %d\n", i, i + 1);
		if (i != n - 1) printf("%d %d\n", i, i + 2);
		if (i != n - 1) printf("%d %d\n", i + 1, i + 2);
		if (a[i][n]) printf("%d %d\n", i, n);
	}
	return 0;
}


