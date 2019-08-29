#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const ll INF = 1e15;
const int N = 200005;
const int M = 500005;
ll h[N], ne[M<<1], to[M<<1], w[M<<1], tot1;
inline void add(ll x, ll y, ll z) {
	ne[++tot1] = h[x], w[tot1] = z;
	h[x] = tot1, to[tot1] = y;
}

ll read(void) {
	ll x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
int n, m;
priority_queue < pair <ll, int> > q;
ll d[N], v[N], p;
void di(void) {
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[1] = 0;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		for (int i = h[x]; ~i; i = ne[i]) {
			int y = to[i];
			if (i == p || i == (p ^ 1)) continue;
			if (d[y] > d[x] + w[i]) {
				d[y] = d[x] + w[i];
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

int main() {
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	memset(h, -1, sizeof(h));
	tot1 = -1;
	int num = read();
	n = read(), m = read();
	for (int i = 1;i <= m; i++) {
		ll x = read(), y = read(), z = read();
		if (x == y) continue;
		add(x, y, z);
		add(y, x, z);
	}
	di();
	cout << 0 << ' ';
	for (int i = 2;i <= n; i++) {
		ll mi = 0;
		for (int k = h[i]; ~k ;k = ne[k]) {
			p = k;
			di();
			mi = max(mi, d[i]);
		}
		if (mi >= INF) printf ("-1 ");
		else printf ("%lld ", mi);
	}
	return 0;
}
	
	
	
	
	
	
	
