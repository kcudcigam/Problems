#include <bits/stdc++.h>
#define int long long
using namespace std;

int m, tot, lg, ans, n;
int x[100010], y[100010];

signed main() {
	freopen("review.in", "r", stdin); freopen("review.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> m;
	if (m == 1) {
		cout << 2 << ' ' << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}
	if (m == 2) {
		cout << 3 << ' ' << 3 << endl;
		cout << 1 << ' ' << 2 << endl;
		cout << 2 << ' ' << 3 << endl;
		cout << 1 << ' ' << 3 << endl;
		return 0;
	}
	int lg = 0, t = m;
	while ((1ll << lg) < m) ++lg;
	cout << lg << endl;
	if ((1ll << lg) > m) --lg;
	n = lg * 2 + 2;
	for (int i=1;i<n;++i) x[++tot] = i, y[tot] = i + 1, ++ans;
	for (int i=2;i<n;i+=2) x[++tot] = i, y[tot] = i + 2, ++ans;
	for (int i=lg-1;i>=0;--i)
		if (m & (1ll << i)) x[++tot] = 1, y[tot] = 2 * (lg - i + 1), ++ans;
	cout << n << ' ' << ans << endl;
	for (int i=1;i<=tot;++i) cout << x[i] << ' ' << y[i] << endl;
	return 0;
}
