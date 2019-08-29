#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int MAXN = 200010, INF = INT_MAX / 3;
int num, n, m, dis[MAXN], ans[MAXN];
bool inq[MAXN];
int frb[MAXN];
vector<int>v[MAXN], w[MAXN], id[MAXN];
queue<int>q;

void AddEdge(int x, int y, int z, int zz) {
	v[x].push_back(y); w[x].push_back(z); id[x].push_back(zz);
}

void SPFA() {
	for (int i = 1; i <= n; ++i) dis[i] = INF;
	dis[1] = 0; q.push(1); inq[1] = true;
	while (!q.empty()) {
		int x = q.front(); inq[x] = false; q.pop();
		for (int i = 0; i < v[x].size(); ++i) {
			int y = v[x][i], z = w[x][i];
			if (dis[x] + z < dis[y]) {
				dis[y] = dis[x] + z; frb[y] = id[x][i];
				q.push(y); inq[y] = true;
			}
		}
	}
}

void frbSPFA(int now) {
	for (int i = 1; i <= n; ++i) dis[i] = INF;
	dis[1] = 0; q.push(1); inq[1] = true;
	while (!q.empty()) {
		int x = q.front(); inq[x] = false; q.pop();
		for (int i = 0; i < v[x].size(); ++i) {
			if (id[x][i] == frb[now]) continue;
			int y = v[x][i], z = w[x][i];
			if (dis[x] + z < dis[y]) {
				dis[y] = dis[x] + z;
				q.push(y); inq[y] = true;
			}
		}
	}
}

int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	cin >> num >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int x, y, z; cin >> x >> y >> z;
		if (x == y) continue;
		AddEdge(x, y, z, i); AddEdge(y, x, z, i);
	}
	
	SPFA();
	
	for (int i = 2; i <= n; ++i) {
		frbSPFA(i);
		if (dis[i] == INF) ans[i] = -1;
		else ans[i] = dis[i];
	}
	
	for (int i = 1; i < n; ++i) cout << ans[i] << " "; 
	cout << ans[n] <<endl;
	
	return 0;
}
/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/

