#include<bits/stdc++.h>
using namespace std;

int f[1010][1010], a[1010];
int n, m;

int dp(int x, int y)
{
	if (f[x][y] != -1) return f[x][y];
	f[x][y] = 0;
	if (x == 1 || x == 2)
	{
		bool flag = (y >= a[x]);
		f[x][y] = flag;
		return f[x][y];
	}
	int ans = dp(x - 1, y);
	if (y >= a[x]) ans = max(ans, dp(x - 2, y - a[x]) + 1);
	f[x][y] = ans;
	return f[x][y];
}

int main()
{
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = -1;
	cout << dp(n, m) << endl;

	return 0;
}

