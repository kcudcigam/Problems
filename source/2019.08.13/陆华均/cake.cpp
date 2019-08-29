#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	T f = 1;
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
const int mod = 1000000007;
long long f[500][500];
int n, m;
int main(){
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	read(n); read(m);
	f[1][1] = 1ll;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			for (int k = 1; k < i; k ++) {
				f[i][j] = (f[i][j] + (f[k][j] * f[i - k][j]) % mod) % mod;
			}
			for (int k = 1; k < j; k ++) {
				f[i][j] = (f[i][j] + (f[i][k] * f[i][j - k]) % mod) % mod;
			}
		}
	}
	write(f[n][m], '\n');
	return 0;
}

