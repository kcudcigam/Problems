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
const int N = 3e5 + 10;
const int MAXLOG = 20;

struct edge {
	int to , w , nxt;
} e[N << 1];

struct info {
	int u , v , w;
} a[N];

int n , tot , m , q;
int fa[N] , depth[N] , father[N][MAXLOG] , mx[N][MAXLOG] , head[N];

inline void chkmax(int &x , int y) {
	x = max(x , y);
}
inline int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
inline void unite(int u , int v) { u = find(u) , v = find(v); fa[u] = v; }
inline void work(int u , int parent) {
	depth[u] = depth[parent] + 1;
	father[u][0] = parent;
	for (int i = 1; i < MAXLOG; ++i) {
		father[u][i] = father[father[u][i - 1]][i - 1];
		mx[u][i] = max(mx[u][i - 1] , mx[father[u][i - 1]][i - 1]);
	}	
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to , w = e[i].w;
		if (v == parent) continue;
		mx[v][0] = w;
		work(v , u);
	}
}
inline int query(int x , int y) {
	int res = 0;
	if (depth[x] > depth[y]) swap(x , y);
	for (int i = MAXLOG - 1; i >= 0; --i) {
		if (depth[father[y][i]] >= depth[x]) {
			chkmax(res , mx[y][i]);
			y = father[y][i];
		}
	}
	if (x == y) return res;
	for (int i = MAXLOG - 1; i >= 0; --i) {
		if (father[x][i] != father[y][i]) {
			res = max(res , max(mx[x][i] , mx[y][i]));
			x = father[x][i] , y = father[y][i];
		}
	}
	return max(res , max(mx[x][0] , mx[y][0]));
}
inline void addedge(int u , int v , int w) {
	++tot;
	e[tot] = (edge){v , w , head[u]};
	head[u] = tot;
}
inline bool cmp(info x , info y) {
	return x.w < y.w;
}

int main() {
	
	#ifndef evenbao
	freopen("graph.in" , "r" , stdin);
	freopen("graph.out" , "w" , stdout);
	#endif
	
	scanf("%d%d%d" , &n , &m , &q);
	for (int i = 1; i <= m; ++i) 
		scanf("%d%d%d" , &a[i].u , &a[i].v , &a[i].w);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	sort(a + 1 , a + m + 1 , cmp);
	for (int i = 1; i <= m; ++i) {
		if (find(a[i].u) != find(a[i].v)) {
			unite(a[i].u , a[i].v);		
			addedge(a[i].u , a[i].v , a[i].w);
			addedge(a[i].v , a[i].u , a[i].w);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (find(i) == i) work(i , 0);
	while (q--) {
		int x , y;
		scanf("%d%d" , &x , &y);
		if (find(x) != find(y)) printf("-1\n");
		else printf("%d\n" , query(x , y));
	}
	
	return 0;
}
