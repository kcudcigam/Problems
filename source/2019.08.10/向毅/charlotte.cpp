#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T, n, t[100010], x[100010], y[100010];
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
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	T = rd();
	while (T--) {
		n = rd();
		for (int i = 1; i <= n; i++) t[i] = rd(), x[i] = rd(), y[i] = rd();
		int sx = 0, sy = 0, st = 0;
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			int tx = abs(x[i] - sx), ty = abs(y[i] - sy), have = t[i] - st, need = tx + ty;
			if (need > have) {
				flag = 0;
				break;
			} else {
				have -= need;
				if (have & 1) {
					flag = 0;
					break;
				}
			}
		}
		if (flag) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

