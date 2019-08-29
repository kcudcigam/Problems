#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T, n;
ll p, ans;
template <typename T> void read(T &x) {
	int f = 1;
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int main() {
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	read(T);
	while (T--) {
		read(n); read(p);
		if (n == 1) {
			cout << "0" << endl;
			continue;
		}
		if (n == 2) {
			cout << "2" << endl;
			continue;
		}
		ans = 2;
		for (ll i = 3; i <= n; i++) {
			ans = ans * i % p;
			if (i % 2) {
				ans = (ans + i * (i - 1) % p) % p;
			} else {
				ans = (ans + (i * (i - 1) - (i - 2)) % p) % p;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

