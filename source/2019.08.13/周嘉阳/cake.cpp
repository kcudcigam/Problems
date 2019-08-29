#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 300 + 10;
#define ll long long
#define ri register int
ll F[MAX_N][MAX_N];

inline ll dfs(int n, int m) {
	if (n > m) swap(n, m);
	if (F[n][m]) return F[n][m];
	for (ri i = 1; i < n; i++)
		F[n][m] = (F[n][m] + dfs(n - i, m) * dfs(i, m) % MOD) % MOD;
	for (ri i = 1; i < m; i++)
		F[n][m] = (F[n][m] + dfs(n, m - i) * dfs(n, i) % MOD) % MOD;
	return F[n][m];
}

int main() {
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	F[1][1] = 1;
	printf("%lld\n", dfs(n, m));
	return 0;
}

