#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimise("O2")
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}


long long predelta[500005];
long long presum[500005];

#pragma GCC optimise("O2")
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout); 
	int n, m;
	read(n); read(m);
	for(int i=0; i<m; i++) {
		int l, r; long long s, e; 
		read(l); read(r); read(s); read(e); 
		long long delta = (e-s)/(r-l);
		predelta[l] += delta;
		predelta[r+1] -= (e-s);
		presum[l] += s; presum[r+1] -= s;
	}
	long long cudelta = 0;
	for(int i=0; i<n; i++) {
		cudelta += predelta[i];
		presum[i] += cudelta;
	}
	long long cumXOR = 0, cumSUM = 0;
	for(int i=0; i<=n+1; i++) {
		cumSUM += presum[i];
		cumXOR ^= cumSUM;
	}
	printf("%lld\n",cumXOR);
}
