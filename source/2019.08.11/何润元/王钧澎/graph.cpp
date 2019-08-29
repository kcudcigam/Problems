#include<bits/stdc++.h>
#define MAXN 300010
#define MAXLOG 20

using namespace std;

int n , m , q;
struct node{
	int x , y , z;
} edge[MAXN];
struct EDGE{
	int nxt , t , va;
} e[MAXN << 1];
int _head[MAXN] , cnt;
int f[MAXN] , ans[MAXN][MAXLOG] , dep[MAXN] , fa[MAXN][MAXLOG];

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > x ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> inline void print(T x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
} 
template <typename T> inline void write(T x) {
	if (x < 0) {x = -x; putchar('-'); }
	print(x);
	putchar('\n');
}

bool cmp(node a , node b) {
	return a.z < b.z;
}

inline int zz(int x) {
	if (f[x] == x) return x;
	else return f[x] = zz(f[x]);
}

inline void addedge(int u , int v , int va) {
	e[++cnt] = (EDGE){_head[u] , v , va};
	_head[u] = cnt;
}

inline void dfs(int u , int Fa , int v) {
	fa[u][0] = Fa; ans[u][0] = v; dep[u] = dep[Fa] + 1;
	for (int i = 1; i < MAXLOG; i++) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
		ans[u][i] = max(ans[u][i - 1] , ans[fa[u][i - 1]][i - 1]);
	}
	for (int i = _head[u]; i; i = e[i].nxt) {
		int y = e[i].t;
		if (y == Fa) continue;
		dfs(y , u , e[i].va);
	}
}

inline int lca(int x , int y) {
	if (dep[x] < dep[y]) swap(x , y);
	for (int i = MAXLOG - 1; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {x = fa[x][i]; y = fa[y][i]; }
	}
	return fa[x][0];
}

inline int fd(int x , int y) {
	if (dep[x] < dep[y]) swap(x , y);
	int s = 0;
	for (int i = MAXLOG - 1; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) {
			chkmax(s , ans[x][i]);
			x = fa[x][i];
		}
	}
	return s;
}

int main() {

	freopen("graph.in" , "r" , stdin);
	freopen("graph.out" , "w" , stdout);

	read(n); read(m); read(q);
	for (int i = 1; i <= m; i++) {
		int x , y , z;
		read(x); read(y); read(z);
		edge[i] = (node){x , y , z};
	}
	
	sort(edge + 1 , edge + m + 1 , cmp);
	
	for (int i = 1; i <= n; i++) f[i] = i;
	
	for (int i = 1; i <= m; i++) {
		int x = edge[i].x , y = edge[i].y , z = edge[i].z;
		if (zz(x) != zz(y)) {
			f[x] = zz(y);
			addedge(x , y , z);
			addedge(y , x , z);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (f[i] == i) {
			dfs(i , 0 , 0);
		}
	}
	
	while(q--) {
		int x , y;
		read(x); read(y);
		if (zz(x) != zz(y)) {
			write(-1);
			continue;
		}
		int LCA = lca(x , y);
		int lans = max(fd(x , LCA) , fd(y , LCA));
		write(lans);
	}

	return 0;

}

