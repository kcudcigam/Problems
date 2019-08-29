#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
int n, m1, m2, num;
namespace bf {
	const static int N = 20;
	int p[N], a[N][N], b[N][N];
	void solve() {
		for (int i = 1; i <= m1; i++) {
			int x, y; read(x), read(y);
			a[x][y] = a[y][x] = 1;
		}
		for (int i = 1; i <= m2; i++) {
			int x, y; read(x), read(y);
			b[x][y] = b[y][x] = 1;
		}
		for (int i = 1; i <= n; i++) p[i] = i;
		int ans = 0;
		do {
			bool fl = true;
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					if (a[i][j] < a[p[i]][p[j]] || b[i][j] < b[p[i]][p[j]]) fl = false;
			if (!fl) ans++;
		} while (next_permutation(p + 1, p + n + 1));
		cout << ans << '\n';
	}
}
namespace subtask1 {
	const int N = 100, Mod = 1e9 + 7;
	int fac[N], bit[N];
	void solve() {
		fac[0] = fac[1] = 1, bit[0] = 1; int tn = max(max(m1, m2), n);
		for (int i = 1; i <= tn; i++) bit[i] = bit[i - 1] * 2 % Mod;
		for (int i = 2; i <= tn; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
		int tmp = 1ll * fac[m1] * bit[m1] % Mod * fac[m2] % Mod * bit[m2] % Mod * fac[n - 2 * (m1 + m2)] % Mod;
		cout << (fac[n] - tmp + Mod) % Mod << '\n';
	}
}
namespace subtask2 {
	const int N = 110, Mod = 1e9 + 7;
	int cnt, siz, vis[N], head[N];
	struct Edge {int next, num;} e[N * N];
	void add(int x, int y) {e[++cnt] = (Edge) {head[x], y}, head[x] = cnt;}
	void dfs(int x) {
		vis[x] = 1, siz++;
		for (int p = head[x]; p; p = e[p].next) {
			int k = e[p].num;
			if (!vis[k]) dfs(k);
		}
	}
	void solve() {
		for (int i = 1; i <= m1; i++) {
			int x, y; read(x), read(y);
			add(x, y), add(y, x);
		}
		for (int i = 1; i <= m2; i++) {
			int x, y; read(x), read(y);
			add(x, y), add(y, x);
		}
		int ans = 1, tmp = 1;
		for (int i = 1; i <= n; i++) {
			ans = 1ll * ans * i % Mod;
			if (!vis[i]) siz = 0, dfs(i), tmp = 1ll * tmp * siz % Mod;
		}
		cout << (ans - tmp + Mod) % Mod << '\n';
	}
}
int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	read(num), read(n), read(m1), read(m2);
	if (num <= 6) return bf::solve(), 0;
	if (num <= 10) return subtask1::solve(), 0;
	if (num <= 14) return subtask2::solve(), 0;
	return 0;
}
