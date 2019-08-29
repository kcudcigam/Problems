#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, k;

LL dfs(LL n, LL k, LL s){
	if (n <= k) return 0;
	if (n & 1){
		if (k > 1) return min(dfs(n >> 1, k - 1, s << 1), dfs((n >> 1) + 1, k, s << 1) + s);
		return dfs((n >> 1) + 1, k, s << 1) + s;
	}
	return dfs(n >> 1, k, s << 1);
}

int main(){
	freopen("glass.in", "r", stdin);
	freopen("glass.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	printf("%lld\n", dfs(n, k, 1));
	return 0;
}
