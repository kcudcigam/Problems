#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 2e5 + 5;
const int M = 4e5 + 5;
int head[N], ver[M], Next[M], tot;
inline void addedge(int u, int v)
{
	ver[++tot] = v;
	Next[tot] = head[u];
	head[u] = tot;
}
inline void add(int u, int v) { addedge(u, v); addedge(v, u); }
int n, k;
bool c[N], d[N];
int fa[N], dep[N];
int Dfs_Rank[N], sum;
bool vis[N];
inline void start()
{
	memset(head, 0, sizeof(head));
	memset(ver, 0, sizeof(ver));
	memset(Next, 0, sizeof(Next));
	memset(dep, 0, sizeof(dep));
	memset(vis, 0, sizeof(vis));
	memset(Dfs_Rank, 0, sizeof(Dfs_Rank));
	tot = sum = 0;
}
inline void FindLeaf(int Root)
{
	Dfs_Rank[++sum] = Root;
	vis[Root] = 1;
	for (int i = head[Root]; i; i = Next[i])
	{
		int v = ver[i];
		if (!vis[v])
		{
			fa[v] = Root;
			dep[v] = dep[Root] + 1;
			FindLeaf(v);
		}
	}
}
inline void modify(int Root)
{
	for (int i = 1; i <= k; i++)
	{
		c[Root] ^= 1;
		Root = fa[Root];
	}
}
inline void doit()
{
	read(n); read(k);
	if (k == 1) { puts("Yes"); return; }
	dep[1] = 1;
	int u, v;
	for (int i = 1; i <= n - 1; i++)
	{
		read(u); read(v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) read(c[i]);
	for (int i = 1; i <= n; i++) read(d[i]);
	FindLeaf(1);
	
	for (int i = n; i >= 1; i--)
	{
		if (dep[Dfs_Rank[i]] < k) break;
		if (c[Dfs_Rank[i]] != d[Dfs_Rank[i]]) modify(Dfs_Rank[i]);
	}
	
	for (int i = 1; i <= n; i++)
	if (c[i] != d[i])
	{
		puts("No");
		return;
	}
	puts("Yes");
}
int main(){
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);
	int T;
	read(T);
	while (T--)
	{
		start();
		doit();
	}
  return 0;
}
