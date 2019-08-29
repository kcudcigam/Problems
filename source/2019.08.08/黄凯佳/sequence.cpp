#include <bits/stdc++.h>
using namespace std;

#define reg register
#define ll long long

inline ll read() {
	reg ll x=0, f=1; reg char c;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	do { x=x*10+c-48; } while (isdigit(c=getchar()));
	return x*f; 
}

const int N = 500000 + 5;

int n, m;
ll t[N], ans, a[N];

void add(ll x, ll y) {
	for (; x<=n; x+=x&-x) t[x]+=y;
}

ll ask(ll x) {
	ll res=0; for (; x; x-=x&-x) res+=t[x]; return res;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n=read(); m=read();
	ll l, r, s, e, d;
	for (reg int i=1; i<=m; ++i) {
		l=read(); r=read(); s=read(); e=read();
		if (l!=r) d=(e-s)/(r-l);
		else d=0;
		a[l]+=s; a[r+1]-=e; 
		add(l+1, d); add(r+1, -d);
	}
	for (reg int i=1; i<=n; ++i) a[i]+=(a[i-1]+ask(i));
	for (reg int i=1; i<=n; ++i) ans^=a[i];
	printf("%lld\n", ans);
	return 0;
}

