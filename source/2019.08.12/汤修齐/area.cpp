#include <bits/stdc++.h>

using namespace std;

const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 }, INF = 1e4, maxn = 1e9 + 5e8;

int x, y, cnt;
set<pair<int, int> > vis;

inline bool Get(int x, int y){
	int t = x & y, cnt = 0;
	while (t){
		if (t & 1) cnt++;
		t >>= 1;
	}
	return cnt & 1;
}

inline pair<int, int> mp(int x, int y){
	return make_pair(x, y);
}

void dfs(int x, int y){
	vis.insert(mp(x, y)); cnt++;
	if (cnt >= INF) return;
	bool b = Get(x, y);
	for (int i = 0; i < 4; i++){
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && tx < maxn && ty < maxn && Get(tx, ty) == b && vis.find(mp(tx, ty)) == vis.end()) dfs(tx, ty);
	}
}

int main(){
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	scanf("%d%d", &x, &y);
	dfs(x, y);
	if (cnt >= INF) printf("infinity\n");
	else printf("%d\n", cnt);
	return 0;
}
