#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
const int N = 20010, Mod = 1e9 + 7;
int a[N], b[N], v[N], f[N], g[N], id[N], pre[N];
int main() {
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	int n, X; read(n), read(X);
	for (int i = 1; i <= n; i++)
		read(v[i]), read(b[i]), read(a[i]);
	f[0] = 1; int m = 2e4;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			id[j] = j / v[i], pre[j] = j < v[i] ? f[j] : (pre[j - v[i]] + f[j]) % Mod;
			f[j] = id[j] <= a[i] ? pre[j] : (pre[j] - pre[j - (a[i] + 1) * v[i]] + Mod) % Mod;
		}
	g[0] = 1; int ans = 0;
	for (int i = n; i; --i) {
		int mn = v[i];
		for (int j = 0; j <= m; j++) {
			int val = g[j];
			id[j] = j / v[i], pre[j] = j < v[i] ? g[j] : (pre[j - v[i]] + g[j]) % Mod;
			g[j] = id[j] <= b[i] ? pre[j] : (pre[j] - pre[j - (b[i] + 1) * v[i]] + Mod) % Mod;
			if (j >= X) {
				g[j] = (g[j] - val + Mod) % Mod;
				if (mn > j - X) ans = (ans + 1ll * g[j] * f[j - X] % Mod) % Mod;
				g[j] = (g[j] + val) % Mod;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

