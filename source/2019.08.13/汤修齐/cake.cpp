#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 310;
const LL MOD = 1000000007;

int n, m;
LL f[maxn][maxn];

LL dfs(int n, int m){
	if (n > m) swap(n, m);
	LL &x = f[n][m];
	if (x) return x;
	for (int i = 1; i < n; i++)
		x = (x + dfs(i, m) * dfs(n - i, m)) % MOD;
	for (int i = 1; i < m; i++)
		x = (x + dfs(n, i) * dfs(n, m - i)) % MOD;
	return x;
}

int main(){
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	scanf("%d%d", &n, &m);
	f[1][1] = 1;
	printf("%lld\n", dfs(n, m));
	return 0;
}
