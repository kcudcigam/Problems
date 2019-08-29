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

const int N = 200000 + 5, M = 1000000 + 5;
const ll inf = LONG_LONG_MAX>>2;

struct edge {
	ll u, v, c, nxt;
}e[M]; int head[N], tot=1;

void add(int u, int v, ll c) {
	e[++tot]=(edge){u, v, c, head[u]}; head[u]=tot;
	e[++tot]=(edge){v, u, c, head[v]}; head[v]=tot;
}

int n, m;
int v[N]; ll d[N];
priority_queue< pair<ll, int> > q;

void dijkstra(int keypos) {
	for (reg int i=1; i<=n; ++i) v[i]=0, d[i]=inf;
	d[1]=0; q.push(make_pair(0, 1));
	while (q.size()) {
		int x=q.top().second; q.pop();
		if (v[x]) continue;
		v[x]=1;
		for (reg int i=head[x]; i; i=e[i].nxt) {
			int y=e[i].v; ll z=e[i].c;
			if (y==keypos) continue; 
			if (d[y]>d[x]+z) {
				d[y]=d[x]+z;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	n=read(); n=read(); m=read();
	ll x, y, z;
	for (reg int i=1; i<=m; ++i) {
		x=read(); y=read(); z=read();
		if (x==y) continue;
		add(x, y, z);
	}
	printf("0");
	for (reg int x=2; x<=n; ++x) {
		dijkstra(x);
		// puts(""); for (reg int j=1; j<=n; ++j) printf("%lld ", d[j]); puts("");
		ll fidis=inf, sedis=inf;
		for (reg int i=head[x]; i; i=e[i].nxt) {
			int y=e[i].v; ll z=e[i].c;
			if (d[y]+z<fidis) sedis=fidis, fidis=d[y]+z;
			else if (d[y]+z<sedis) sedis=d[y]+z;
		}
		printf(" %lld", ((sedis==inf)?(-1):(sedis)));
	}
	printf("\n");
	return 0;
}

