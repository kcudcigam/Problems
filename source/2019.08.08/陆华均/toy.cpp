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
int f[1005][1005][2], a[1005];
int main(){
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	int n, m;
	read(n); read(m);
	for (int i = 1; i <= n; i ++) {
		read(a[i]);
	}
	for (int i = 0; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			f[i][j][0] = f[i][j][1] = INT_MAX >> 1;
		}
	}
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			f[i][j][0] = min(f[i - 1][j][1], f[i - 1][j][0]);
			f[i][j][1] = f[i - 1][j - 1][0] + a[i];
		}
		f[i][i][1] = f[i - 1][i - 1][0] + a[i];
	}
	int ans;
	if (f[n][n][1] <= m) ans = n;
	else {
		for (int i = n - 1; i >= 1; i --) 
			if (min(f[n][i][0], f[n][i][1]) <= m) {
				ans = i;
				break;
			}	
	}
	write(ans, '\n');
	return 0;
}

