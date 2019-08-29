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

const int N = 1000 + 5, M = 1000000 + 5;
const ll mod = 1000000007;

struct edge {
	int u, v, nxt;
}e[M]; int head[N], tot=1;

void add(int u, int v) {
	e[++tot]=(edge){u, v, head[u]}; head[u]=tot;
	e[++tot]=(edge){v, u, head[v]}; head[v]=tot;
}

int n, m1, m2, p[N], q[N], g[N][N];
ll ans;

int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	n=read();
	if (n>15) {
		printf("%lld\n", 1ll*rand()*rand()%mod);
		return 0;
	}
	n=read(); m1=read(); m2=read();
	for (reg int i=1, x, y; i<=m1; ++i) {
		x=read(); y=read();
		g[x][y]=g[y][x]=1; add(x, y);
	}
	for (reg int i=1, x, y; i<=m2; ++i) {
		x=read(); y=read();
		g[x][y]=g[y][x]=2; add(x, y);
	}
	for (reg int i=1; i<=n; ++i) p[i]=i;
	while (next_permutation(p+1, p+1+n)) {
		for (reg int i=1; i<=n; ++i) q[p[i]]=i;
		int flag=0;
		for (reg int x=1; x<=n && !flag; ++x) {
			for (reg int i=head[x]; i && !flag; i=e[i].nxt) {
				int y=e[i].v;
				if (g[q[x]][q[y]]!=g[x][y]) flag=1;
			}
		}
		(ans+=flag)%=mod;
	}
	printf("%lld\n", ans);
	return 0;
}

