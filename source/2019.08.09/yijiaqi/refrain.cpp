#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mo = (int)1e9 + 7;
int NUM, ans, n, m1, m2;
int M[1010][1010][4], x[100010][4], y[100010][4];
int a[1010];

template <typename T> void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { a = a * 10 + c - '0'; c = getchar(); }
	a *= f;
}

int check() {
	for (int i=1;i<=m1;++i)
		if (!M[a[x[i][0]]][a[y[i][0]]][0]) return 1;
	for (int i=1;i<=m2;++i)
		if (!M[a[x[i][1]]][a[y[i][1]]][1]) return 1;
	return 0;
}

signed main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	read(NUM); read(n); read(m1); read(m2);
	int tot = 1;
	for (int i=1;i<=n;++i) tot *= i;
	for (int i=1;i<=m1;++i) {
		read(x[i][0]); read(y[i][0]);
		M[x[i][0]][y[i][0]][0] = M[y[i][0]][x[i][0]][0] = 1;
	}
	if (n <= 10) {
		for (int i=1;i<=m2;++i) {
			read(x[i][1]); read(y[i][1]);
			M[x[i][1]][y[i][1]][1] = M[y[i][1]][x[i][1]][1] = 1;
		}
		for (int i=1;i<=n;++i) a[i] = i;
		for (int i=1;i<=tot;++i) {
			ans += check();
			next_permutation(a + 1, a + n + 1);
		}
		cout << ans % mo << endl;
	} else {
		int ans1 = 1;
		for (int i=1;i<=(m1+m2);++i)
			ans1 = ans1 * i % mo * 2 % mo;
		cout << ((tot - ans1) % mo + mo) % mo << endl;
	}
	return 0;
}
