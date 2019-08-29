#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long long INF = 2e18;
set <int> a[MAXN]; 
int n, m; long long x, dp[MAXN];
int main(int argc,char *argv[]) {
	freopen(argv[1], "r" ,stdin);
	scanf("%lld", &x);
	freopen(argv[5], "w" ,stdout);
	freopen(argv[2], "r" ,stdin);
	scanf("%d%d", &n, &m);
	if (n < 1 || m < 1 || n > 1e5 || m > 2e5) {
		printf("%d\n", 0);
		freopen(argv[6], "w" ,stdout);
		printf("Wrong Answer. N, M not in range.");
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int x = 0, y = 0; scanf("%d%d", &x, &y);
		if (x < 1 || y < 1 || x > n || y > n || x >= y) {
			printf("%d\n", 0);
			freopen(argv[6], "w" ,stdout);
			printf("Wrong Answer. u, v not in range.");
			return 0;
		}
		if (a[x].count(y)) {
			printf("%d\n", 0);
			freopen(argv[6], "w" ,stdout);
			printf("Wrong Answer. Multiple edges found.");
			return 0;
		}
		a[x].insert(y);
	}
	dp[n] = 1;
	for (int i = n - 1; i >= 1; i--) {
		for (auto x : a[i]) {
			dp[i] += dp[x];
			dp[i] = min(dp[i], INF);
		}
	}
	if (dp[1] == INF) {
		printf("%d\n", 0);
		freopen(argv[6], "w" ,stdout);
		printf("Wrong Answer. Too many paths from 1 to N.");
		return 0;
	}
	if (dp[1] != x) {
		printf("%d\n", 0);
		freopen(argv[6], "w" ,stdout);
		printf("Wrong Answer. Number of paths from 1 to N: %lld.", dp[1]);
		return 0;
	}
	int score = 1;
	score += n <= 64;
	score += n <= 256;
	score += n <= 2048;
	score += n <= 16384;
	printf("%d\n", score);
	freopen(argv[6], "w" ,stdout);
	printf("Correct Answer with N = %d.", n);
	return 0;
}
