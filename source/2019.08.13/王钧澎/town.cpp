#include<bits/stdc++.h>
#define MAXN 300010
#define MAXLOG 20

using namespace std;

int n;
int f[MAXN];
int fa[MAXN][MAXLOG] , dep[MAXN];
int l[MAXN] , r[MAXN];
int a[MAXN] , b[MAXN];

struct node{
	int nxt , t;
} edge[MAXN << 1];
int cnt , head[MAXN];

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> inline void print(T x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void write(T x) {
	print(x);
	putchar('\n');
}

inline void addedge(int u , int v) {
	edge[++cnt].nxt = head[u];
	edge[cnt].t = v;
	head[u] = cnt;
}

inline void dfs(int u , int wzy) {
	fa[u][0] = wzy; dep[u] = dep[wzy] + 1;
	for (int i = 1; i < MAXLOG; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].t;
		if (v == wzy) continue;
		dfs(v , u);
	}
}

int lca(int x , int y) {
	if (dep[x] < dep[y]) swap(x , y);
	int s = 0;
	for (int i = MAXLOG - 1; i >= 0; i--) {
		if (dep[fa[x][i]] >= dep[y]) {
			x = fa[x][i]; s += (1 << i);
		}
	}
	if (x == y) return s;
	for (int i = MAXLOG - 1; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
			s += (1 << (i + 1));
		}
	}
	return s + 2;
}

inline int fd(int x) {
	if (f[x] == x) return x;
	else return f[x] = fd(f[x]);
}

int main() {

	freopen("town.in" , "r" ,stdin);
	freopen("town.out" , "w" , stdout);

	read(n);
	for (int i = 1; i <= n; i++) f[i] = l[i] = r[i] = i;
	for (int i = 1; i < n; i++) {
		read(a[i]); read(b[i]);
		addedge(a[i] , b[i]);
		addedge(b[i] , a[i]);
	}
	
	dfs(1 , 0);
	
	for (int i = 1; i < n; i++) {
		int x = a[i] , y = b[i];
		int byf = lca(l[fd(x)] , r[fd(y)]) , fsy = lca(r[fd(x)] , l[fd(y)]);
		int xtq = lca(l[fd(x)] , l[fd(y)]) , pcf = lca(r[fd(x)] , r[fd(y)]);
		int aa = l[fd(x)] , bb = r[fd(y)];
		if (fsy > byf) {
			byf = fsy;
			aa = r[fd(x)]; bb = l[fd(y)];
		}
		if (xtq > byf) {
			byf = xtq;
			aa = l[fd(x)]; bb = l[fd(y)];
		}
		if (pcf > byf) {
			byf = pcf;
			aa = r[fd(x)]; bb = r[fd(y)];
		}
		f[x] = fd(y);
		l[fd(y)] = aa; r[fd(y)] = bb;
		write(byf);
	}

	return 0;
}

