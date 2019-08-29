#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200005;
int f[MAXN], sf[MAXN], c[MAXN], p[MAXN], v[MAXN], u[MAXN];
vector <int> d[MAXN];
int T, n, k, x, y;
void dfs(int rt, int dep){
	for (int i = 0; i < d[rt].size(); i++)
		if (d[rt][i] != f[rt]){
			f[d[rt][i]] = rt;
			dfs(d[rt][i], dep+1);
			if (dep >= k && !sf[rt]) sf[rt] = f[sf[d[rt][i]]];
		}
	if (dep >= k && d[rt].size() == 1){
		int fat = rt;
		for (int i = 1; i <= k; i++) fat = f[fat];
		sf[rt] = fat;
	}
	return;
}
bool wrk(int rt, int dep){
	if (d[rt].size() == 1 && rt != 1){
		if (c[rt] != p[rt]){
			if (dep < k) return false;
			v[f[rt]]++;
			u[sf[rt]]++;
		}
		return true;
	}
	for (int i = 0; i < d[rt].size(); i++)
		if (d[rt][i] != f[rt])
			if (!wrk(d[rt][i], dep+1)) return false;
	v[f[rt]] += v[rt]-u[f[rt]];
	if ((c[rt]+v[rt])%2 != p[rt]){
		if (dep < k) return false;
		v[f[rt]]++;
		u[sf[rt]]++;
	}
	return true;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> T;
	for (int I = 1; I <= T; I++){
		memset(v, 0, sizeof(v));
		memset(u, 0, sizeof(u));
		memset(f, 0, sizeof(f));
		memset(sf, 0, sizeof(sf));
		memset(c, 0, sizeof(c));
		memset(p, 0, sizeof(p));
		cin >> n >> k;
		for (int i = 1; i <= n; i++) d[i].clear();
		for (int i = 1; i < n; i++){
			cin >> x >> y;
			d[x].push_back(y);
			d[y].push_back(x);
		}
		dfs(1, 1);
		for (int i = 1; i <= n; i++) cin >> c[i];
		for (int i = 1; i <= n; i++) cin >> p[i];
		if (wrk(1, 1))
			cout << "Yes" << endl; else
			cout << "No" << endl;
	}
	return 0;
}

