#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

int rd(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 3e5 + 10;
int n, h[N], dis[N], xx[N], yy[N], tot, f[N];
int dep[N], fa[N], siz[N], tp[N], son[N];
struct edge{int nxt, v;} e[N << 1];
struct ddd{int x, y;} a[N];

inline void add(int x, int y) 
	{e[++tot] = (edge) {h[x], y}, h[x] = tot;}

int _find(int x) {return x == f[x] ? x : f[x] = _find(f[x]);}

void dfs(int x) {
	siz[x] = 1, dep[x] = dep[fa[x]] + 1;
	for (int i = h[x], v; i; i = e[i].nxt) if (!dep[v = e[i].v]) {
		fa[v] = x, dfs(v), siz[x] += siz[v];
		if (siz[v] > siz[son[x]]) son[x] = v;
	}
}

void dfs2(int x, int y) {
	tp[x] = y;
	if (son[x]) dfs2(son[x], y);
	for (int i = h[x], v; i; i = e[i].nxt)
		if ((v = e[i].v) != fa[x] && v != son[x]) dfs2(v, v);
}

inline int lca(int x, int y) {
	for (; tp[x] ^ tp[y]; x = fa[tp[x]])
		if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
	return dep[x] > dep[y] ? y : x;
}

inline int dist(int x, int y) {
	int lc;
	lc = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[lc];
}

inline void MM(int x, int y) {
	int xa, xb, ya, yb, disa = 0, disb;
	
	xb = xx[x], yb = xx[y], disb = dist(xb, yb);
	if (disa < disb) xa = xb, ya = yb, disa = disb;
	
	xb = yy[x], yb = xx[y], disb = dist(xb, yb);
	if (disa < disb) xa = xb, ya = yb, disa = disb;
	
	xb = xx[x], yb = yy[y], disb = dist(xb, yb);
	if (disa < disb) xa = xb, ya = yb, disa = disb;
	
	xb = yy[x], yb = yy[y], disb = dist(xb, yb);
	if (disa < disb) xa = xb, ya = yb, disa = disb;
	
	if (disa > dis[x]) dis[x] = disa, xx[x] = xa, yy[x] = ya;
	if (dis[y] > dis[x]) dis[x] = dis[y], xx[x] = xx[y], yy[x] = yy[y];
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n= rd();
	fox (i, 2, n) {
		a[i].x = rd(), a[i].y = rd();
		add(a[i].x, a[i].y), add(a[i].y, a[i].x);
	}
	
	fox (i, 1, n) f[i] = i, xx[i] = yy[i] = i;
	dfs(1), dfs2(1, 1);
	int x, y, lc;
	fox (i, 2, n) {
		x = _find(a[i].x), y = _find(a[i].y);
		if (dep[x] > dep[y]) swap(x, y);
		f[x] = y;
		MM(x, y);
		printf("%d\n", dis[x]);
	}
	return 0;
}
