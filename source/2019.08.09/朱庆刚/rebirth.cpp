#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;

const int MAXN = 2e5 + 5;

struct node {
	int p;
	int d;
	bool operator < (const node &b) const {
		return d > b.d;
	}
};

int n, m, dis[MAXN];
vector<pair<int, int> >g[MAXN];
pair<int, int>pre[MAXN];

void dij() {
	memset(dis, 0x7f, sizeof(dis));
	priority_queue<node>q;
	bool vis[MAXN] = {0};
	dis[1] = 0;
	q.push((node){1, 0});
	for(;!q.empty();) {
		node now = q.top();
		q.pop();
		if(vis[now.p]) continue;
		vis[now.p] = true;
		for(int i = 0; i < (int)g[now.p].size(); ++i) {
			node next = (node){g[now.p][i].first, dis[now.p] + g[now.p][i].second};
			if(next.d < dis[next.p]) {
				dis[next.p] = next.d;
				pre[next.p] = make_pair(now.p, g[now.p][i].second);
				q.push(next);
			}
		}
	}
}

int main() {
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	int fuck;
	scanf("%d", &fuck);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int ra, rb, rc;
		scanf("%d %d %d", &ra, &rb, &rc);
		if(ra == rb) continue;
		g[ra].push_back(make_pair(rb, rc));
		g[rb].push_back(make_pair(ra, rc));
	}
	dij();
	printf("0 ");
	for(int i = 2; i <= n; ++i) {
		if(g[i].size() == 1) {
			printf("-1 ");
			continue;
		}
		int res = 2147483647;
		bool flag = false;
		for(int j = 0; j < (int)g[i].size(); ++j) {
			if(!flag && pre[i] == g[i][j]) {
				continue;
				flag = true;
			}
			res = min(res, dis[g[i][j].first] + g[i][j].second);
		}
		printf("%d ", res);
	}
	return 0;
}

