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

const int N = 100000 + 5;

ll n, a[N], ans=LONG_LONG_MIN;

ll solve(ll l, ll r) {
	ll sum=0, res=LONG_LONG_MIN;
	for (reg int i=l; i<=r; ++i) {
		sum+=a[i]; if (sum>res) res=sum;
		if (sum<0) sum=0; 
	}
	return res;
}

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	n=read();
	for (reg int i=1; i<=n; ++i) a[i]=read();
	for (reg int i=1; i<n; ++i)
		ans=max(ans, solve(1, i)+solve(i+1, n));
	printf("%lld\n", ans);
	return 0;
}

