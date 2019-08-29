#include<bits/stdc++.h>
#define MAXN 500010
#define ll long long

using namespace std;

int n , m;
ll a[MAXN];
ll l , r , s , e;
ll jc[MAXN] , pl[MAXN];
ll wzy[MAXN] , byf[MAXN] , xtq[MAXN];
ll x , y , z;
ll ans;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

int main(){

	freopen("sequence.in" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);

	read(n); read(m);
	
	for (int i = 1; i <= m; i++) {
		read(l); read(r); read(s); read(e);
		jc[l] += s;
		wzy[r + 1] += s;
		ll gc = (e - s) / (r - l);
		pl[l + 1] += gc;
		byf[r + 1] += gc;
		xtq[r + 1] += e - s;
	}
	
	for (int i = 1; i <= n; i++) {
		x += jc[i];
		x -= wzy[i];
		y += pl[i];
		if (xtq[i]) {
			y -= byf[i];
			z -= xtq[i];
		}
		z += y;
		a[i] = x + z;
		ans ^= a[i];
	}
	
	cout << ans << endl;

	return 0;
}


