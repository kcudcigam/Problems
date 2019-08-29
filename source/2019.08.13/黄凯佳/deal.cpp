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

const int N = 1000 + 5, M = 10000 + 5, mod = 1000000007;

ll n, X, ans, a[N], b[N], c[N], f[2][M];

vector<ll> v; 

void dfs(int id, ll sum, ll rest, ll sma) {
	if (rest+sum<X) return;
	if (sum-sma>=X) return; 
	if (sum>X) {
		(ans+=f[n&1][sum-X])%=mod;
		return;
	}
	if (id==n+1) return;
	for (reg int i=0; i<=b[id] && sum+a[id]*i-((sma==0&&i>0)?a[i]:sma)<X; ++i)
		dfs(id+1, sum+a[id]*i, rest-a[id]*b[id], (sma==0&&i>0)?a[i]:sma);
}

int main() {
	freopen("deal.in", "r", stdin);
	freopen("deal.out", "w", stdout);
	n=read(); X=read();
	for (reg int i=1; i<=n; ++i) a[i]=read(), b[i]=read(), c[i]=read();
	f[0][0]=1;
	for (reg int i=1; i<=n; ++i) {
		for (reg int k=1; k<=c[i]; ++k)
			for (reg int j=a[n]; j>=a[i]*k; --j) (f[i&1][j]+=f[(i&1)^1][j-a[i]*k])%=mod;
	}
	ll tmp=0;
	for (reg int i=1; i<=n; ++i) tmp+=a[i]*b[i];
	dfs(1, 0, tmp, 0);
	printf("%lld\n", ans);
	return 0;
}

