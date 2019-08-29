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

const int N = 500000 + 5;

struct edge {
	int u, v, nxt;
}e[N<<1]; int head[N], tot=1;

void add(int u, int v) {
	e[++tot]=(edge){u, v, head[u]}; head[u]=tot;
}

ll n, m, fa[N], mark[N], a[N];

int get(int x) {
	if (fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}

void dfs(int x) {
	a[x]+=mark[x];
	for (reg int i=head[x]; i; i=e[i].nxt) {
		a[e[i].v]+=a[x];
		dfs(e[i].v);
	}
}

int main() {
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	n=read(); m=read();
	int q, x, y;
	for (reg int i=1; i<=n; ++i) fa[i]=i;
	for (reg int i=1; i<=m; ++i) {
		q=read(); x=read(); y=read();
		if (q==1) {
			if (x>y) swap(x, y);
			if (get(x)==get(y)) continue;
			add(get(x), get(y)); mark[get(y)]-=mark[get(x)];
			fa[get(y)]=get(x);
		}
		if (q==2) mark[get(x)]+=y;
	}
	for (reg int i=1; i<=n; ++i) if (get(i)==i) dfs(i);
	for (reg int i=1; i<=n; ++i) printf("%lld ", a[i]);
	return 0;
}

