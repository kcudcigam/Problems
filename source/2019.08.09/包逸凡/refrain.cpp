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
#define mp make_pair
#define fi first
#define se second
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n , M1 , M2 , res;
int a[N] , b[N] , p[N] , pos[N] , X[N] , Y[N];
bool e1[555][555] , e2[555][555];

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
inline int power(int a , int n) {
	int res = 1 , b = a;
	while (n > 0) {
		if (n & 1) res = 1ll * res * b % mod;
		b = 1ll * b * b % mod;
		n >>= 1;
	}
	return res;
}
inline bool ok() {
	for (int i = 1; i <= n; ++i) pos[p[i]] = i;
	for (int i = 1; i <= M1; ++i)
		if (!e1[pos[X[i]]][pos[Y[i]]]) return true;
	for (int i = 1; i <= M2; ++i) 
		if (!e2[pos[X[i + M1]]][pos[Y[i + M1]]]) return true;
	return false;
}
inline void dfs(int dep) {
	if (dep > n) {
		if (ok())
			add(res , 1);
		return;
	} else {
		for (int i = 1; i <= n; ++i) {
			if (!p[i]) {
				p[i] = dep;
				dfs(dep + 1);
				p[i] = 0;
			}
		}
	}
}
inline void sol1() {
	res = 0;
	dfs(1);
	printf("%d\n" , res);
}

int main() {
	
	#ifndef evenbao
	freopen("refrain.in" , "r" , stdin);
	freopen("refrain.out" , "w" , stdout);
	#endif
	
	int caseno;
	read(caseno);
	read(n); read(M1); read(M2);
	for (int i = 1; i <= M1; ++i) {
		read(X[i]);
		read(Y[i]);
		if (caseno <= 6) e1[X[i]][Y[i]] = e1[Y[i]][X[i]] = 1;
	}
	for (int i = 1; i <= M2; ++i) {
		read(X[i + M1]);
		read(Y[i + M1]);
		if (caseno <= 6) e2[X[i + M1]][Y[i + M1]] = e2[Y[i + M1]][X[i + M1]] = 1;
	}
	if (caseno <= 6) {
		sol1();
		return 0;
	}
	if (11 <= caseno && caseno <= 14) {
		int ans = 1;
		for (int i = 1; i <= n; ++i) ans = 1ll * ans * i % mod;
		ans = (ans - n % mod + mod) % mod;
		printf("%d\n" , ans);
		return 0;
	}
	if (7 <= caseno && caseno <= 10) {
		int ans = 1;
		for (int i = 1; i <= n; ++i)	ans = 1ll * ans * i % mod;
		int res = 1;
		for (int i = 1; i <= n - 2 * M1 - 2 * M2; ++i) res = 1ll * res * i % mod;
		res = 1ll * res * power(2 , M1 + M2) % mod;
		for (int i = 1; i <= M1; ++i) res = 1ll * res * i % mod;
		for (int i = 1; i <= M2; ++i) res = 1ll * res * i % mod;
		printf("%d\n" , (ans - res + mod) % mod);
		return 0;
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) ans = 1ll * ans * i % mod;
	printf("%d\n" , ans);
	
	return 0;
}

