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

ll n , k;

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
} 
inline int calc(ll n) {
	int ret = 0;
	while (n > 0) { ++ret; n >>= 1; }
	return ret;
}
inline int CNT(ll n) {
	int ret = 0;
	for (ll i = n; i; i -= i & (-i)) ++ret;
	return ret;
}
int main() { 
 	
 	#ifndef evenbao
 	freopen("glass.in" , "r" , stdin);
 	freopen("glass.out" , "w" , stdout);
	#endif
	 
 	read(n); read(k);
 	int len = calc( n );
	if (CNT(n) <= k) {
		cout<< 0 << '\n';
		return 0;
	}
	ll now = 0 , ans = (1LL << len);
	for (int i = len - 1; i >= 0; --i) {
		if (n & (1LL << i)) {
			--k;
			if (k <= 0) continue;
			now += (1LL << i);
		} else if (k > 0) chkmin(ans , now + (1LL << i));
	}
	cout<< ans - n << '\n';
	
	return 0;
}

