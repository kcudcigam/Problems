#include<bits/stdc++.h>
using namespace std;

#define il inline
#define ll long long
#define ri register int
const int MAX_N = 1000000 + 10;
const double lg2 = log(2);
ll st[MAX_N][20], pw[20];
ll n, c1, c2, c3, c4, A[MAX_N];
ll F[MAX_N], ans;

template<typename Tp> inline void read(Tp &x) {
	int minus = 1; char ch; x = 0;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') minus = -1;
	for (; isdigit(ch); ch = getchar()) x *= 10, x += ch - '0';
	x *= minus;
}

il void init() {
	for (ri i = 0, j = 1; i < 20; i++, j *= 2)
		pw[i] = j/*, cout << i << " " << j << endl*/;
	for (ri i = 1; i <= n; i++)
		st[i][0] = A[i];
	for (ri j = 1; j < 20; j++) {
		for (ri i = 1; i <= n; i++) {
			if (i + pw[j - 1] > n) continue;
			st[i][j] = min(st[i][j - 1], st[i + pw[j - 1]][j - 1]);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= 20 && i + pw[j] - 1 <= n; j++)
//			printf("%d ", st[i][j]);
//		puts("");
//	}
}

il ll cal(ll x) {
//	return x;
	return c1 * x * x * x + c2 * x * x + c3 * x + c4;
}

il ll qry(ll l, ll r) {
	ll len = (ll)(log(r - l) / lg2);
	return cal(min(st[l][len], st[r - pw[len] + 1][len]));
}

int main() {
//	cout << LONG_LONG_MAX << endl;
//	cout << (double)log(200000) / log(2);
//	printf("%lld\n", (long long)pow(2, 49));
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	ll l, r;
	read(n), read(c1), read(c2), read(c3), read(c4);
	for (ri i = 1; i <= n; i++)
		read(A[i]);
	if (c1 == 0 && c2 == 0) {
		ll ans = 0;
		for (ri i = 1; i <= n; i++)
			ans += A[i] * c3;
		if (c4 > 0) ans += c4 * n;
		else ans += c4;
		printf("%lld\n", ans);
		return 0;
	}
	init();
//	while (true) {
//		read(l), read(r);
//		printf("%d\n", qry(l, r));
//	}
	for (ri i = 1; i <= n; i++) F[i] = -0x3f3f3f3f3f3f3f3f;
	F[0] = 0, F[1] = qry(1, 1);
	for (ri i = 2; i <= n; i++) {
		for (ri j = 0; j < i; j++) {
			F[i] = max(F[i], F[j] + qry(j + 1, i));
		}
	}
//	for (int i = 1; i <= n; i++) printf("%lld\n", F[i]);
	printf("%lld\n", F[n]);
	return 0;
}

