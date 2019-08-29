#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &X) {
	X = 0;
	char C = getchar();
	T F = 1;
	for (; !isdigit(C); C = getchar()) if (C == '-')  F = -1;
	for (; isdigit(C); C = getchar()) X = (X << 1) + (X << 3) + (C ^ 48);
	X *= F;
}
template <typename T> inline void w(T X) {
	if (X > 9) w(X / 10);
	putchar(X % 10 + 48);
}
template <typename T> inline void write(T X, char C) {
	if (X < 0) {
		putchar('-');
		X = -X;
	}
	w(X);
	putchar(C);
}
const int mod = 1e9 + 7;
struct info{
	int u, v;
}g[500], h[500];
bool a[500][500], b[500][500], vis[500];
int p[500], n, m1, m2, sum;
inline void dfs(int dep) {
	if (dep == n + 1) {
		for (int i = 1; i <= m1; i ++) {
			if (!a[p[g[i].u]][p[g[i].v]]) {
				sum ++;
				return;
			}
		}
		for (int i = 1; i <= m2; i ++) {
			if (!b[p[h[i].u]][p[h[i].v]]) {
				sum ++;
				return;
			}
		}	
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			p[dep] = i;
			vis[i] = true;
			dfs(dep + 1);
			vis[i] = false;
		}
	}
	p[dep] = 0;
}
inline long long A(long long P) {
	long long sum = 1;
	for (long long i = 2; i <= P; i ++) {
		sum = (sum * i) % mod;
	}
	return sum;
}
int main(){
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	int NUM;
	read(NUM);
	read(n); read(m1); read(m2);
	for (int i = 1; i <= m1; i ++) {
		int x, y;
		read(x); read(y);
		g[i].u = x;
		g[i].v = y;
		a[x][y] = a[y][x] = true;
	}
	for (int i = 1; i <= m2; i ++) {
		int x, y;
		read(x); read(y);
		h[i].u = x;
		h[i].v = y;
		b[x][y] = b[y][x] = true;
	}
	if (NUM <= 6) {
		dfs(1);
		write(sum % mod, '\n');
	}
	else {
		long long x = (1 << m1) % mod, y = (1 << m2) % mod, z = A(n - 2 * m1 - 2 * m2), k = A(n);
		x = (x * A(m1)) % mod;
		y = (y * A(m2)) % mod;
		write((k + mod - (((x * y) % mod) * z) % mod) % mod, '\n');
	}
	return 0;
}


