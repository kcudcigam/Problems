#include <bits/stdc++.h>
using namespace std;

#define reg register
#define ll long long

inline ll read() {
	reg ll x=0, f=1; reg char c;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	do x=x*10+c-48; while (isdigit(c=getchar()));
	return x*f;
}

int n, m, Q;

namespace solu1 {

const int N = 300000 + 5, M = 600000 + 5;
const ll inf = LONG_LONG_MAX>>2;

struct edge {
	ll u, v, c, nxt;
}e[M]; int head[N], tot=1;

inline void add(int u, int v, ll c) {
	e[++tot]=(edge){u, v, c, head[u]}; head[u]=tot;
	e[++tot]=(edge){v, u, c, head[v]}; head[v]=tot;
}

int t, v[N];
ll d[N];

priority_queue< pair<ll, int> > q;
ll dijkstra(int s, int t) {
	while (q.size()) q.pop();
	for (reg int i=1; i<=n; ++i) v[i]=0, d[i]=inf;
	d[s]=0; q.push(make_pair(0, s));
	while (q.size()) {
		int x=q.top().second; q.pop();
		if (v[x]) continue;
		v[x]=1;
		if (x==t) break;
		for (reg int i=head[x]; i; i=e[i].nxt) {
			int y=e[i].v; ll z=e[i].c;
			if (d[y]>max(d[x], z)) {
				d[y]=max(d[x], z);
				q.push(make_pair(-d[y], y));
			}
		}
	}
	if (d[t]==inf) return -1;
	else return d[t];
}

int main() {
	int x, y; ll z;
	for (reg int i=1; i<=m; ++i) {
		x=read(); y=read(); z=read();
		add(x, y, z);
	} 
	for (; Q; --Q) {
		x=read(); y=read();
		printf("%lld\n", dijkstra(x, y));
	}
	return 0;
}

}

namespace solu2 {

const int N = 300000 + 5, M = 600000 + 5;

struct edge {
	ll u, v, c, nxt;
}e[M]; int head[N], tot=1;

inline void add(int u, int v, ll c) {
	e[++tot]=(edge){u, v, c, head[u]}; head[u]=tot;
	e[++tot]=(edge){v, u, c, head[v]}; head[v]=tot;
}

struct node {
	ll u, v, c;
}ed[M];

inline bool comp(const node &ed1, const node &ed2) {
	return ed1.c < ed2.c;
}

int t, c[N], fa[N], d[N], f[N][20];
ll g[N][20];

inline int get(int x) {
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}

void kruskal() {
	sort(ed+1, ed+1+m, comp);
	for (reg int i=1; i<=n; ++i) fa[i]=i;
	for (reg int i=1; i<=m; ++i) {
		if (get(ed[i].u)==get(ed[i].v)) continue;
		fa[get(ed[i].u)]=get(ed[i].v);
		add(ed[i].u, ed[i].v, ed[i].c);
	}
}

queue<int> q;
void bfs(int r) {
	q.push(r); d[r]=1;
	while (q.size()) {
		int x=q.front(); q.pop();
		c[x]=r;
		for (reg int i=head[x]; i; i=e[i].nxt) {
			int y=e[i].v; ll z=e[i].c;
			if (d[y]) continue;
			d[y]=d[x]+1; f[y][0]=x; g[y][0]=z;
			for (reg int j=1; j<=t; ++j)
				f[y][j]=f[f[y][j-1]][j-1],
				g[y][j]=max(g[y][j-1], g[f[y][j-1]][j-1]);
			q.push(y);
		}
	}
}

ll ask(int x, int y) {
	if (c[x]!=c[y]) return -1;
	if (d[x]>d[y]) swap(x, y);
	ll res=0;
	for (reg int i=t; i>=0; --i)
		if (d[f[y][i]]>=d[x]) res=max(res, g[y][i]), y=f[y][i];
	if (x==y) return res;
	for (reg int i=t; i>=0; --i)
		if (f[x][i]!=f[y][i]) res=max(res, max(g[x][i], g[y][i])), x=f[x][i], y=f[y][i];
	return max(res, max(g[x][0], g[y][0]));
}

int main() {
	t=log(n)/log(2)+1;
	int x, y; ll z;
	for (reg int i=1; i<=m; ++i) {
		x=read(); y=read(); z=read();
		ed[i]=(node){x, y, z};
	}
	kruskal();
	for (reg int i=1; i<=n; ++i) if (!d[i]) bfs(i); 
	for (; Q; --Q) {
		x=read(); y=read();
		printf("%lld\n", ask(x, y));
	}
	return 0;
}

}

int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	n=read(); m=read(); Q=read();
	if (n<=1000) solu1::main();
	else solu2::main();
	return 0;
}

