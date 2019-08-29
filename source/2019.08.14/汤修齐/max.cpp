#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 1e5 + 10, MOD = 1e9 + 7;

struct node {
	int x; LL val, p;
	
	void Read(){
		scanf("%d%lld%lld", &x, &val, &p);
	}
	
	bool operator < (const node &t) const {
		return x < t.x;
	}
} a[maxn], v[maxn];

int n, m, q;
LL f[maxn], d[maxn], len;

bool cmp(node a, node b){
	return a.val > b.val;
}

LL dp(){
	memset(f, 0, sizeof f);
	memset(d, 0, sizeof d);
	d[0] = 1;
	for (int i = 1; i <= len; i++){
		f[i] = (f[i - 1] + a[i].val * d[i - 1] % MOD * a[i].p) % MOD;
		d[i] = d[i - 1] * (1 - a[i].p + MOD) % MOD;
	}
	return f[len];
}

int Find(int x){
	int l = 0, r = m, mid;
	while (l + 1 < r){
		mid = l + r >> 1;
		if (v[mid].x >= x) r = mid;
		else l = mid;
	}
	return l;
}

int main(){
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++) v[i].Read();
	sort(v + 1, v + m + 1);
	LL ans = 0;
	for (int i = 1; i <= q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		len = 0;
		for (int j = Find(l) + 1; v[j].x <= r && j <= m; j++) a[++len] = v[j];
		sort(a + 1, a + len + 1, cmp);
		ans = (ans + dp()) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
