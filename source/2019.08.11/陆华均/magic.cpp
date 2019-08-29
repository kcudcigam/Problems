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
const int mod = 998244353;
inline long long f(long long x, long long k) {
	long long sum = 1;
	while(k) {
		if (k & 1) sum = (sum * x) % mod;
		x = (x * x) % mod;
		k >>= 1;
	}
	return sum;
}
int main(){
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	long long n;
	read(n);
	string s;
	cin >> s;
	long long ans = f(26, n);
	long long len = s.size();
	if (len == n) {
		write(ans - 1, '\n');
	}
	else {
		long long num = (f(26, n - len) + ((f(26, n - len - 1) * 25) * len) % mod) % mod;
		write((ans - num + mod) % mod, '\n');
	}
	return 0;
}


