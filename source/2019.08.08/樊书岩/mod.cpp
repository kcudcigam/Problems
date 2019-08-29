#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {
		if(c == '-') f = -f;
	}
	for(; isdigit(c); c = getchar()) {
		x = x * 10 + c - '0';
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {
	write(x); putchar(sp);
}
int q, n;
LL ans, p;
LL solve(int n) {
	ans = 0;
	_rep(i, 2, n) {
		ans = i * ans % p;
		if(i & 1) {
			ans = (ans + 1ll * i * i % p - i % p) % p;
		} else {
			ans = (ans + 1ll * (i - 1) * (i - 2) % p + 1ll * i % p) % p;
		}
	}
	return ans;
}
int main() {
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	read(q);
	while(q--) {
		read(n); read(p);
		writesp(solve(n));
	}
	return 0;
}

