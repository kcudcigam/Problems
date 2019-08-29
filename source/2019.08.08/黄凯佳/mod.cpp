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

const int N = 10000000 + 5;

ll T, n, p, f[N];

void solve() {
	scanf("%lld%lld", &n, &p);
	f[1]=0%p; f[2]=2%p;
	for (reg int i=3; i<=n; ++i) {
		f[i]=(i*f[i-1]%p+i*(i-1)%p)%p;
		if (i%2==0) f[i]=(f[i]-(i-2)+p)%p;
	}
	printf("%lld\n", f[n]);
}

int main() {
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	for (scanf("%lld", &T); T; --T) solve();
	return 0;
}

