#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10, maxm = maxn << 1;

int n, m, q;
int val[maxn];
int head[maxn], to[maxm], nxt[maxm], tot;

inline void addedge(int u, int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

int main(){
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	for (int k = 1; k <= q; k++){
		int opt, x, y;
		scanf("%d%d", &opt, &x);
		if (!opt){
			int cnt = val[x];
			for (int i = head[x]; i; i = nxt[i]) cnt += val[to[i]];
			printf("%d\n", cnt);
		} else {
			scanf("%d", &y);
			val[x] += y;
		}
	}
	return 0;
}
