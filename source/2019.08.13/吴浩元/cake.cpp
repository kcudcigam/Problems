#include <bits/stdc++.h>
using namespace std;

#define MODN 1000000007

long long n, m;
long long f[1010][1010];

long long dfs(long long n, long long m)
{
	if (f[n][m] != 0) return f[n][m];
	if (n == 1 && m == 1)
	{
		f[n][m] = 1;
		return f[n][m];
	}
	long long ans = 0;
	for (long long i = 1; i < n; i++)
		ans = (ans + dfs(i, m) * dfs(n - i, m)) % MODN;
	for (long long i = 1; i < m; i++)
		ans = (ans + dfs(n, i) * dfs(n, m - i)) % MODN;
	f[n][m] = ans;
	return f[n][m];
}

int main()
{
	// use long long
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	cout << dfs(n, m) << endl;
	/*
	for (long long i = 1; i <= n; i++)
	{
		for (long long j = 1; j <= m; j++)
			cout << f[i][j] << " ";
		cout << endl;
	}
	*/

	return 0;
}

