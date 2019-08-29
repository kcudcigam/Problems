#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 310, Mod = 1e9 + 7;
int f[N][N], vis[N][N];
int calc(int n, int m) {
	if (!n || !m) return 0;
	if (n == 1 && m == 1) return 1;
	if (vis[n][m]) return f[n][m]; vis[n][m] = 1;
	for (int i = 1; i < n; i++)
		f[n][m] = (f[n][m] + 1ll * calc(i, m) * calc(n - i, m) % Mod) % Mod;
	for (int i = 1; i < m; i++)
		f[n][m] = (f[n][m] + 1ll * calc(n, i) * calc(n, m - i) % Mod) % Mod;
	return f[n][m];
}
int main() {
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	int n, m; cin >> n >> m;
	cout << calc(n, m) << '\n';
	return 0;
}
