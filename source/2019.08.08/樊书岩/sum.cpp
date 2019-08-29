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
const int maxn = 500010;
int n, m, arr[maxn];
LL mx[maxn][3][2];
void work() {
	LL max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
	_rep(i, 1, n) {
		_rep(j, 1, 2) {
			_rep(k, 0, 1) {
				mx[i][j][k] = INT_MIN;
			}
		}
	}
	_rep(i, 1, n) {
		mx[i][1][0] = max1;
		mx[i][1][1] = arr[i] + std::max(mx[i - 1][1][1], 0ll);
		if(i >= 4) mx[i][2][0] = max2;
		if(i >= 3) mx[i][2][1] = arr[i] + std::max(mx[i - 1][2][1], max3);
		max1 = std::max(max1, mx[i][1][1]);
		max2 = std::max(max2, mx[i][2][1]);
		if(i < 2) max3 = INT_MIN;
		else max3 = std::max(max3, mx[i - 1][1][1]);
	//	std::cout << mx[i][1][0] << " " << mx[i][1][1] << " " << mx[i][2][0] << " " << mx[i][2][1] << " " << max1 << " " << max2 << " " << max3 << std::endl;
	}
	writesp(std::max(mx[n][2][0], mx[n][2][1]));
}
int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	read(n);
	_rep(i, 1, n) {
		read(arr[i]);
	}
	work();
	return 0;
}
