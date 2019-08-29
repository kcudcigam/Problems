#include<bits/stdc++.h>
#define N 300010
using namespace std;
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
template <typename T> inline void read(T &n){
	n = 0; T f = 1; char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
int n, cnt;
struct sfl{
	int lp, pp[2];
}te[N << 1];
int dpt[N], head[N], fa[N][21], f[N << 1];
struct edge{
	int u, v, nxt;
}e[N << 1];
inline void aedge(int u, int v){
	++cnt;
	e[cnt].u = u;
	e[cnt].nxt = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
inline void dfs(int u, int fat){
	dpt[u] = dpt[fat] + 1;
	fa[u][0] = fat;
	for (int i = 1; i <= 20; ++i)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt){
		int v = e[i].v;
		if (v != fat)
			dfs(v, u);
	}
}
inline int lca(int x, int y){
	if (dpt[x] < dpt[y]) swap(x, y);
	for (int i = 20; i >= 0; --i)
		if (dpt[fa[x][i]] >= dpt[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; --i)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
inline int ff(int x){
	if (x == f[x]) return x;
	return f[x] = ff(f[x]);
}
int main(){
	FO("town");
	read(n);
	for (int i = 1; i <= n; ++i){
		te[i].lp = 0;
		te[i].pp[0] = te[i].pp[1] = i;
		f[i] = i;
	}
	for (int i = n + 1; i <= n << 1; ++i)
		f[i] = i;
	for (int i = 1; i < n; ++i){
		int a, b;
		read(a), read(b);
		aedge(a, b);
		aedge(b, a);
	}
	dpt[1] = -1;
	dfs(1, 1);
	for (int i = 1; i < n; ++i){
		int u, v;
		u = e[i << 1].u;
		v = e[i << 1].v;
		int fu = ff(u);
		int fv = ff(v);
		int np = n + i;
		f[fu] = f[fv] = np;
		if (te[fu].lp < te[fv].lp) swap(fu, fv);
		te[np].lp = te[fu].lp;
		te[np].pp[0] = te[fu].pp[0];
		te[np].pp[1] = te[fu].pp[1];
		for (int j = 0; j <= 1; ++j)
			for (int k = 0; k <= 1; ++k){
				u = te[fu].pp[j], v = te[fv].pp[k];
				int jl = dpt[u] + dpt[v] - (dpt[lca(u, v)] << 1);
				if (jl > te[np].lp){
					te[np].lp = jl;
					te[np].pp[0] = u;
					te[np].pp[1] = v;
				}
			}
		printf("%d\n", te[np].lp);
	}
	return 0;
}
