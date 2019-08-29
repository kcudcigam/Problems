#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	char c = getchar();
	T f = 1;
	x = 0;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	w(x);
	putchar(c);
}
int a[2][600][600], opt, sum;
bool vis[600][600];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
inline void build(int dep) {
	if (dep == 9) {
//		for (int i = 1; i <= (1 << dep); i ++) {
//			for (int j = 1; j <= (1<< dep); j ++) {
//				if (a[opt][i][j] > 0) cout << ' ';
//				cout << a[opt][i][j] << ' ';
//			}
//			cout << endl;
//		}
		return;
	}
	else {
		opt ^= 1;
		for (int i = 1; i <= 1 << dep; i ++) {
			for (int j = 1; j <= 1 << dep; j ++) {
				a[opt][i * 2 - 1][j * 2 - 1] = a[opt ^ 1][i][j];
				a[opt][i * 2][j * 2 - 1] = a[opt ^ 1][i][j];
				a[opt][i * 2 - 1][j * 2] = a[opt ^ 1][i][j];
				a[opt][i * 2][j * 2] = -a[opt ^ 1][i][j];
			}
		}
		build(dep + 1);
	}
}
inline void dfs(int x, int y) {
	if (x == 1 || y == 1) {
		sum = INT_MAX;
		return;
	} 
	if (sum == INT_MAX) return;
	vis[x][y] = true;
	sum ++;
	for (int i = 0; i < 4; i ++) {
		int xi = x + dx[i], yi = y + dy[i];
		if (!vis[xi][yi] && a[opt][xi][yi] == a[opt][x][y]) dfs(xi, yi);  
		if (sum == INT_MAX) return;
	}
}
int main(){
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	int xi, yi;
	read(xi); read(yi); 
	if (xi <= 100 && yi <= 100) {
		a[0][1][1] = 1;
		build(0);
		dfs(xi + 1, yi + 1);
		if (sum == INT_MAX) printf("infinity\n");
		else write(sum, '\n');
	}
	else {
		printf("infinity\n");
	}
	return 0;
}



