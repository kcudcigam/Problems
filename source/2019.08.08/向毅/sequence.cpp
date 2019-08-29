#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[500010];
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n); read(m);
	for (ll i = 1; i <= m; i++) {
		ll l, r;
		ll s, e;
		read(l); read(r); read(s); read(e);
		ll cha = (e - s) / (r - l);
		ll x = s;
		for (ll j = l; j <= r; j++) {
			a[j] += x;
			x += cha;
		}
	}
	ll ans = a[1];
	for (ll i = 2; i <= n; i++) ans ^= a[i];
	cout << ans << endl;
	return 0;
}

