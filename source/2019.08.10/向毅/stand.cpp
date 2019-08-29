#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
	int l, r;
} p[260];
int n, m;
bool used[260];
ll a[10], c[10000010], sum[10000010], ans;
ll f(ll x) {
	ll tmp = 1, res = 0;
	for (int i = 1; i <= 5; i++) {
		tmp *= x;
		res += a[i] * tmp;
	}
	return res;
}
void find_sum() { for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + c[i]; }
inline int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()); if (ch == '-') f = -f;
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
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	n = rd(); m = rd(); a[1] = RD(); a[2] = RD(); a[3] = RD(); a[4] = RD(); a[5] = RD();
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		p[i].l = rd(); p[i].r = rd();
		c[p[i].l] ++; c[p[i].r + 1]--;
		if (p[i].l != 1 || p[i].r != m) flag = 0;
	}
	if (flag) {
		printf("%lld\n", f((ll)n));
	} else {
		ll maxx, maxi, tot = 0;
		while (tot < n) {
			find_sum();
			maxx = 0;
			for (int i = 1; i <= m; i++) {
				if (sum[i] > maxx) {
					maxx = sum[i];
					maxi = i;
				}
			}
			ans += f(maxx);
			tot += maxx;
			for (int i = 1; i <= n; i++) {
				if (!used[i] && p[i].l <= maxi && p[i].r >= maxi) {
					c[p[i].l]--; c[p[i].r + 1]++;
					used[i] = 1;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

