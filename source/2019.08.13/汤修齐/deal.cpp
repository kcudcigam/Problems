#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1010, maxm = 20010;
const LL MOD = 1000000007;

int n, X;
LL f1[maxn][maxm], f2[maxm];
int val[maxn], a[maxn], b[maxn];

inline int Find(int x){
	int l = 0, r = n, mid;
	while (l + 1 < r){
		mid = l + r >> 1;
		if (val[mid] > x) r = mid;
		else l = mid;
	}
	return r;
}

int main(){
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	scanf("%d%d", &n, &X);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", val + i, a + i, b + i);
	
	f1[n + 1][0] = 1;
	for (int i = n; i >= 1; i--)
		for (int j = 0; j < X + val[n]; j++)
			for (int k = 0; k <= a[i] && val[i] * k <= j; k++)
				f1[i][j] = (f1[i][j] + f1[i + 1][j - val[i] * k]) % MOD;
	
	f2[0] = 1;
	for (int i = 1; i < n; i++)
		for (int j = val[n] - 1; j >= 0; j--)
			for (int k = 1; k <= b[i] && val[i] * k <= j; k++)
				f2[j] = (f2[j] + f2[j - val[i] * k]) % MOD;
	
	LL ans = 0;
	for (int i = 0; i < val[n]; i++)
		ans = (ans + f1[Find(i)][X + i] * f2[i] % MOD) % MOD;
	printf("%lld\n", ans);
	
	return 0;
}
