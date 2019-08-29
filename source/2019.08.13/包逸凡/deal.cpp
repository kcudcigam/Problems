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
const int N = 1010;
const int mod = 1000000007;
const int limit = 20005;

int n , X;
int a[N] , b[N] , c[N] , f[2][limit + 5] , g[N][limit + 5] , sum[limit + 5];

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
	x = (x + y) % mod;
}
inline void dec(int &x , int y) {
	x = (x - y + mod) % mod;
}

int main() {
	
	#ifndef evenbao
	freopen("deal.in" , "r" , stdin);
	freopen("deal.out" , "w" , stdout);
	#endif
	
	read(n); read(X); 
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		read(b[i]); 
		read(c[i]);
	}
	f[0][0] = 1;
	ll sm = 0;
	for (int i = 1; i <= n; ++i) {
		int now = i & 1 , pre = now ^ 1;
		sm += (ll)a[i] * c[i];
		for (int j = 0; j <= a[i]; j += 4) sum[j] = sum[j + 1] = sum[j + 2] = sum[j + 3] = 0;
		int lim = min((ll)limit , sm);
		for (int j = 0; j <= lim; j += 4) f[now][j] = f[now][j + 1] = f[now][j + 2] = f[now][j + 3] = 0;
		for (int j = 0; j <= lim; ++j) {
			add(sum[j % a[i]] , f[pre][j]);
			add(f[now][j] , sum[j % a[i]]);
			if (j + (c[i] + 1) * a[i] <= lim) dec(f[now][j + (c[i] + 1) * a[i]] , sum[j % a[i]]);
		}
	}
	g[n + 1][0] = 1;
	sm = 0;
	for (int i = n; i >= 1; --i) {
		for (int j = 0; j <= a[i]; j += 4) sum[j] = sum[j + 1] = sum[j + 2] = sum[j + 3] = 0;
		sm += (ll)a[i] * b[i];
		int lim = min((ll)limit , sm);
		for (int j = 0; j <= lim; j += 4) g[i][j] = g[i][j + 1] = g[i][j + 2] = g[i][j + 3] = 0;
		for (int j = 0; j <= lim; ++j) {
			add(sum[j % a[i]] , g[i + 1][j]);
			add(g[i][j] , sum[j % a[i]]);
			if (j + (b[i] + 1) * a[i] <= lim) dec(g[i][j + (b[i] + 1) * a[i]] , sum[j % a[i]]);
		}
 	}
	int ans = 0 , now = 0;
	for (int i = 0; i <= limit; ++i) {
		// min{ C } > i
		while (now <= n && a[now] <= i) ++now;
		if (now <= n && i + X <= limit) add(ans , 1ll * f[n & 1][i] * g[now][X + i] % mod);
		else break;
	}
 	printf("%d\n" , ans);
	
	return 0;
}

