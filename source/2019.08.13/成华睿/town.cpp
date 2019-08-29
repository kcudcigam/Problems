#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2005;
int a[N][N], d[N][N], s[N], z[N], md[N];
int n, x, y, zx, zy, ans;
int main(){
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		a[i][1] = i;
		z[i] = i;
		s[i] = 1;
	}
	for (int k = 1; k < n; k++){
		cin >> x >> y;
		if (s[z[x]] > s[z[y]]) swap(x, y);
		zx = z[x];
		zy = z[y];
		ans = max(md[zx], md[zy]);
		for (int i = 1; i <= s[zx]; i++)
			for (int j = 1; j <= s[zy]; j++){
				d[a[zx][i]][a[zy][j]] = d[a[zy][j]][a[zx][i]] = d[a[zx][i]][x]+d[a[zy][j]][y]+1;
				ans = max(ans, d[a[zx][i]][a[zy][j]]);
			}
		for (int i = 1; i <= s[zx]; i++){
			a[zy][s[zy]+i] = a[zx][i];
			z[a[zx][i]] = zy;
		}
		s[zy] += s[zx];
		md[zy] = ans;
		cout << ans << endl;
	}
	return 0;
}


