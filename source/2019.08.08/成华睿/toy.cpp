#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1005;
int f[MAXN][MAXN][2];
int a[MAXN];
int n, m;
int main(){
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j][0] = f[i][j][1] = 1e9;
	f[1][1][1] = a[1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++){
			f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1]);
			f[i][j][1] = f[i-1][j-1][0]+a[i];
		}
	for (int i = n; i >= 0; i--)
		if (min(f[n][i][0], f[n][i][1]) <= m){
			cout << i << endl;
			break;
		}
	return 0;
}

