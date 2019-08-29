#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 205, P = 1e9+7;
ll f[N][N], fx[N], fy[N];
int a[N], b[N], c[N];
int n, x;
ll ans;
int main(){
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int j = 0; j <= b[n] && j*a[n] <= 2*x; j++){
		f[n][j*a[n]] = 1;
		fx[j*a[n]] = 1;
	}
	for (int k = n-1; k; k--)
		for (int i = x+a[k]-1; i; i--){
			for (int j = 1; j <= b[k] && j*a[k] <= i; j++)
				f[k][i] = (f[k][i]+fx[i-j*a[k]])%P;
			fx[i] = (fx[i]+f[k][i])%P;
		}
	for (int j = 0; j <= c[1] && j*a[1] <= 2*x; j++) fy[j*a[1]] = 1;
	for (int k = 2; k <= n; k++)
		for (int i = x-1; i; i--)
			for (int j = 1; j <= c[k] && j*a[k] <= i; j++)
				fy[i] = (fy[i]+fy[i-j*a[k]])%P;
	for (int k = 1; k <= n; k++)
		for (int i = x; i < x+a[k]; i++)
			ans = (ans+(fy[i-x]*f[k][i]))%P;
	cout << ans << endl;
	return 0;
}


