#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
	#define eprintf(...) fprintf(stderr , _VA_ARGS)
#else
	#define eprintf(...) 42
#endif

typedef long long LL;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int , int> pii;
typedef pair<LL , int> pli;
typedef pair<int , LL> pil;
typedef pair<LL , LL> pll;
#define MP make_pair
#define fi first
#define se second
const int N = 5e5 + 10;
const LL INF = 1e18;

int n;
LL ans;
LL a[N] , f[N] , g[N] , pref[N] , suf[N];

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
	freopen("sum.in" , "r" , stdin);
	freopen("sum.out" , "w" , stdout);
	#endif
	
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	pref[0] = -INF;
	for (int i = 1; i <= n; ++i) {
		f[i] = max(a[i] , f[i - 1] + a[i]);
		pref[i] = pref[i - 1];
		chkmax(pref[i] , f[i]);	
	}
	suf[n + 1] = -INF;
	for (int i = n; i >= 1; --i) {
		g[i] = max(a[i] , g[i + 1] + a[i]);
		suf[i] = suf[i + 1];
		chkmax(suf[i] , g[i]);	
	}
	LL ans = -INF;
 	for (int i = 1; i <= n - 1; ++i) 
 		chkmax(ans , pref[i] + suf[i + 1]);
 	printf("%lld\n" , ans);
 	
	return 0;
}

