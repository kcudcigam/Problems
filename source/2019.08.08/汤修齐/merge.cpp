#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

int n, m;
int d[maxn];
int to[maxn], nxt[maxn], head[maxn], tot;
bool vis[maxn];
int val[maxn], ans[maxn];

void Init(int x){
	for (int i = 1; i <= x; i++) d[i] = i;
}

int Find(int x){
	return d[x] == x ? x : d[x] = Find(d[x]);
}

void Join(int x, int y){
	x = Find(x); y = Find(y);
	if (x == y) return;
	d[x] = y;
}

void addedge(int u, int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

void dfs(int x, int c){
	vis[x] = 1; c += val[x];
	ans[x] = c;
	for (int i = head[x]; i; i = nxt[i]){
		int p = to[i];
		dfs(p, c);
	}
}

int main(){
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	scanf("%d%d", &n, &m);
	Init(n + m + 1);
	int point_tot = n;
	for (int i = 1; i <= m; i++){
		int opt, x, y;
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 1){
			x = Find(x); y = Find(y);
			if (x != y){
				point_tot++;
				addedge(point_tot, x);
				addedge(point_tot, y);
				Join(x, point_tot);
				Join(y, point_tot);
			}
		} else val[Find(x)] += y;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(Find(i), 0);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
