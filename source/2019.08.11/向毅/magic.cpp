#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 998244353;
ll n, len;
string s;
ll power(ll x, ll y, ll mod) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		y >>= 1;
		x = x * x % mod;
	}
	return res;
}
inline ll rd() {
	ll x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	n = rd(); cin >> s;
	len = s.size();
	if (len == n) {
		printf("1\n");
		return 0;
	}
	ll ans = 0, tmp = 1;
	for (int i = len + 1; i <= n; i++) {
		tmp = tmp * 26 % MOD;
		ans = (ans + (len + 1) * tmp) % MOD;
		ans = ((ans - (len - (i - len) + 1)) % MOD + MOD) % MOD;
	}
	printf("%lld\n", ((power(26, n, MOD) - ans) % MOD + MOD) % MOD);
	return 0;
}

