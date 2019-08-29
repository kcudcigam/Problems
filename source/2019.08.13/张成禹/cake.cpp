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
const int p = 1e9 + 7;
int ml(int x, int y) { return 1ll * x * y - 1ll * x * y / p * p; }
int ad(int x, int y) { x += y; return x >= p ? x - p : x < 0 ? x + p : x; }
int n, m;
int f[305][305];
// n * m - 1
int main()
{
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	read(n), read(m);
	f[1][1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (i == 1 && j == 1) continue;
			for (int k = 1; k < i; ++k)
				f[i][j] = ad(f[i][j], ml(f[k][j], f[i - k][j]));
			for (int k = 1; k < j; ++k)	
				f[i][j] = ad(f[i][j], ml(f[i][k], f[i][j - k]));
		}
	cout << f[n][m] << '\n';
	return 0;
}

