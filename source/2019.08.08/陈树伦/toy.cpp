#include<bits/stdc++.h>
using namespace std;
int f[1001][1001][2];
int a[1001];
int main(){
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++) {
			f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1]);
			if (j) f[i][j][1] = f[i-1][j-1][0] + a[i];
		}
	for (int i = n; i >= 0; i--)
		if (min(f[n][i][0], f[n][i][1]) <= m) {
			cout << i;
			return 0;
		}
	return 0;
}

