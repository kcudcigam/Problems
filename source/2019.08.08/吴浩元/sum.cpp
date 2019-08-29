#include<bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F3F3F3F3F

long long n, now, ans, maxi = -INF;
long long a[100010], f[100010], g[100010];

int main()
{
	// need check
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	for (long long i = 1; i <= n; i++)
	{
		now += a[i];
		maxi = max(maxi, a[i]);
		if (now < 0) now = 0;
		if (maxi >= 0) f[i] = max(now, f[i - 1]); else f[i] = maxi;
	}
	now = 0;
	maxi = -INF;
	for (long long i = n; i >= 1; i--)
	{
		if (maxi >= 0) g[i] = max(now, g[i + 1]); else g[i] = maxi;
		maxi = max(maxi, a[i]);
		now += a[i];
		if (now < 0) now = 0;
	}
	for (long long i = 1; i < n; i++)
		ans = max(ans, f[i] + g[i]);
	cout << ans << endl;

	return 0;
}

