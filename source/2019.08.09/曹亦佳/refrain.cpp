#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int num, n, m1, m2, a[110][110], b[110];
vector <pair<int, int> >c1, c2;

void baoli() {
	for (int i = 1; i <= m1; ++i) {
		int x, y; cin >> x >> y;
		a[x][y] = a[y][x] = 1;
		c1.push_back(make_pair(x, y));
	}
	for (int i = 1; i <= m2; ++i) {
		int x, y; cin >> x >> y;
		a[x][y] = a[y][x] = 2;
		c2.push_back(make_pair(x, y));
	}
	
	for (int i = 1; i <= n; ++i) b[i] = i;
	int ans = 0;
	while (next_permutation(b + 1, b + n + 1)) {
		bool flag = false;
		for (int i = 0; i < m1; ++i) {
			int x = c1[i].first, y = c1[i].second;
			if (a[b[x]][b[y]] != 1) {ans = (ans + 1) % mod; flag = true; break;}
		}
		if (flag) continue;
		for (int i = 0; i < m2; ++i) {
			int x = c2[i].first, y = c2[i].second;
			if (a[b[x]][b[y]] != 2) {ans = (ans + 1) % mod; flag = true; break;}
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	cin >> num >> n >> m1 >> m2;
	if (n == 1 || n == 2) cout << "0" << endl;
	else baoli();

	return 0;
}
/*
3
3 1 1
1 2
2 3
*/

