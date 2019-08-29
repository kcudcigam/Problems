#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 3e5 + 1;

int n;
vector<int>g[MAXN];

int p, d;

void dfs(int u, int fa, int dis) {
	if(dis > d) {
		p = u;
		d = dis;
	}
	for(int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v, u, dis + 1);
	}
}

int main() {
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
		d = -1;
		dfs(u, 0, 0);
		d = -1;
		dfs(p, 0, 0);
		printf("%d\n", d);
	}
	return 0;
}
