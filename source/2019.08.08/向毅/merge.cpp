#include <bits/stdc++.h>
using namespace std;
int n, m, fa[500010], ans[500010];
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void write(int x) {
	if (x / 10) {
		write(x / 10);
		putchar(x % 10 + '0');
	} else {
		putchar(x + '0');
	}
}
int main() {
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int t, x, y;
		read(t); read(x); read(y);
		if (t == 1) {
			int a = find(x), b = find(y);
			if (a != b) fa[b] = a;
		} else {
			x = find(x);
			for (int i = 1; i <= n; i++) {
				int d = find(i);
				if (d == x) ans[i] += y;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		write(ans[i]);
		printf(" ");
	}
	write(ans[n]);
	printf("\n");
	return 0;
}

