#include <bits/stdc++.h>
using namespace std;
#define mr make_pair
#define pk push_back
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const LL  infll = 0x3f3f3f3f3f3f3f3fll, INFLL = 0x7fffffffffffffffll;
template <typename T> void read(T &x)
{
	x = 0; int f = 1; char c = getchar();
	for ( ; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for ( ; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void chkmax(T &x, T y) { x = x < y ? y : x; }
template <typename T> void chkmin(T &x, T y) { x = x > y ? y : x; }
const int N = 200005;
LL A, B, C, D;
int n, top;
LL mn[1010][1010];
LL f[N], a[N], g[N], s[N];
LL calc(LL x) { return A * x * x * x + B * x * x + C * x + D; }
int main()
{
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	read(n), read(A), read(B), read(C), read(D);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= n; ++i)
	{
		mn[i][i] = a[i];
		for (int j = i + 1; j <= n; ++j)
			mn[i][j] = min(mn[i][j - 1], a[j]);
	}
	for (int i = 1; i <= n; ++i)
	{
		f[i] = -2e18;
		for (int j = 0; j < i; ++j)
			f[i] = max(f[i], f[j] + calc(mn[j + 1][i]));
	}
/*	g[0] = 2e18;
	s[top = 1] = 0;
	for (int i = 1; i <= n; ++i)
	{
		while (top && a[i] < a[s[top - 1]])
			f[s[top - 1]] = max(f[s[top - 1]], f[s[top]]),
			g[s[top - 1]] = min(g[s[top - 1]], g[s[top]]),
			top--;
		g[s[top]] = min(g[s[top]], a[i]);
		g[s[top - 1]] = min(g[s[top - 1]], a[i]);
		f[i] = max(f[s[top]] + calc(g[s[top]]), f[s[top - 1]] + calc(g[s[top - 1]]));
		if (a[s[top]] >= a[i]) s[top] = i, g[s[top]] = 2e18;
		else s[++top] = i, g[s[top]] = 2e18;
	}*/
	cout << f[n] << '\n';
	return 0;
}

