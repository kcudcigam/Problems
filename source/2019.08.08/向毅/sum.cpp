#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll logn = 20;
ll n, a[100010], dp1[100010], dp2[100010], lo[100010], maxx1[100010][30], maxx2[100010][30];
ll ans;
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
ll find1(ll l, ll r) {
	ll len = r - l + 1;
	return max(maxx1[l][lo[len]], maxx1[r - (1 << lo[len]) + 1][lo[len]]);
}
ll find2(ll l, ll r) {
	ll len = r - l + 1;
	return max(maxx2[l][lo[len]], maxx2[r - (1 << lo[len]) + 1][lo[len]]);
}
int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	read(n);
	for (ll i = 1; i <= n; i++) read(a[i]);
	dp1[1] = a[1];
	for (ll i = 2; i <= n; i++) dp1[i] = max(dp1[i - 1] + a[i], a[i]);
	dp2[n] = a[n];
	for (ll i = n - 1; i >= 1; i--) dp2[i] = max(dp2[i + 1] + a[i], a[i]);
	for (ll i = 1; i <= n; i++) {
		maxx1[i][0] = dp1[i];
		maxx2[i][0] = dp2[i];
	}
	for (ll j = 1; j <= logn; j++) {
		for (ll i = 1; i + (1 << j) - 1 <= n; i++) {
			maxx1[i][j] = max(maxx1[i][j - 1], maxx1[i + (1 << j - 1)][j - 1]);
			maxx2[i][j] = max(maxx2[i][j - 1], maxx2[i + (1 << j - 1)][j - 1]);
		}
	}
	for (ll i = 2; i <= n; i++) lo[i] = lo[i / 2] + 1;
	for (ll i = 1; i < n; i++) ans = max(ans, find1(1, i) + find2(i + 1, n));
	cout << ans << endl;
	return 0;
}

