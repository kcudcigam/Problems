#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ri register int
const int MOD = 1000000007;
const int MAX_N = 1000 + 10;
int A[MAX_N], B[2][MAX_N], n, x;
ll ret[2], ans;

inline void dfs(int cur, int flg, int lim, int las) {
//	printf("cur%d flg%d lim%d las%d\n", cur, flg, lim, las);
	if (cur == 0) {
//		puts("GET!!");
		ret[flg] = (ret[flg] + 1) % MOD;
		return;
	}
	if (cur < 0 || cur < A[1]) return;
	if (A[--las] <= lim) return;
	if (las < 1) return;
	for (int j = 0; j <= B[flg][las]; j++) {
		B[flg][las] -= j;
		if (cur - A[las] * j < 0) {
			B[flg][las] += j;
			return;
		}
//		printf("using %d %dpieces\n", A[las], j);
		dfs(cur - A[las] * j, flg, lim, las);
		B[flg][las] += j;
	}
}

int main() {
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &A[i], &B[0][i], &B[1][i]);
	for (int i = x; i < x + A[n]; i++) {
		ret[0] = 0, dfs(i, 0, i - x, n + 1);
		ret[1] = 0, dfs(i - x, 1, -1, n + 1);
		ans = (ans + ret[0] * ret[1] % MOD) % MOD;
//		cout << i << " " << ret[0] << " " << ret[1] << " " << ans << endl;
	}
	printf("%lld\n", ans);
	return 0;
}

