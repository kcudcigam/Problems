#include<bits/stdc++.h>
using namespace std;

template<typename tn> void read(tn &a) {
	tn f = 1, x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 300010;
int n, m, q, cnt, blng[MAXN], ans;
bool vis[MAXN];
vector<int>v[MAXN], w[MAXN];

void dfs(int x) {
	blng[x] = cnt;
	for (int i = 0; i < v[x].size(); ++i) {
		int y = v[x][i];
		if (!blng[y]) dfs(y);
	}
}

void dfs1(int x, int mx, int e) {
//	cerr << x << " " << mx << " " << e << endl;
	if (x == e) {ans = min(ans, mx); return;}
	vis[x] = true;
	for (int i = 0; i < v[x].size(); ++i) {
		int y = v[x][i], z = w[x][i];
		if (vis[y] || z > ans) continue;
		dfs1(y, max(mx, z), e);
	}
	vis[x] = false;
}

void AddEdge(int x, int y, int z) {
	v[x].push_back(y); w[x].push_back(z);
}

int main(){
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	read(n); read(m); read(q);
	for (int i = 1; i <= m; ++i) {
		int x, y, z; read(x); read(y); read(z);
		AddEdge(x, y, z); AddEdge(y, x, z);
	}

	for (int i = 1; i <= n; ++i) if (!blng[i]) {cnt++; dfs(i);}
	
	for (int i = 1; i <= q; ++i) {
		int x, y; read(x); read(y);
		if (blng[x] != blng[y]) {cout << "-1" << endl; continue;}
		ans = INT_MAX; dfs1(x, -1, y); cout << ans << endl;
	}

	return 0;
}



