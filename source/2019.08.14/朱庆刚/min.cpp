#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int MAXN = 2e5 + 1;

int n, k[4], a[MAXN];
int st[MAXN][20];
long long dp[MAXN];

inline int get_min(int l, int r) {
	int k = log(r - l + 1) / log(2);
	return min(st[l][k], st[r - (1 << k) + 1][k]);
}

inline long long f(int x) {
	return (long long)k[3] * (long long)x * (long long)x * (long long)x + (long long)k[2] * (long long)x * (long long)x + (long long)k[1] * (long long)x + (long long)k[0];
}

int main() {
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	scanf("%d %d %d %d %d", &n, &k[3], &k[2], &k[1], &k[0]);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		st[i][0] = a[i];
	}
	for(int i = 1; i <= log(n) / log(2); ++i) {
		for(int j = 1; j <= n - (1 << i) + 1; ++j) {
			st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	}
	
	if(n > 1000 && k[3] == 0 && k[2] == 0 && k[1] == 0) {
		if(k[0] > 0) printf("%lld", (long long)k[0] * (long long)n);
		else if(k[0] < 0) printf("%d", k[0]);
		else printf("0");
		return 0;
	} else if(n > 1000) {
		long long res = 0;
		for(int i = 1; i <= n; ++i) {
			if(f(a[i]) > 0) res += f(a[i]);
		}
		if(res == 0) printf("%lld", f(get_min(1, n)));
		else printf("%lld", res);
	}
	
	for(int i = 1; i <= n; ++i) {
		dp[i] = f(a[i]) + dp[i - 1];
		for(int j = i - 1; j >= 1; --j) {
			dp[i] = max(dp[i], f(get_min(j, i)) + dp[j - 1]);
		}
	}
	printf("%lld", dp[n]);
	return 0;
}


