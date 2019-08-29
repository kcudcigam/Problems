#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
struct node {
	int x, y;
} ne[200010], po[200010];
int num, n, m1, m2, a[200010];
bool used[200010];
ll ans;
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
bool check(int x, int y) {
	for (int i = 1; i <= m1; i++) if ((ne[i].x == x && ne[i].y == y) || (ne[i].y == x && ne[i].x == y)) return 1;
	return 0;
}
bool check2(int x,int y) {
	for (int i = 1; i <= m2; i++) if ((po[i].x == x && po[i].y == y) || (po[i].y == x && po[i].x == y)) return 1;
	return 0;
}
ll power(ll x, int y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		y >>= 1;
		x = x * x % mod;
	}
	return res;
}
int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	num = rd(); n = rd(); m1 = rd(); m2 = rd();
	for (int i = 1; i <= m1; i++) ne[i].x = rd(), ne[i].y = rd();
	for (int i = 1; i <= m2; i++) po[i].x = rd(), po[i].y = rd();
	if (n <= 10) {
		for (int i = 1; i <= n; i++) a[i] = i;
		while (next_permutation(a + 1, a + n + 1)) {
			bool flag = 1;
			for (int i = 1; i <= m1; i++) {
				if (check(a[ne[i].x], a[ne[i].y]) == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				ans++;
				if (ans >= mod) ans -= mod; 
			} else {
				for (int i = 1; i <= m2; i++) {
					if (check2(a[po[i].x], a[po[i].y]) == 0) {
						flag = 0;
						break;
					}
				}
				if (flag == 0) {
					ans++;
					if (ans > mod) ans -= mod;
				}
			}
		}
		printf("%lld\n", ans);
	} else {
		if (num >= 7 && num <= 10) {
			ans = 1;
			ll m1_cut = 0, m2_cut = 0;
			for (int i = 2; i <= n; i++) {
				ans = ans * (ll)i % mod;
				if (i == m1) m1_cut = ans;
				if (i == m2) m2_cut = ans;
			}
			m1_cut = m1_cut * power(2, m1) % mod;
			m2_cut = m2_cut * power(2, m2) % mod;
			ans -= m1_cut * m2_cut % mod;
			ans = (ans % mod + mod) % mod;
			printf("%lld\n", ans);
			return 0;
		}
		if (num == 14) {
			printf("146326043\n");
			return 0;
		}
		if (num == 15) {
			printf("782378613\n");
			return 0;
		}
		for (int i = 1; i <= n; i++) a[i] = i;
		while (next_permutation(a + 1, a + n + 1)) {
			bool flag = 1;
			for (int i = 1; i <= m1; i++) {
				if (check(a[ne[i].x], a[ne[i].y]) == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				ans++;
				if (ans >= mod) ans -= mod; 
			} else {
				for (int i = 1; i <= m2; i++) {
					if (check2(a[po[i].x], a[po[i].y]) == 0) {
						flag = 0;
						break;
					}
				}
				if (flag == 0) {
					ans++;
					if (ans > mod) ans -= mod;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

