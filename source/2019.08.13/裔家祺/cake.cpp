#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010;
const int mo = (int)1e9 + 7;
int n, m;
int f[N][N];

signed main() {
	freopen("cake.in", "r", stdin); freopen("cake.out", "w", stdout);
	cin >> n >> m;
	f[1][1] = 1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j) {
			if (i + j < 3) continue;
			for (int k=1;k<i;++k)
				f[i][j] = (f[i][j] + f[k][j] * f[i - k][j] % mo) % mo;
			for (int k=1;k<j;++k)
				f[i][j] = (f[i][j] + f[i][k] * f[i][j - k] % mo) % mo;
		}
	cout << f[n][m] << endl;
	return 0;
}
