#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10, maxm = maxn << 1, A = 20;

int n;
int U[maxn], V[maxn];
int anc[maxn][A], deep[maxn];
int head[maxn], to[maxm], nxt[maxm], tot;
int d[maxn], s[maxn];
int L[maxn], R[maxn], D[maxn];

inline void addedge(int u, int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

void dfs(int x, int fa, int dep){
	anc[x][0] = fa; deep[x] = dep;
	for (int i = 1; i < A; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	
	for (int i = head[x]; i; i = nxt[i]){
		int p = to[i];
		if (p != fa) dfs(p, x, dep + 1);
	}
}

inline int lca(int x, int y){
	if (deep[x] > deep[y]) swap(x, y);
	
	for (int i = A - 1; i >= 0; i--)
		if (deep[anc[y][i]] >= deep[x]) y = anc[y][i];
	
	if (x == y) return x;
	
	for (int i = A - 1; i >= 0; i--)
		if (anc[x][i] != anc[y][i]){
			x = anc[x][i];
			y = anc[y][i];
		}
	return anc[x][0];
}

void Init(int x){
	for (int i = 1; i <= x; i++){
		d[i] = i;
		s[i] = 1;
	}
}

int Find(int x){
	return d[x] == x ? x : d[x] = Find(d[x]);
}

inline int Join(int x, int y){
	x = Find(x); y = Find(y);
	if (s[x] < s[y]) swap(x, y);
	s[x] += s[y]; d[y] = x;
	return x;
}

int main(){
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		scanf("%d%d", U + i, V + i);
		addedge(U[i], V[i]);
		addedge(V[i], U[i]);
	}
	dfs(1, 0, 1);
	Init(n);
	for (int i = 1; i <= n; i++){
		L[i] = R[i] = i;
		D[i] = 1;
	}
	int S[2], E[2];
	for (int i = 1; i < n; i++){
		int u = Find(U[i]), v = Find(V[i]);
		int p = Join(U[i], V[i]);
		S[0] = L[u]; S[1] = R[u];
		E[0] = L[v]; E[1] = R[v];
		if (D[u] > D[v]){
			D[p] = D[u]; L[p] = L[u]; R[p] = R[u];
		} else {
			D[p] = D[v]; L[p] = L[v]; R[p] = R[v];
		}
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++){
				int c = deep[S[j]] + deep[E[k]] - 2 * deep[lca(S[j], E[k])];
				if (c > D[p]){
					D[p] = c;
					L[p] = S[j];
					R[p] = E[k];
				}
			}
		printf("%d\n", D[p]);
	}
	return 0;
}
