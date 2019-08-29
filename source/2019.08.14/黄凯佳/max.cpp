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

const ll mod = 1000000007;

struct ston {
	ll y, p;
};

inline bool comp(const ston &a1, const ston &a2) {
	return a1.y > a2.y;
}

ll n, m, q, tot[105], c[105][505], l[105], r[105], v[105], ans;
ston a[105][505];

void dfs(ll cnt, ll rat) {
	if (cnt==n+1) {
		ll sum=0;
		for (reg int k=1; k<=q; ++k) {
			ll maxa=0;
			for (reg int i=l[k]; i<=r[k]; ++i) maxa=max(maxa, a[k][v[i]].y);
			(sum+=maxa)%=mod;
		}
		(ans+=sum*rat)%=mod;
		return;
	}
	for (reg int i=1; i<=tot[cnt]; ++i) {
		v[cnt]=i; rat=rat*(1-c[cnt][i-1]+mod)%mod*a[cnt][i].p%mod;
		dfs(cnt+1, rat);
	}
}

int main() {
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	n=read(); m=read(); q=read();
	for (reg int i=1, x, y, p; i<=m; ++i) {
		x=read(); y=read(); p=read();
		a[x][++tot[x]]=(ston){y, p};
	}
	for (reg int i=1; i<=q; ++i) l[i]=read(), r[i]=read();
	for (reg int i=1; i<=n; ++i) sort(a[i]+1, a[i]+tot[i]+1, comp);
	for (reg int i=1; i<=n; ++i)
		for (reg int j=1; j<=tot[i]; ++j) (c[i][j]=c[i][j-1]+a[i][j].p)%=mod;
	dfs(1, 1);
	printf("%lld\n", ans);
	return 0;
}

