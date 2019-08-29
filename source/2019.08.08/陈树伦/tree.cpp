#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();while(!isdigit(c)) c=getchar();
	int num = 0;while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num;
}
int head[200001], ver[400001], nxt[400001], size;
void addedge(int u, int v) {
	ver[++size] = v, nxt[size] = head[u], head[u] = size;
	ver[++size] = u, nxt[size] = head[v], head[v] = size;
}
int fa[200001], dep[200001];
int dfs0[400001], top;
int first[200001], second[200001];
void dfs(int x) {
	dfs0[first[x] = ++top] = x;
	dep[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dfs(ver[i]);
			dep[x] = max(dep[x], dep[ver[i]] + 1);
		}
	dfs0[second[x] = ++top] = x;
}
int f[200001][20];
int getfa(int u, int k) {
	for (int i = 0; (1<<i) <= k; i++)
		if (k & (1<<i)) u = f[u][i];
	return u;
}
int headl[200001], nxtl[200001];
int c[200001], d[200001];
int bt[400001];
void add(int p) {
	for (int x=p;x<=top;x+=x&-x) bt[x] ^= 1;
}
int query(int p) {
	int ans = 0;
	for (int x=p;x;x-=x&-x) ans ^= bt[x];
	return ans;
}
void init() {
	memset(head, 0, sizeof(head));
	memset(fa, 0, sizeof(fa));
	memset(dep, 0, sizeof(dep));
	memset(headl, 0, sizeof(headl));
	memset(bt, 0, sizeof(bt));
	size = top = 0;
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int t;
	t = read();
	while (t > 0) {
		init();
		int n, k;
		n = read();k=read();
		for (int i = 1; i < n; i++) {
			int u, v;
			u = read();v=read();
			addedge(u, v);
		}
		dfs(1);
		for (int i = 1; i <= n; i++) f[i][0] = fa[i];
		for (int j = 1; j < 20; j++)
			for (int i = 1; i <= n; i++)
				f[i][j] = f[f[i][j-1]][j-1];
		for (int i = 1; i <= n; i++) nxtl[i] = headl[dep[i]], headl[dep[i]] = i;
		for (int i = 1; i <= n; i++) c[i] = read();
		for (int i = 1; i <= n; i++) d[i] = read();
		bool get = 1;
		for (int i = 1; get && i <= n; i++) 
			for (int u = headl[i]; u; u = nxtl[u]) {
				c[u] ^= query(first[u]) ^ query(second[u]);
				if (c[u] ^ d[u]) {
					int ku = getfa(u, k-1);
					if (!ku) {
						cout << "No" << endl;
						get = 0;
						break;
					}
					add(first[ku]), add(first[u]+1);
				}
			}
		if (get) cout << "Yes" << endl;
		--t;
	}
	return 0;
}

