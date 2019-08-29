#include<cstdio>
#include<iostream>
using namespace std;

const int MAXN = 101;
const long long MO = 1000000007;

int n, x, a[MAXN], b[MAXN], c[MAXN];
int maxd = -1;

long long rem1[MAXN][MAXN], rem2[MAXN * 2][MAXN][MAXN];

long long f1(int k, int i) {
	if(k == 0) return 1;
	if(i > n) return 0;
	if(rem1[k][i] > 0) return rem1[k][i];
	long long res = f1(k, i + 1);
	for(int j = 1; j <= c[i]; ++j) {
		if(k - j * a[i] < 0) break;
		res += f1(k - j * a[i], i + 1);
		res %= MO;
	}
	return rem1[k][i] = res;
}

long long f2(int k, int i, int mx) {
	if(k == 0) return 1;
	if(a[i] <= mx) return 0;
	if(rem2[k][i][mx] > 0) return rem2[k][i][mx];
	long long res = f2(k, i - 1, mx);
	for(int j = 1; j <= b[i]; ++j) {
		if(k - j * a[i] < 0) break;
		res += f2(k - j * a[i], i - 1, mx);
		res %= MO;
	}
	return rem2[k][i][mx] = res;
}

int main() {
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		if(b[i] > 0) maxd = max(maxd, a[i]);
	}
	long long ans = 0;
	for(int i = 0; i < maxd; ++i) {
		long long syy = f1(i, 1);
		if(syy == 0) continue;
		ans += (syy * f2(x + i, n, i)) % MO;
		ans %= MO;
	}
	printf("%lld", ans);
	return 0;
}

