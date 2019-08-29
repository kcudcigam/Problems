#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
int g[100];
ll f[500], l[500], r[500];
ll dp[500][500][500];
int main() {
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= 5; i++) cin >> g[i];
	for (int i = 1;i <= n; i++) {
		int x = i;
		for (int j = 1;j <= 5; j++) f[i] += g[j] * x, x *= i;
	}
	for (int i = 1;i <= n; i++) {
		scanf ("%lld %lld", &l[i], &r[i]);
	}
	ll ans = 0;
	for (int i = 1;i <= n; i++) ans = max(ans, f[i] + f[i-1]);
	cout << ans << endl;
	return 0;
}

