#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, num[20];
bool h[20];
ll n, a[20];
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
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	t = rd();
	while (t--) {
		n = RD();
		a[0] = 0;
		ll tmp = n;
		while (tmp) { 
			a[++a[0]] = tmp % 10;
			tmp /= 10;
		}
		for (int i = 1; i <= a[0]; i++) {
			if (h[a[i]] == 0) num[++num[0]] = a[i];
			h[a[i]] = 1;
		}
		if (num[0] <= 2) {
			printf("1\n");
		} else {
			printf("2\n");
		}
	}
	return 0;
}

