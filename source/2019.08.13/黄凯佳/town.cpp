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

struct node {
	int u, v;
}ed[M];

struct edge {
	int u, v, nxt;
}e[M]; int head[N], tot=1;

inline void add(int u, int v) {
	e[++tot]=(edge){u, v, head[u]}; head[u]=tot;
	e[++tot]=(edge){v, u, head[v]}; head[v]=tot;
}

int n, rt, siz[N], maxpart[N], d[N], maxlen[N], f[N], fa[N], bc[N];

inline int get(int x) {
	return bc[x]==x?x:bc[x]=get(bc[x]);
}

void findroot(int x, int fa) {
	siz[x]=1;
	for (reg int i=head[x]; i; i=e[i].nxt) {
		int y=e[i].v;
		if (y==fa) continue;
		findroot(y, x);
		siz[x]+=siz[y]; maxpart[x]=max(maxpart[x], siz[y]); 
	}
	maxpart[x]=max(maxpart[x], n-siz[x]);
	if (maxpart[x]<maxpart[rt]) rt=x;
}

void markdepth(int x, int fa) {
	d[x]=d[fa]+1;
	for (reg int i=head[x]; i; i=e[i].nxt) {
		int y=e[i].v;
		if (y==fa) continue;
		markdepth(y, x);
	}
}

int main() {
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	n=read();
	for (reg int i=1, x, y; i<n; ++i) {
		x=read(); y=read();
		add(x, y); ed[i]=(node){x, y};
	}
	maxpart[0]=0x3f3f3f3f;
	findroot(1, 0); markdepth(rt, 0); //printf("%d\n", rt);
	memset(head, 0, sizeof(head)); tot=1;
	for (reg int i=1; i<=n; ++i) bc[i]=i;
	for (reg int k=1, res, x, y; k<n; ++k) {
		x=ed[k].u; y=ed[k].v; 
		res=max(maxlen[get(x)], maxlen[get(y)]);
		int len1=0, len2=0;
		for (reg int u=x, son=0, len=0; u; ++len, son=u, u=fa[u]) {
			len1=max(len1, len);
			for (reg int i=head[u]; i; i=e[i].nxt) {
				int v=e[i].v;
				if (v==son || v==fa[u]) continue;
				len1=max(len1, len+f[v]+1);
			}
		}
		for (reg int u=y, son=0, len=0; u; ++len, son=u, u=fa[u]) {
			len2=max(len2, len);
			for (reg int i=head[u]; i; i=e[i].nxt) {
				int v=e[i].v;
				if (v==son || v==fa[u]) continue;
				len2=max(len2, len+f[v]+1);
			}
		}
		res=max(res, len1+len2+1);
		printf("%d\n", res);
		if (d[x]<d[y]) swap(x, y);
		fa[x]=y, bc[get(x)]=get(y); add(x, y);
		maxlen[get(y)]=res;
		for (; fa[x]; x=fa[x]) {
			if (f[fa[x]]>=f[x]+1) break;
			f[fa[x]]=f[x]+1;
		}
	}
	return 0;
}

