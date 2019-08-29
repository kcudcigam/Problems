#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mo = (int)1e9 + 7;
int f[1010][20010], g[1010][20010], s[20010];
int a[1010], b[1010], c[1010];
int n, X, Max;

int Add(int a, int b) {
	LL t = (LL)((LL)a + (LL)b);	
	return (t >= mo) ? t - mo : t;
}

int main() {
	freopen("deal.in", "r", stdin); freopen("deal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> X;
	for (int i=1;i<=n;++i) cin >> a[n - i + 1] >> b[n - i + 1] >> c[n - i + 1];
	Max = X + a[1] - 1;
	for (int i=0;i<=n;++i) f[i][0] = 1;
	for (int i=1;i<=n;++i) {
		for (int j=0;j<a[i];++j) {
			s[0] = f[i - 1][j];
			for (int k=1;k<=Max/a[i];++k) {
				int tmp = a[i] * k + j;
				if (tmp <= Max) s[k] = Add(s[k - 1], f[i - 1][tmp]);
			}
			for (int k=0;k<=Max/a[i];++k) {
				int tmp = a[i] * k + j;
				if (tmp > Max) break;
				if (tmp - X >= a[i]) { f[i][tmp] = f[i - 1][tmp]; continue; }
				f[i][tmp] = ((s[k] - (k - b[i] - 1 >= 0 ? s[k - b[i] - 1] : 0)) + mo) % mo;
			}
		}
	}
	memset(s, 0, sizeof(s));
	for (int i=0;i<=n;++i) g[i][0] = 1;
	for (int i=1;i<=n;++i) {
		for (int j=0;j<a[i];++j) {
			s[0] = g[i - 1][j];
			for (int k=1;k<=Max/a[i];++k) {
				int tmp = a[i] * k + j;
				if (tmp <= Max) s[k] = Add(s[k - 1], g[i - 1][tmp]);
			}
			for (int k=0;k<=Max/a[i];++k) {
				int tmp = a[i] * k + j;
				if (tmp > Max) break;
				g[i][tmp] = ((s[k] - (k - c[i] - 1 >= 0 ? s[k - c[i] - 1] : 0)) + mo) % mo;
			}
		}
	}
	int ans = 0;
	for (int i=X;i<=X+a[1];++i)
		ans = (ans + (long long)f[n][i] * (long long)g[n][i - X] % mo) % mo;
	cout << ans << endl;
	return 0;
}
