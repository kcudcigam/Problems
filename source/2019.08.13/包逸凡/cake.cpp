#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
	#define eprintf(...) fprintf(stderr , _VA_ARGS)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<int , ll> pil;
typedef pair<ll , ll> pll;
#define MP make_pair
#define fi first
#define se second
const int mod = 1000000007;
const int N = 310;

int n , m;
int dp[N][N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0'; 
	x *= f;
}
inline void add(int &x , int y) {
	x += y;
	while (x >= mod) x -= mod;
}

int main() {
	
	#ifndef IAKIOI
	freopen("cake.in" , "r" , stdin);
	freopen("cake.out" , "w" , stdout);
	#endif
	
	read(n); read(m);
	dp[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k < i; ++k) add(dp[i][j] , 1ll * dp[k][j] * dp[i - k][j] % mod);
			for (int k = 1; k < j; ++k) add(dp[i][j] , 1ll * dp[i][k] * dp[i][j - k] % mod); 
		}
	}
	printf("%d\n" , dp[n][m]);
	
	return 0;
} 
