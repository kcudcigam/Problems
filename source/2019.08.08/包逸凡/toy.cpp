#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL	
	#define eprintf(...) fprintf(stderr , __VA_ARGS)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<ll , ll> pll;
typedef unsigned long long ull;
#define mp make_pair
#define fi first
#define se second
const int N = 1010;
const int inf = 2e9;

int n , m;
int a[N] , dp[N][N][2];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
} 

int main() {
	
	#ifndef evenbao
	freopen("toy.in" , "r" , stdin);
	freopen("toy.out" , "w" , stdout);
	#endif
	
	read(n); read(m);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j][0] = dp[i][j][1] = inf;
		}
 	}
 	dp[0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (j < i) dp[i][j][0] = min(dp[i - 1][j][1] , dp[i - 1][j][0]);
			dp[i][j][1] = dp[i - 1][j - 1][0] + a[i];		
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (min(dp[n][i][0] , dp[n][i][1]) <= m) ans = i;
	printf("%d\n" , ans);
	
	return 0;
}

