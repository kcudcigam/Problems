#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10, maxm = maxn << 1, A = 20;

struct node {
	int u, v, c;
	
	void Read(){
		scanf("%d%d%d", &u, &v, &c);
	}
	
	bool operator < (const node &t) const {
		return c < t.c;
	}
} e[maxn];

int n, m, q;
int d[maxn], s[maxn];
int head[maxn], to[maxm], nxt[maxm], cost[maxm], tot;
int anc[maxn][A], Max[maxn][A], deep[maxn];

inline void addedge(int u, int v, int c){
	to[++tot] = v;
	cost[tot] = c;
	nxt[tot] = head[u];
	head[u] = tot;
}

void Init(int n){
	for (int i = 1; i <= n; i++){
		d[i] = i;
		s[i] = 1;
	}
}

int Find(int x){
	return x == d[x] ? x : d[x] = Find(d[x]);
}

void Join(int x, int y){
	x = Find(x); y = Find(y);
	if (s[x] < s[y]) swap(x, y);
	s[x] += s[y]; d[y] = x;
}

void kru(){
	sort(e + 1, e + m + 1);
	Init(n);
	for (int i = 1; i <= m; i++)
		if (Find(e[i].u) != Find(e[i].v)){
			Join(e[i].u, e[i].v);
			addedge(e[i].u, e[i].v, e[i].c);
			addedge(e[i].v, e[i].u, e[i].c);
		}
}

void dfs(int x, int fa, int val, int dep){
	deep[x] = dep; anc[x][0] = fa; Max[x][0] = val;
	for (int i = 1; i < A; i++){
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
		Max[x][i] = max(Max[x][i - 1], Max[anc[x][i - 1]][i - 1]);
	}
	
	for (int i = head[x]; i; i = nxt[i]){
		int p = to[i];
		if (p != fa) dfs(p, x, cost[i], dep + 1);
	}
}

inline int lca(int x, int y){
	if (deep[x] > deep[y]) swap(x, y);
	
	int re = 0;
	for (int i = A - 1; i >= 0; i--)
		if (deep[anc[y][i]] >= deep[x]){
			re = max(re, Max[y][i]);
			y = anc[y][i];
		}
	
	if (x == y) return re;
	
	for (int i = A - 1; i >= 0; i--)
		if (anc[x][i] != anc[y][i]){
			re = max(re, max(Max[x][i], Max[y][i]));
			x = anc[x][i];
			y = anc[y][i];
		}
	
	return max(re, max(Max[x][0], Max[y][0]));
}

int main(){
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++) e[i].Read();
	kru();
	for (int i = 1; i <= n; i++)
		if (!deep[i]) dfs(i, 0, 0, 1);
	for (int i = 1; i <= q; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", Find(u) == Find(v) ? lca(u, v) : -1);
	}
	return 0;
}
