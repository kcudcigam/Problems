#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
const int N = 800010;
bool cmp(int x, int y) {return x > y;}
int a[N], b[N], c[N];
int main() {
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	int n, m = 0, ans = 0, l1 = 0, l2 = 0, l3 = 0; read(n);
	for (int i = 1; i <= n; i++) {
		int op, v; read(op), read(v);
		if (op == 11) ans += v, m++;
		if (op == 10) a[++l1] = v;
		if (op == 1) b[++l2] = v;
		if (!op) c[++l3] = v;
	}
	sort(a + 1, a + l1 + 1, cmp), sort(b + 1, b + l2 + 1, cmp);
	for (int i = 1; i <= min(l1, l2); i++) ans += a[i] + b[i];
	if (l1 > l2) for (int i = l2 + 1; i <= l1; i++) c[++l3] = a[i];
		else for (int i = l1 + 1; i <= l2; i++) c[++l3] = b[i];
	sort(c + 1, c + l3 + 1, cmp);
	for (int i = 1; i <= min(m, l3); i++) ans += c[i];
	cout << ans << '\n';
	return 0;
}
