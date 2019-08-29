#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F3F3F3F3F

long long lg[1000010], st[200010][20], dp[200010], a[200010];
long long A, B, C, D, n, mini = -INF, ans, ansmin = INF;

long long query(long long l, long long r)
{
	long long t = lg[r - l + 1];
	return min(st[l][t], st[r - (1 << t) + 1][t]);
}

long long f(long long x)
{
	return A * x * x * x + B * x * x + C * x + D;
}

int main()
{
	// use long long / need further thinking
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	for (long long i = 2; i <= 1000000; i++)
		lg[i] = lg[i >> 1] + 1;
	cin >> n >> A >> B >> C >> D;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	if (n <= 5000)
	{
		long long t = lg[n];
		for (long long j = 1; j <= n; j++) st[j][0] = a[j];
		for (long long i = 1; i <= t; i++)
			for (long long j = 1; j + (1 << i) - 1 <= n; j++)
				st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		for (long long i = 1; i <= n; i++) dp[i] = -INF;
		for (long long i = 1; i <= n; i++)
			for (long long j = 1; j <= i; j++)
			{
				dp[i] = max(dp[i], dp[i - j] + f(query(i - j + 1, i)));
			}
		cout << dp[n] << endl;
	}
	else {
		for (long long i = 1; i <= n; i++)
		{
			if (mini < a[i])
			{
				if (mini == -INF || f(a[i]) > 0)
				{
					if (mini != -INF) ans += f(mini);
					mini = a[i];
				}
				//cout << i << ": " << mini << " " << ans << endl;
				continue;
			}
			if (mini >= a[i])
			{
				if (mini == -INF || f(mini) > 0)
				{
					if (mini != -INF) ans += f(mini);
					mini = a[i];
				}
				//cout << i << ": " << mini << " " << ans << endl;
				continue;
			}
		}
		if (mini != -INF) ans += f(mini);
		else
		{
			for (long long i = 1; i <= n; i++)
				ansmin = min(ansmin, a[i]);
			ans = f(ansmin);
		}
		cout << ans << endl;
	}

	return 0;
}


