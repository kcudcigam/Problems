#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

const int MAXN = 3e5 + 1;
const int INF = 2147483647;

struct Edge {
	int u;
	int v;
	int w;
	bool operator < (const Edge b) const {
		return w < b.w;
	}
};

int n, m, q;
Edge e[MAXN];
int fa[MAXN];
vector<pair<int, int> >g[MAXN];

vector<pair<int, int> >que[MAXN];
int top[MAXN], len[MAXN], ans[MAXN];
bool vis[MAXN];

int finda(int x) {
	return x == fa[x] ? x : finda(fa[x]);
}

int finds(int x) {
	int tmp = fa[x];
	if(tmp != x) return fa[x] = finds(fa[x]);
	len[x] = max(len[x], len[tmp]);
	return fa[x];
}

void tarjan(int u, int from) {
	for(auto i : g[u]) {
		if(i.first == from) continue;
		tarjan(i.first, u);
		len[u] = i.second;
		fa[i.first] = u;
	}
	for(auto i : que[u]) {
		if(vis[i.first]) {
			top[i.second] = finds(i.first);
			ans[i.second] = max(len[i.first], len[u]);
		}
	}
	vis[u] = true;
}

int main() {
	//freopen("graph.in", "r", stdin);
	//freopen("graph.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}
	sort(e + 1, e + 1 + m);
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		int fu = finda(e[i].u);
		int fv = finda(e[i].v);
		if(fu == fv) continue;
		g[e[i].u].push_back(make_pair(e[i].v, e[i].w));
		g[e[i].v].push_back(make_pair(e[i].u, e[i].w));
		fa[fu] = fv;
	}
	for(int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		que[x].push_back(make_pair(y, i));
		que[y].push_back(make_pair(x, i));
	}
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) tarjan(i, 0);
	for(int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

