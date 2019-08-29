#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	T  f = 1;
	char c = getchar();
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
const int M = 5e5 + 5;
int anc[M], sum[M], val[M], tot;
inline int f(int x) {
	if (anc[x] == x) return x;
	return anc[x] = f(anc[x]);
}
inline void melt(int x, int y) {
	if (f(x) != f(y)) {
		tot ++;
		val[x] += sum[f(x)];
		val[y] += sum[f(y)];
		anc[tot] = tot;
		anc[f(x)] = tot;
		anc[f(y)] = tot;
	}
}
int main(){
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	int n, q;
	read(n); read(q);
	for (int i = 1; i <= n; i ++) {
		anc[i] = i;
	}
	tot = n + 1;
	for (int i = 1; i <= q; i ++) {
		int opt, x, y;
		read(opt); read(x); read(y);
		if (opt == 1) {
			melt(x, y);
		}
		else {
			sum[f(x)] += y;
		}
	}
	for (int i = 1; i < n; i ++) write(val[i] + sum[f(i)], ' ');
	write(val[n] + sum[f(n)], '\n');
	return 0;
}

