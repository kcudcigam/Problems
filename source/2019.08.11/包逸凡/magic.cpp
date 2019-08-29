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
typedef pair<ll , ll> pll;
#define MP make_pair
#define fi first
#define se second
const int mod = 998244353;
const int N = 1e6 + 10;

char s[N];

inline int qpow(int a , ll n) {
	ll b = a , res = 1;
	while (n > 0) {
		if (n & 1) res = 1ll * res * b % mod;
		b = 1ll * b * b % mod;
		n >>= 1;
	} 
	return res;
}

signed main() {
	
	#ifndef evenbao
	freopen("magic.in" , "r" , stdin);
	freopen("magic.out" , "w" , stdout);
	#endif
	
	ll n;
	scanf("%lld%s" , &n , s + 1);
	int m = strlen(s + 1);
	if (n == m) {
		cout<< (qpow(26 , n) - 1 % mod + mod) % mod << '\n';
		return 0;
	}
	int ans = qpow(26 , n);
	ans = (ans - 1ll * 25 * qpow(26 , n - m - 1) % mod * m % mod + mod) % mod;
	ans = (ans - qpow(26 , n - m) % mod + mod) % mod;
	cout<< ans << '\n';
	
	return 0;
}
