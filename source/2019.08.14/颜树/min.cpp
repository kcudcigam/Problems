#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void chkmin(T &x, T y) {x = x < y ? x : y;}
template <typename T> void chkmax(T &x, T y) {x = x > y ? x : y;}
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
const int N = 200010; const ll inf = 1ll << 60;
int A, B, C, D, a[N]; ll f[N], g[N], st[N], mx[N];
ll calc(ll x) {return x * (x * (x * A + B) + C) + D;}
int main() {
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	int n; read(n), read(A), read(B), read(C), read(D);
	for (int i = 1; i <= n; i++) read(a[i]);
	memset(f, -0x3f, sizeof(f)), f[0] = 0, f[1] = calc(a[1]);
	int top = 1; st[1] = 1, mx[1] = g[1] = f[1];
	for (int i = 2; i <= n; i++) {
		ll tmp = -inf;
		while (top && a[st[top]] > a[i])
			chkmax(f[i], g[top] + calc(a[i])), chkmax(tmp, g[top]), top--;
		chkmax(f[i], f[st[top]] + calc(a[i]));
		chkmax(f[i], tmp + calc(a[i])), chkmax(f[i], mx[top]), chkmax(tmp, f[i]);
		st[++top] = i, g[top] = tmp, mx[top] = tmp + calc(a[i]), chkmax(mx[top], mx[top - 1]);
	}
	cout << f[n] << '\n';
	return 0;
}
