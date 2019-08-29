#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
const ll maxn = 1000;
const ll maxm = 10000;
ll n, X, val[maxn + 10], L[maxn + 10], sho[maxn + 10], w_L[(maxm << 1) + 10], w_s[maxm + 10];
inline ll rd() {
	ll x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
int main() {
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	n = rd(); X = rd();
	for (ll i = 1; i <= n; i++) val[i] = rd(), L[i] = rd(), sho[i] = rd();
	for (ll i = n; i >= 1; i--) {
		for (ll j = val[n] - 1; j >= 1; j--) {
			ll t = w_s[j];
			for (ll k = 1; k <= sho[i] && j - val[i] * k >= 0; k++) {
				if (w_s[j - val[i] * k]) {
					t += w_s[j - val[i] * k];
				} else if (j - val[i] * k == 0) {
					t++;
				}
				t %= mod;
			}
			w_s[j] = t;
		}
	}
	w_s[0] = 1;
	for (ll i = n; i >= 1; i--) {
		for (ll j = X + val[n] - 1; j >= 1; j--) {
			ll t = w_L[j];
			for (ll k = 1; k <= L[i] && j - val[i] * k >= 0; k++) {
				if (j - val[i] * k >= X) break;
				if (w_L[j - val[i] * k]) {
					t += w_L[j - val[i] * k];
				} else if (j - val[i] * k == 0) {
					t++;
				}
				t %= mod;
			}
			w_L[j] = t;
		}
	}
 	ll ans = 0;
	for (ll i = 0; i < val[n]; i++) ans = (ans + w_L[X + i] * w_s[i] % mod) % mod;
	printf("%d\n", ans);
	return 0;
}


