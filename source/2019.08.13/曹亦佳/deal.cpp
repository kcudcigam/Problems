#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007, MAXN = 110, MAXX = 1010;
int n, x, dp[MAXN][MAXX], dp1[MAXN][MAXX], a[MAXN], b[MAXN], c[MAXN];

int main(){
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	cin >> n >> x;
	for (int i = 0; i < n; ++i) cin >> a[n-i] >> b[n-i] >> c[n-i];
	
	for (int i = 0; i <= b[1]; ++i) dp[1][a[1] * i] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < x; ++j) {
			//	cerr << "i:" << i << "j:" << j << " " << dp[i][j] << " " << b[i + 1]<< endl;
			for (int k = 0; k <= b[i + 1]; ++k) {
			//	cerr << j + a[i + 1] * k << " ";
				dp[i + 1][j + a[i + 1] * k] = (dp[i + 1][j + a[i + 1] * k] + dp[i][j]) % mod;
				if (j + a[i + 1] * k >= x) break;
			}
		//	cerr << endl;
		}
		for (int j = x; j < x + a[1]; ++j) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
	}	
	
	for (int i = 0; i <= c[1]; ++i) dp1[1][a[1] * i] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < a[1]; ++j) {
			//	cerr << "i:" << i << "j:" << j << " " << dp1[i][j] << " " << c[i + 1]<< endl;
			for (int k = 0; k <= c[i + 1]; ++k) {
			//	cerr << j + a[i + 1] * k << " ";
				dp1[i + 1][j + a[i + 1] * k] = (dp1[i + 1][j + a[i + 1] * k] + dp1[i][j]) % mod;
				if (j + a[i + 1] * k >= a[1]) break;
			}
		//	cerr << endl;
		}
	}
	
	int ans = 0;
	for (int i = x; i < x + a[1]; ++i) ans = ans + dp[n][i] * dp1[n][i - x];
	cout << ans << endl;

	return 0;
}
/*
3 10
1 5 3
3 2 2
5 3 2
*/
