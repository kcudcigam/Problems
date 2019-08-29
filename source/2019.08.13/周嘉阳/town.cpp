#include<bits/stdc++.h>
using namespace std;

#define il inline
const int MAX_N = 300000 + 10;
int Head[MAX_N], Next[MAX_N << 1], V[MAX_N << 1], tot;
int far, mlen, dep[MAX_N];
int n;

il void Add(int u, int v) {
	V[++tot] = v, Next[tot] = Head[u], Head[u] = tot;
}

il void init() {
	memset(dep, 0, sizeof dep);
	mlen = -1;
}

il void dfs(int u, int fa) {
	for (int i = Head[u]; i; i = Next[i]) {
		int v = V[i];
		if (v == fa) continue;
		dep[v] = dep[u] + 1;
		if (dep[v] > mlen) mlen = dep[v], far = v;
		dfs(v, u);
	}
}

int main() {
	freopen("town1.in", "r", stdin);
	freopen("town.out", "w", stdout);
	int u, v;
	scanf("%d", &n);
	for (register int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		Add(u, v), Add(v, u);
		init(), dfs(u, 0);
		init(), dfs(far, 0);
		printf("%d\n", mlen);
	}
	return 0;
}

