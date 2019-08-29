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

struct node {
	ll t, x, y;
}a[N];

inline bool comp(const node &a1, const node &a2) {
	return a1.t < a2.t;
}

ll n, dx, dy, dt;

void solve() {
	n=read();
	for (reg int i=1; i<=n; ++i)
		a[i].t=read(), a[i].x=read(), a[i].y=read();
	//sort(a+1, a+1+n, comp);
	for (reg int i=1; i<=n; ++i) {
		dx=abs(a[i].x-a[i-1].x); dy=abs(a[i].y-a[i-1].y);
		dt=a[i].t-a[i-1].t;
		if (dt<dx+dy || (dt-(dx+dy))%2!=0) {
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
	return;
}

int main() {
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	for (reg int T=read(); T; --T) solve();
	return 0;
}

