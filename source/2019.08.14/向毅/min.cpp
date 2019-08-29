#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 200000;
const ll logn = 20;
ll n, A, B, C, D, a[maxn + 10], lo[maxn + 10], minx[maxn + 10][logn + 10], dp[2][maxn + 10];
ll query(ll l, ll r) { ll len = r - l + 1; return min(minx[l][lo[len]], minx[r - (1 << lo[len]) + 1][lo[len]]); }
ll f(ll X) { return A * X * X * X + B * X * X + C * X + D; }
void solve() {
	dp[0][1] = 0; dp[1][1] = f(a[1]);
	for (ll i = 2; i <= n; i++) {
		dp[1][i] = max(dp[0][1] + f(query(1, i)), dp[1][1] + f(query(2, i)));
		if (i == 2) {
			dp[0][i] = max(dp[0][1] + f(query(1, i - 1)), dp[1][1]);
		} else {
			dp[0][i] = max(dp[0][1] + f(query(1, i - 1)), dp[1][1] + f(query(2, i - 1)));
		}
		for (ll j = 2; j <= i; j++) {
			dp[1][i] = max(dp[1][i], dp[0][j] + f(query(j, i)));
			if (j + 1 <= i) dp[1][i] = max(dp[1][i], dp[1][j] + f(query(j + 1, i)));
			if (j <= i - 1) dp[0][i] = max(dp[0][i], dp[0][j] + f(query(j, i - 1)));
			if (j + 1 <= i - 1) dp[0][i] = max(dp[0][i], dp[1][j] + f(query(j + 1, i - 1)));
		}
	}
	printf("%lld\n", dp[1][n]);
}
int main() {
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &n, &A, &B, &C, &D);
	for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]), minx[i][0] = a[i];
	for (ll j = 1; j <= logn; j++) for (ll i = 1; i + (1 << j) - 1 <= n; i++) minx[i][j] = min(minx[i][j - 1], minx[i + (i << j - 1)][j - 1]);
	for (ll i = 2; i <= n; i++) lo[i] = lo[i >> 1] + 1;
	if (A == 0 && B == 0 && C <= 0 && D <= 0) {
		printf("%lld\n", f(query(1, n)));
		return 0;
	}
	solve();
	return 0;
}


