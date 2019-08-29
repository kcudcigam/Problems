#include<bits/stdc++.h>
#define inf 1000000000000000000
#define ll long long 
#define pr pair<ll, int>
using namespace std;
int read(){
	char c=getchar();while(!isdigit(c))c=getchar();
	int num=0;while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num;
}
void write(long long num){if(num<0)putchar('-'),num=-num;if(num>=10)write(num/10);putchar(num%10+'0');} 
int head[200001], ver[1000001], edge[1000001], nxt[1000001], sz;
int headt[200001], vert[1000001], edget[1000001], nxtt[1000001], szt;
void addedge(int u, int v, int w) {
	ver[++sz] = v, edge[sz] = w, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, edge[sz] = w, nxt[sz] = head[v], head[v] = sz;
}
void addedget(int u, int v, int w) {
	vert[++szt] = v, edget[szt] = w, nxtt[szt] = headt[u], headt[u] = szt;
	vert[++szt] = u, edget[szt] = w, nxtt[szt] = headt[v], headt[v] = szt;
}
int fa[200001];
ll dis[200001];
void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	priority_queue<pr, vector<pr >, greater<pr > > pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if (dis[u] != d) continue;
		for (int i = head[u]; i; i = nxt[i])
			if (dis[ver[i]] > dis[u] + edge[i]) {
				dis[ver[i]] = dis[u] + edge[i];
				fa[ver[i]] = u;
				pq.push(make_pair(dis[ver[i]], ver[i]));
			} 
	}
}
int dep[200001], size[200001], son[200001];
void dfs1(int x) {
	size[x] = 1;
	for (int i = headt[x]; i; i = nxtt[i])
		if (fa[x] != vert[i]) {
			dep[vert[i]] = dep[x] + 1;
			dfs1(vert[i]);
			size[x] += size[ver[i]];
			if (size[vert[i]] > size[son[x]]) son[x] = vert[i];
		}
}
int top[200001], id[200001], rk[200001], now;
void dfs2(int s, int t) {
	++now;
	top[s] = t;
	id[s] = now;
	rk[now] = s;
	if (son[s]) dfs2(son[s], t);
	for (int i = headt[s]; i; i = nxtt[i])
		if (vert[i] != fa[s] && vert[i] != son[s])
			dfs2(vert[i], vert[i]);
}
struct node {
	int l, r;
	long long dat, num;
}nd[1000001];
void build(int p, int l, int r) {
	nd[p].l = l, nd[p].r = r;
	nd[p].dat = inf, nd[p].num = inf;
	if (l == r) return;
	int mid = (l + r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
}
void pushdown(int p) {
	if (nd[p].dat == inf) return;
	nd[p*2].dat = min(nd[p*2].dat, nd[p].dat);
	nd[p*2].num = nd[p*2].dat-dis[rk[nd[p*2].l]];
	nd[p*2+1].dat = min(nd[p*2+1].dat, nd[p].dat);
	nd[p*2+1].num = nd[p*2+1].dat-dis[rk[nd[p*2+1].l]];
	nd[p].dat = inf;
}
void change(int p, int l, int r, long long d) {
	if (nd[p].l >= l && nd[p].r <= r) {nd[p].dat=min(nd[p].dat, d);nd[p].num=nd[p].dat-dis[rk[nd[p].l]]; return;}
	pushdown(p);
	int mid = (nd[p].l + nd[p].r) / 2;
	if (l <= mid) change(p * 2, l, r, d);
	if (r > mid) change(p * 2 + 1, l, r, d);
	nd[p].num = min(nd[p*2].num, nd[p*2+1].num);
}
long long query(int p, int u) {
	if (nd[p].l == nd[p].r) return nd[p].num==inf?-1:nd[p].num;
	pushdown(p);
	int mid = (nd[p].l + nd[p].r) / 2;
	if (u <= mid) return query(p * 2, u);
	else return query(p * 2 + 1, u); 
}
void modify(int u, int v, int w) {
	long long d = dis[u] + dis[v] + w;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) swap(u, v);
		change(1, id[top[v]], id[v], d);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	if (u == v) return;
	change(1, id[u] + 1, id[v], d);
}
int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	int Num = read();
	int n, m;
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x, y, len;
		x = read(), y = read(), len = read();
		addedge(x, y, len);
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++) addedget(i, fa[i], dis[i] - dis[fa[i]]);
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	for (int u = 1; u <= n; u++)
		for (int i = head[u]; i; i = nxt[i])
			if ((fa[u]!=ver[i]&&fa[ver[i]]!=u)||(edge[i]!=dis[u]-dis[fa[u]]&&edge[i]!=dis[ver[i]]-dis[fa[ver[i]]]))
				modify(u, ver[i], edge[i]);
	putchar('0'), putchar(' ');
	for (int i = 2; i <= n; i++) write(query(1, id[i])), putchar(' ');
	putchar('\n');
	return 0;
}
