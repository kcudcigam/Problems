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

const int N = 300000 + 5, M = 600000 + 5;

struct edge {
	int u, v, nxt;
}e[M]; int head[N], tot=1;

inline void add(int u, int v) {
	e[++tot]=(edge){u, v, head[u]}; head[u]=tot;
	e[++tot]=(edge){v, u, head[v]}; head[v]=tot; 
}

int n, m, Q;
ll a[N], d[N];

int main() {
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	n=read(); m=read(); Q=read();
	for (reg int i=1, x, y; i<=m; ++i) {
		x=read(); y=read();
		add(x, y);
	}
	for (reg int op; Q; --Q) {
		op=read();
		if (op==0) {
			ll x=read();
			for (reg int i=head[x]; i; i=e[i].nxt) {
				if (d[e[i].v]==0) continue;
				for (reg int j=head[e[i].v]; j; j=e[j].nxt) a[e[j].v]+=d[e[i].v];
				a[e[i].v]+=d[e[i].v]; d[e[i].v]=0;
			}
			if (d[x]!=0) {
				for (reg int i=head[x]; i; i=e[i].nxt) a[e[i].v]+=d[x];
				a[x]+=d[x]; d[x]=0;
			}
			printf("%lld\n", a[x]);
		}
		if (op==1) {
			ll x=read(); ll y=read();
			if (y==0) continue;
			d[x]+=y;
		}
	}
	return 0;
}

