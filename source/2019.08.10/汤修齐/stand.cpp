#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 110;

struct node {
	int l, r;
	
	bool operator < (const node &t) const {
		return r == t.r ? l < t.l : r < t.r;
	}
} a[maxn];

int n, m;
int A[6];
bool used[maxn];
vector<int> f[maxn];

inline int X2(int x){
	return x * x;
}

inline LL getc(int x){
	return 1ll * x * A[1] + X2(x) * A[2] + X2(x) * x * A[3] + X2(x) * X2(x) * A[4] + X2(x) * X2(x) * x * A[5];
}

LL dfs(){
	bool b = 0;
	for (int i = 1; i <= n && !b; i++)
		if (!used[i]) b = 1;
	if (!b) return 0;
	vector<int> f[maxn], k;
	for (int i = 1; i <= n; i++){
		if (used[i]) continue;
		for (int j = a[i].l; j <= a[i].r; j++)
			f[j].push_back(i);
	}
	int p = 1;
	for (int i = 2; i <= m; i++)
		if (f[i].size() > f[p].size()) p = i;
	for (int i = 1; i <= m; i++)
		if (f[i].size() == f[p].size()) k.push_back(i);
	LL re = 0;
	for (int i = 0; i < k.size(); i++){
		for (int j = 0; j < f[k[i]].size(); j++) used[f[k[i]][j]] = 1;
		re = max(re, dfs());
		for (int j = 0; j < f[k[i]].size(); j++) used[f[k[i]][j]] = 0;
	}
	return re + getc(f[p].size());
}

int main(){
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 5; i++) scanf("%d", A + i);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].l, &a[i].r);
	printf("%lld\n", dfs());
	return 0;
}
