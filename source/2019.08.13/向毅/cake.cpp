#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
const int maxn = 300;
int n, m;
ll dp[maxn + 10][maxn + 10];
int main() {
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n > m) swap(n, m);
	dp[1][1] = 1;
	for (int i = 2; i <= m; i++) for (int j = 1; j < i; j++) dp[1][i] = (dp[1][i] + dp[1][j] * dp[1][i - j]) % mod;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i > j) { dp[i][j] = dp[j][i]; continue; }
			for (int k = 1; k < i; k++) dp[i][j] = (dp[i][j] + dp[k][j] * dp[i - k][j]) % mod;
			for (int k = 1; k < j; k++) dp[i][j] = (dp[i][j] + dp[i][k] * dp[i][j - k]) % mod;
		}
	}
	printf("%lld\n", dp[n][m]);
	return 0;
}


