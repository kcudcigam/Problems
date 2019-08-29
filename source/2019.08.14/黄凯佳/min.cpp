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

const int N = 200000 + 5;

ll n, A, B, C, D, a[N], f[N];

ll t[2][N<<2];

void build(int p, int l, int r) {
	if (l==r) { t[0][p]=l; return; }
	int mid=(l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
	t[0][p]=a[t[0][p<<1]]<a[t[0][p<<1|1]]?t[0][p<<1]:t[0][p<<1|1];
}

ll ask1(int p, int l, int r, int L, int R) {
	if (L<=l && r<=R) return t[0][p];
	int mid=(l+r)>>1; ll res1=0, res2=0;
	if (L<=mid) {
		res2=ask1(p<<1, l, mid, L, R);
		res1=a[res1]<a[res2]?res1:res2;
	}
	if (mid<R) {
		res2=ask1(p<<1|1, mid+1, r, L, R);
		res1=a[res1]<a[res2]?res1:res2;
	} 
	return res1;
}

void build2(int p, int l, int r) {
	if (l==r) { t[1][p]=((l==1)?(0):(LONG_LONG_MIN)); return; }
	int mid=(l+r)>>1;
	build2(p<<1, l, mid);
	build2(p<<1|1, mid+1, r);
	t[1][p]=max(t[1][p<<1], t[1][p<<1|1]);
}

void update(int p, int l, int r, int d, ll k) {
	if (l==r) { t[1][p]=k; return; }
	int mid=(l+r)>>1;
	if (d<=mid) update(p<<1, l, mid, d, k);
	else update(p<<1|1, mid+1, r, d, k);
	t[1][p]=max(t[1][p<<1], t[1][p<<1|1]);
}

ll ask2(int p, int l, int r, int L, int R) {
	if (L<=l && r<=R) return t[1][p];
	int mid=(l+r)>>1; ll res=LONG_LONG_MIN;
	if (L<=mid) res=max(res, ask2(p<<1, l, mid, L, R));
	if (mid<R) res=max(res, ask2(p<<1|1, mid+1, r, L, R));
	return res;
}

inline ll g(ll x) { return ((A*x+B)*x+C)*x+D; }

int main() {
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	n=read(); A=read(); B=read(); C=read(); D=read();
	a[0]=LONG_LONG_MAX;
	for (reg int i=1; i<=n; ++i) a[i]=read();
	build(1, 1, n);build2(1, 0+1, n+1);
	for (reg int i=1; i<=n; ++i) {
		f[i]=LONG_LONG_MIN;
		reg int t, j;
		for (t=0, j=ask1(1, 1, n, 1, i); j!=i; t=j, j=ask1(1, 1, n, j+1, i))
			f[i]=max(f[i], ask2(1, 0+1, n+1, t+1, j-1+1)+g(a[j]));
		f[i]=max(f[i], ask2(1, 0+1, n+1, t+1, i-1+1)+g(a[i]));
		update(1, 1, n+1, i+1, f[i]);
	}
	printf("%lld\n", f[n]);
	return 0;
}

