#include<cstdio>
using namespace std;

int ri() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

int n, m, a[2][(int)5e5 + 1];

int solve() {
	int l0, r0, l1, r1;
	scanf("%d %d %d %d", &l0, &r0, &l1, &r1);
	int k = (r0 - l0 + 1 + r1 - l1 + 1) / 2 + 1;
	int p0 = l0, p1 = l1, ans;
	for(;k--;) {
		if(p1 > r1 || (p0 <= r0 && a[0][p0] < a[1][p1])) ans = a[0][p0++];
		else ans = a[1][p1++];
	}
	return ans;
}

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[0][i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[1][i]);
	for(;m--;) {
		int o = ri();
		if(o == 1) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			a[x][y] = z;
		} else {
			printf("%d\n", solve());
		}
	}
	return 0;
}

