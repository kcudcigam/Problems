#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n; ll x;
vector <pair <int, int>> ans;
int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	read(x), n = 64;
	for (int i = 2; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		ans.emplace_back(i, j);
	for (int i = 63; i >= 2; i--) {
		if (x & 1) ans.emplace_back(1, i);
		x >>= 1;
	}
	printf("%d %llu\n", n, ans.size());
	for (auto x : ans) printf("%d %d\n", x.first, x.second);
	return 0;
}
