#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 2e5 + 10, maxm = 1e6 + 10;
const LL INF = 1e17;

struct node{
	int x; LL c;
	
	node (int x = 0, LL c = 0) : x(x), c(c) {
		
	}
	
	bool operator < (const node &t) const {
		return c > t.c;
	}
};

int Num;
int n, m;
LL d[maxn];
int a[maxn];
bool Can[maxm];
int to[maxm], nxt[maxm], cost[maxm], head[maxn], tot;

void addedge(int u, int v, int c){
	to[++tot] = v;
	cost[tot] = c;
	nxt[tot] = head[u];
	head[u] = tot;
}

void dij(int x, bool k){
	priority_queue<node> q;
	q.push(node(x, 0));
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[x] = 0;
	while (q.size()){
		node top;
		do {
			top = q.top();
			q.pop();
		} while (top.c != d[top.x] && q.size());
		
		for (int i = head[top.x]; i; i = nxt[i]){
			int p = to[i]; LL c = top.c + cost[i];
			if (Can[i]) continue;
			if (c < d[p]){
				d[p] = c;
				if (k) a[p] = i;
				q.push(node(p, c));
			}
		}
	}
}

int main(){
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	scanf("%d%d%d", &Num, &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		if (u != v){
			addedge(u, v, c);
			addedge(v, u, c);
		}
	}
	dij(1, 1);
	printf("0 ");
	/*
	for (int i = 2; i <= n; i++){
		LL Min1 = INF, Min2 = INF;
		for (int j = head[i]; j; j = nxt[j]){
			int p = to[j]; LL c = cost[j] + d[p];
			if (c < Min1){
				Min2 = Min1;
				Min1 = c;
			} else if (c < Min2) Min2 = c;
		}
		printf("%lld ", Min2 == INF ? -1 : Min2);
	}
	*/
	for (int i = 2; i <= n; i++){
		Can[a[i]] = 1;
		Can[(a[i] & 1) ? a[i] + 1 : a[i] - 1] = 1;
		dij(1, 0);
		Can[a[i]] = 0;
		Can[(a[i] & 1) ? a[i] + 1 : a[i] - 1] = 0;
		printf("%lld ", d[i] == INF ? -1 : d[i]);
	}
	printf("\n");
	return 0;
}
