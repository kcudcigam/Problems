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
#define mp make_pair
#define fi first
#define se second
const int N = 255;
const int INF = 2e9;
const int LIMIT = 5e5 + 5;

struct segment {
	int l , r;
} seg[N];

int n , m , timer , res , groups;
int f[N] , s[N] , delta[N] , a[6] , val[N] , used[N] , now[N] , use[N] , g[N][N];

bool operator < (segment a , segment b) {
	return a.l < b.l;
}

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}
inline int calc(int x) {
	return a[1] * x + a[2] * x * x + a[3] * x * x * x + a[4] * x * x * x * x + a[5] * x * x * x * x * x;
} 
inline int get() {
	int ret = 0;
	for (int i = 1; i <= m; ++i) {
		ret += calc(use[i]);
	}
	return ret;
}
inline void work(int depth) {
	if (depth > n)  {
		++timer;
		chkmax(res , get());
		if (timer * m > LIMIT) {
			printf("%d\n" , res);
			exit(0);
		}
		return;		
	} else {
		for (int i = seg[depth].l; i <= seg[depth].r; ++i) {
			++use[i];
			work(depth + 1);
			--use[i];
		}		
	}	
}
inline int getv() {
	int res = 0;
	for (int i = 1; i <= groups; ++i) {
		int mx = -INF , mn = INF;
		for (int j = 1; j <= g[i][0]; ++j) {
			chkmax(mx , seg[g[i][j]].l);
			chkmin(mn , seg[g[i][j]].r);
		}
		if (mx > mn) return -INF;
		res += val[g[i][0]];
	}
	return res;
}
inline void dfs(int depth) {
	if (depth > n) {
		chkmax(res , getv());
		return;
	} else {
		for (int i = 1; i <= groups; ++i) {
			g[i][++g[i][0]] = depth;
			dfs(depth + 1);
			--g[i][0];
		}
		++groups; 
		g[groups][g[groups][0] = 1] = depth;
		dfs(depth + 1);
		--g[groups][0]; --groups;
	}
}
inline void solve_15() {
	dfs(1);
	printf("%d\n" , res);
}

int main() {
	
	#ifndef evenbao
	freopen("stand.in" , "r" , stdin);
	freopen("stand.out" , "w" , stdout);
	#endif
	
	read(n); read(m);
	for (int i = 1; i <= 5; ++i) read(a[i]);
	for (int i = 0; i <= n; ++i) val[i] = calc(i);
	for (int i = 1; i <= n; ++i) {
		read(seg[i].l); 
		read(seg[i].r);	
	}
	int L = -INF , R = INF;
	for (int i = 1; i <= n; ++i) {
		chkmax(L , seg[i].l);
		chkmin(R , seg[i].r);
	}
	if (L <= R) {
		printf("%d\n" , val[n]);
		return 0;
	}
	if (n <= 10 && m <= 10) {
		solve_15();
		return 0;
	} 
	while (true) {
		for (int i = 1; i <= m; ++i) delta[i] = 0;
		bool ok = false;
		for (int i = 1; i <= n; ++i) {
			if (used[i]) continue;
			++delta[seg[i].l];
			--delta[seg[i].r + 1];
			ok |= true;
		}	
		if (!ok) break;
		for (int i = 1; i <= m; ++i) delta[i] += delta[i - 1];
		for (int i = 1; i <= m; ++i) s[i] = delta[i] + now[i];
		int mx = 0 , pos = 0;
		for (int i = 1; i <= m; ++i) {
			if (s[i] > mx && delta[i] > 0) {
				mx = s[i];
				pos = i;
			}
		}
		now[pos] = s[pos];
		for (int i = 1; i <= n; ++i)
			if (seg[i].l <= pos && seg[i].r >= pos) used[i] = true;
	} 
	res = 0;
	for (int i = 1; i <= m; ++i) res += val[now[i]];
	work(1);
	
	return 0;
}

