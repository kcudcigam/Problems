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
long long ans = 0;
int n, sum, a[1001], b[1001], c[1001], d[10001], dlen, e[10001], elen, g[5001][20001]; 
inline void dfs(int dep, int num, int mini) {
	if (dep == dlen + 1) {
		if (num >= sum) ans += g[elen][num - sum]; 
		ans %= 1000000007;
		return;
	}
	if (num + d[dep] < sum + mini) dfs(dep + 1, num + d[dep], min(mini, d[dep]));
	dfs(dep + 1, num, mini);
}
int main(){
	read(n); read(sum);
	for (int i = 1; i <= n; i ++) {
		read(a[i]); read(b[i]); read(c[i]);
		for (int j = 1; j <= b[i]; j ++) d[++ dlen] = a[i];
		for (int j = 1; j <= c[i]; j ++) e[++ elen] = a[i];
	}
	g[0][0] = 1;
	for (int i = 1; i <= elen; i ++) {
		for (int j = 0; j <= 5000; j ++) {
			g[i][j] = g[i - 1][j] ;
			if (j > e[i]) g[i][j] += g[i - 1][j - e[i]];
		}
	}
	dfs(1, 0, 1e9);
	write(ans, '\n');
 	return 0;
}

