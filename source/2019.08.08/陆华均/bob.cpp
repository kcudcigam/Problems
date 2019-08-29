#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	register T f = 1;
	register char c = getchar();
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
int t[16][16][16][16], hp[15];
bool vis[16][16][16][16];
inline void dfs(int a, int b, int c, int d) {
	vis[a][b][c][d] = true;
	int h = a, i = b, j = c, k = d;
	bool more = false;
	if (a) {
		a --;
		if (a) {
			if (!b) b = hp[a];
			else if (!c) c = hp[a];
			else if (!d) d = hp[a];
		}
		else more = true;
	}
	if (b) {
		b --;
		if (b) {
			if (!a) a = hp[b];
			else if (!c) c = hp[b];
			else if (!d) d = hp[b];		
		}
		else more = true;	
	}
	if (c) {
		c --;
		if (c) {
			if (!a) a = hp[c];
			else if (!b) b = hp[c];
			else if (!d) d = hp[c];		
		}
		else more = true;
	}
	if (d) {
		d --;
		if (d) {
			if (!a) a = hp[d];
			else if (!b) b = hp[d];
			else if (!c) c = hp[d];		
		}
		else more = true;	
	}
	if (more) {
		if (vis[a][b][c][d]) {
			t[a][b][c][d] = 1;
		}
		else if (!t[a][b][c][d]) dfs(a, b, c, d);
		t[h][i][j][k] = t[a][b][c][d];
	}
	else {
		t[h][i][j][k] = 2;
	}
	vis[h][i][j][k] = false;
}
int main(){
	freopen("bob.in", "r", stdin);
	freopen("bob.out", "w", stdout);
	int n;
	read(n);
	for (int i = 1; i <= n - 1; i ++) {
		read(hp[i]);
	}
	int ans = 0;
	for (int i1 = 0; i1 <= n; i1 ++) {
		for (int i2 = 0; i2 <= n; i2 ++) {
			for (int i3 = 0; i3 <= n; i3 ++) {
				for (int i4 = 0; i4 <= n; i4 ++) {
					if (!t[i1][i2][i3][i4] && i1 + i2 + i3 + i4 > 0) dfs(i1, i2, i3, i4);
					ans += (t[i1][i2][i3][i4] == 1);
				}
			}
		}	
	}
	write(ans, '\n');
	return 0;
}


