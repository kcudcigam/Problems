#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	T f = 1;
	char c = getchar();
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
const int M = 2e5 + 5;
long long A, B, C, D, f[2][M], d[M], a[M];
inline long long fun(long long x) {
	return A * x * x * x + B * x * x + C * x + D;
} 
int main(){
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	int n;
	read(n);
	read(A); read(B); read(C); read(D);
	for (int i = 1; i <= n; i ++) {
		read(a[i]);
	}
	for (int i = 2; i <= n; i ++) {
		f[0][i] = max(f[1][i - 1], f[0][i - 1]) + fun(a[i]);
		d[i] = fun(min(a[i], a[i - 1]));
		f[1][i] = fun(d[i]);
		if (fun(d[i - 1]) > f[1][i]) d[i] = d[i - 1];
	}
	write(max(f[0][n], f[1][n]), '\n');
	return 0;
}


