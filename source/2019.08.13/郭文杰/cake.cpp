#include<bits/stdc++.h>

#define FILE "cake"

using namespace std;

static struct Read
{
	template<typename T>
	Read& operator>>(T& x)
	{
		int f = 1; x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
		for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
		x *= f;
		return *this;
	}
} read;

const long long MOD = 1000000007;
int n, m;
long long dp[301][301] = {{}, {0, 1}};

int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	read >> n >> m;
	for (auto i = 2; i <= m; ++i)
	{
		for (auto j = 1; j <= i / 2; ++j)
			dp[1][i] = (dp[1][i] + dp[1][j] * dp[1][i - j]) % MOD;
		dp[i][1] = dp[1][i];
	}
	cout << dp[n][m];
	return 0;
}
