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
const int N = 1e7 + 10;

int n , mod;
int f[N];

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
	
	#ifndef evenbao
	freopen("mod.in" , "r" , stdin);
	freopen("mod.out" , "w" , stdout);
	#endif
	
	int T;
	read(T);
	while (T--) {
		read(n); read(mod);
		f[0] = 0; 
		for (int i = 1; i <= n; ++i) {
			f[i] = 1ll * f[i - 1] * i % mod;
			if (i % 2 == 0) add(f[i] , (1ll * i * (i - 2) % mod + 2ll) % mod);
			else add(f[i] , 1ll * i * (i - 1) % mod);
		} 
		printf("%d\n" , f[n]);
	} 
	
	return 0;
}


