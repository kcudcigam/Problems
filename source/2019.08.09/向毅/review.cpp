#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Y, p[70], u[10010], v[10010];
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
inline ll RD() {
	ll x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return x * f;
}
int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	p[0] = 1;
	for (ll i = 1; i <= 62; i++) p[i] = p[i - 1] * 2;
	Y = RD();
	bool flag = 0;
	ll flag_ans, ans;
	for (ll i = 0; i <= 62; i++) {
		if (p[i] == Y) {
			flag = 1;
			flag_ans = i;
			break;
		}
		if (p[i] < Y) ans = i;
	}
	if (flag) {
		if (flag_ans == 0) {
			printf("2 1\n1 2\n");
		} else {
			ll n = flag_ans + 2;
			ll m = n * (n - 1) / 2;
			printf("%lld %lld\n", n, m);
			for (ll i = 1; i < n; i++) for (ll j = i + 1; j <= n; j++) printf("%lld %lld\n", i, j);
		}
	} else {
		ll n = ans + 3, x = ans, m = 0;
		for (ll i = 1; i < n - 1; i++) {
			for (ll j = i + 1; j <= n - 1; j++) {
				u[++m] = i;
				v[m] = j;
			}
		}
		while (Y) {
			if (Y >= p[x]) {
				u[++m] = x + 2;
				v[m] = n;
				Y -= p[x];
			}
			x--;
		}
		printf("%lld %lld\n", n, m);
		for (ll i = 1; i <= m; i++) printf("%lld %lld\n", u[i], v[i]);
	}
	return 0;
}

