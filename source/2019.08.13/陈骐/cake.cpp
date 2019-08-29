#include<bits/stdc++.h>
typedef long long ll;
#define MAXN 305

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
}

const ll mod = 1000000007;
ll f[MAXN][MAXN];

inline ll solve(int n, int m)
{
	if (f[n][m])
		return f[n][m];
	ll ans = 0;
	for (int i = 1; i < n; ++i)
		ans = (ans + (solve(i, m) * solve(n - i, m) % mod)) % mod;
	for (int i = 1; i < m; ++i)
		ans = (ans + (solve(n, i) * solve(n, m - i) % mod)) % mod;
	return f[n][m] = f[m][n] = ans;
}

int main(int argc, char *argv[])
{
	freopen ("cake.in", "r", stdin);
	freopen ("cake.out", "w", stdout);
	int n, m;
	read(n), read(m);
	f[1][1] = f[2][1] = f[1][2] = 1;
	printf ("%lld\n", solve(n, m) % mod);
	return 0;
}
