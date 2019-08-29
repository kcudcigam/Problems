#include <bits/stdc++.h>
using namespace std;

#define MODN 1000000007

int f[1010][20010], g[1010][20010], fa[1010][20010];
int n, m, vm;
long long ans;
int v[1010], a[1010], b[1010];

int main()
{
	// mod
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> a[i] >> b[i];
		vm = max(vm, v[i]);
	}
	for (int j = 0; j < m + v[n]; j++)
		if (j % v[n] == 0 && a[n] * v[n] >= j)
		{
			f[n][j] = 1;
			if (j != 0) fa[n][j] = 1;
		}
		else
		{
			f[n][j] = 0;
			fa[n][j] = 0;
		}
	for (int i = n - 1; i >= 1; i--)
		for (int j = 0; j < m + v[i]; j++)
		{
			for (int k = 0; k <= a[i]; k++)
			{
				if (j - k * v[i] >= 0)
				{
					f[i][j] = (f[i][j] + f[i + 1][j - k * v[i]]) % MODN;
					if (k != 0) fa[i][j] = (fa[i][j] + f[i + 1][j - k * v[i]]) % MODN;
				}
			}
		}
	//cout << f[1][10] << " " << f[2][11] << " " << f[3][10] << endl;
	g[0][0] = 1;
	for (int j = 0; j < vm; j++)
		if (j % v[1] == 0 && b[1] * v[1] >= j)
			g[1][j] = 1;
		else
			g[1][j] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < vm; j++)
		{
			int res = 0;
			for (int k = 0; k <= b[i]; k++)
			{
				if (j - k * v[i] >= 0)
					res = (res + g[i - 1][j - k * v[i]]) % MODN;
			}
			g[i][j] = res;
		}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m + vm; j++)
			cout << fa[i][j] << " ";
		cout << endl;
	}
	*/
	for (int i = 0; i < n; i++)
		for (int j = m; j < m + vm; j++)
		{
			ans = (ans + (long long)fa[i + 1][j] * (long long)g[i][j - m]) % MODN;
		}
	cout << ans << endl;

	return 0;
}


