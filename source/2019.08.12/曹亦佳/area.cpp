#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int a[260][260], nx, ny, cnt;
bool flag, f[260][260];

void pls(int n) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				for (int l = 1; l <= n; ++l)
					a[(i - 1) * n + k][(j - 1) * n + l] = a[i][j] * a[k][l];
}

void dfs(int x, int y) {
//	cerr << x << " " << y << endl;
	if (x == 1 || y == 1) {flag = true; return;}
	if (f[x][y]) return;
	f[x][y] = true; cnt++;
	for (int i = 0; i < 4; ++i)
		if (a[x + dx[i]][y + dy[i]] == a[x][y]) {
			dfs(x + dx[i], y + dy[i]);
			if (flag) return;
		}
}

int main(){
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	cin >> nx >> ny; nx++; ny++;
	if (nx > 100 || ny > 100){cout << "infinity" << endl; return 0;}
	
	a[1][1] = 1; a[1][2] = 1; a[2][1] = 1; a[2][2] = -1;
	pls(2); pls(4); pls(16);
	
	flag = false;
	dfs(nx, ny);
	if (flag) cout << "infinity" << endl;
	else cout << cnt << endl;

	return 0;
}



