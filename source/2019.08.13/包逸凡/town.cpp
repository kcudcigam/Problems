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
const int INF = 2e9;
const int N = 3e5 + 10;
const int MAXLOG = 20;

int n;
vector< int > a[N];
int dep[N] , father[N][MAXLOG] , fa[N] , sz[N] , P[N][2] , d[N] , u[N] , v[N];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}
inline void work(int u , int par) {
	dep[u] = dep[par] + 1;
	father[u][0] = par;
	for (int i = 1; i < MAXLOG; ++i)
		father[u][i] = father[father[u][i - 1]][i - 1];
	for (unsigned i = 0; i < a[u].size(); ++i) {
		int v = a[u][i];
		if (v == par) continue;
		work(v , u);
	}
}
inline int lca(int x , int y) {
	if (dep[x] > dep[y]) swap(x , y);
	for (int i = MAXLOG - 1; i >= 0; --i)
		if (dep[father[y][i]] >= dep[x]) y = father[y][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; --i)
		if (father[x][i] != father[y][i])
			x = father[x][i] , y = father[y][i];
	return father[x][0];
}
inline int calc(int u , int v) {
	if (u == 0 || v == 0) return -INF;
	else return dep[u] + dep[v] - 2 * dep[lca(u , v)];
}
inline int getroot(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = getroot(fa[x]);
}
inline void merge(int u , int v) {
	u = getroot(u) , v = getroot(v);
	if (u == v) return;
	if (sz[u] > sz[v]) swap(u , v);
	fa[u] = v; sz[v] += sz[u];
	int new_x = P[v][0] , new_y = P[v][1];
	if (calc(P[u][0] , P[u][1]) > d[v]) {
		d[v] = calc(P[u][0] , P[u][1]);
		new_x = P[u][0] , new_y = P[u][1];
	}
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
		if (calc(P[u][i] , P[v][j]) > d[v]) {
			d[v] = calc(P[u][i] , P[v][j]);
			new_x = P[u][i] , new_y = P[v][j];
		}
	P[v][0] = new_x; P[v][1] = new_y;
	d[v] = calc(new_x , new_y);
	return;
} 

int main() { 
	
	#ifndef evenbao
	freopen("town.in" , "r" , stdin);
	freopen("town.out" , "w" , stdout);
	#endif
	
	read(n);
	for (int i = 1; i < n; ++i) {
		read(u[i]); read(v[i]);
		a[u[i]].push_back(v[i]);
		a[v[i]].push_back(u[i]);
	}
	work(1 , 0);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;	
		P[i][0] = i; P[i][1] = 0;
	}
	for (int i = 1; i < n; ++i) {
		int x = u[i] , y = v[i];
		merge(x , y);
		printf("%d\n" , d[getroot(x)]);	
	}
	
	return 0;
}

