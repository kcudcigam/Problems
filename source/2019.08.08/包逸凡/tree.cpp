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

#define rint register int

const int N = 2e5 + 10;
const int MAXLOG = 20;

struct edge {
	int to , nxt;
} e[N << 2];

int n , k , tot , flag , timer;
int son[N] , head[N] , depth[N] , father[N][MAXLOG] , c[N] , d[N] , tag[N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
} 
inline void addedge(int u , int v) {
	++tot;
	e[tot] = (edge){v , head[u]};
	head[u] = tot;
}
inline void dfs(int u , int par) {
	depth[u] = depth[par] + 1;
	father[u][0] = par;
	for (rint i = 1; i < MAXLOG; ++i)
		father[u][i] = father[father[u][i - 1]][i - 1];
	for (rint i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == par) continue;
		dfs(v , u);
	}
}
inline int get(int u , int k) {
	for (rint i = MAXLOG - 1; i >= 0; --i)
		if (k & (1 << i)) u = father[u][i];
	return u;
}
inline void work(int u , int par) {
	for (rint i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == par) continue;
		work(v , u);
		tag[u] ^= tag[v];
	}	
	if (!flag) return;
	if ((c[u] ^ tag[u]) != d[u]) {
		if (depth[u] >= k) {
			tag[u] ^= 1;
			tag[get(u , k)] ^= 1;
		} else flag = false;
	}
}

int main() {
	
	#ifndef evenbao
	freopen("tree.in" , "r" , stdin);
	freopen("tree.out" , "w" , stdout);
	#endif
	
	int T;
	read(T);
	while (T--) {
		read(n); read(k);
		for (rint i = 0; i <= n; i += 5) {
			head[i] = head[i + 1] = head[i + 2] = head[i + 3] = head[i + 4] = 0;
			tag[i] = tag[i + 1] = tag[i + 2] = tag[i + 3] = tag[i + 4] = 0;
		}
		for (rint i = 0; i <= tot; i += 5) {
			e[i].nxt = e[i + 1].nxt = e[i + 2].nxt = e[i + 3].nxt = e[i + 4].nxt = 0;
		}
		tot = 0;
		for (rint i = 1; i < n; ++i) {
			int x , y;
			read(x); read(y);
			addedge(x , y);
			addedge(y , x);
		}
		for (rint i = 1; i <= n; ++i) read(c[i]);
		for (rint i = 1; i <= n; ++i) read(d[i]);
		depth[0] = 0;
		dfs(1 , 0);
		flag = true;
		work(1 , 0);
		if (flag) puts("Yes");
		else puts("No");
	}
	
	return 0;
}

