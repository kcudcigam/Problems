#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10, maxm = 4e5 + 10;

struct node{
	int x, deep;
	
	node (int x = 0, int deep = 0) : x(x), deep(deep) {
		
	}
	
	bool operator < (const node & t) const {
		return deep < t.deep;
	}
};

int n, k, cnt;
priority_queue<node> q;

int fa[maxn], deep[maxn], C1[maxn], C2[maxn], S[maxn];

int head[maxn], to[maxm], nxt[maxm], tot;

void addedge(int u, int v){
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}

void Init(){
	memset(head, 0, sizeof head);
	tot = 0;
	cnt = 0;
	while (q.size()) q.pop();
}

void dfs(int x, int f, int dep){
	deep[x] = dep;
	fa[x] = f;
	for (int i = head[x]; i; i = nxt[i]){
		int p = to[i];
		if (p != f) dfs(p, x, dep + 1);
	}
}

void work(){
	Init();
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= n; i++) scanf("%d", C1 + i);
	for (int i = 1; i <= n; i++) scanf("%d", C2 + i);
	for (int i = 1; i <= n; i++){
		S[i] = C1[i] != C2[i];
		cnt += S[i];
	}
	for (int i = 1; i <= n; i++)
		if (S[i] && deep[i] >= k) q.push(node(i, deep[i]));
	while (q.size() && cnt){
		node top;
		do {
			top = q.top();
			q.pop();
		} while (!S[top.x] && q.size());
		if (!S[top.x]) break;
		for (int p = top.x, i = 1; i <= k; i++, p = fa[p]){
			S[p] ^= 1;
			if (S[p]){
				cnt++;
				if (deep[p] >= k) q.push(node(p, deep[p]));
			} else cnt--;
		}
	}
	if (!cnt) printf("Yes\n");
	else printf("No\n");
}

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) work();
	return 0;
}
