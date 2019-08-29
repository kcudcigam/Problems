#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define LD long double
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)

using namespace std;

template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {if(c == '-') f = -f;}
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int n, m, w[1010];
int dp[1010][1010][2]; 
int main() {
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	read(n); read(m);
	
	_rep(i, 1, n) read(w[i]);
	
	_rep(i, 0, n) {
		_rep(j, 0, n) {
			dp[i][j][0] = dp[i][j][1] = INT_MAX / 2;
		}
	}
	dp[0][0][0] = 0;
	_rep(i, 1, n) {
		_rep(j, 1, (i + 1) / 2) {
			dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][0]);
			if(dp[i - 1][j - 1][0] + w[i] <= m) dp[i][j][1] = dp[i - 1][j - 1][0] + w[i];
		}
	}
	
//	_rep(i, 1, n) {
//		_rep(j, 1, n) {
//			printf("dp(%d, %d, 0) = %d\n", i, j, dp[i][j][0]);
//			printf("dp(%d, %d, 1) = %d\n", i, j, dp[i][j][1]);
//		}
//	}
	int ans = 0;
	_rep(j, 1, n) {
		if(dp[n][j][0] != INT_MAX / 2) ans = max(ans, j);
		if(dp[n][j][1] != INT_MAX / 2) ans = max(ans, j);
	}
	
	write(ans); puts("");
	return 0;
}

