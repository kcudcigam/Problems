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
const int N = 3e5 + 5;
const int M = 6e5 + 5;
struct Path
{
	int u, v, w;
}p[N];
inline bool comp(Path x, Path y) { return x.w < y.w; }
int n, m, q;
int fa[N];
inline int Find(int x)
{
	if (x == fa[x]) return x;
	fa[x] = Find(fa[x]);
	return fa[x];
}

int head[N], ver[M], Edge[M], Next[M], tot;
inline void add(int u, int v, int w)
{
	ver[++tot] = v;
	Edge[tot] = w;
	Next[tot] = head[u];
	head[u] = tot;
}

int d[N], Rank[N], f[N][34], val[N][34], sum;
inline void dfs(int x, int fat)
{
	d[x] = d[fat] + 1;
	Rank[x] = sum;
	
	for (int i = 1; i <= 30; i++)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
		val[x][i] = max(val[x][i - 1], val[f[x][i - 1]][i - 1]);
	}
	
	for (int i = head[x]; i; i = Next[i])
	{
		int v = ver[i];
		if (v != fat)
		{
			f[v][0] = x;
			val[v][0] = Edge[i];
			dfs(v, x);
		}
	}
}
inline int solve(int x, int y)
{
	if (d[x] > d[y]) swap(x, y);
	
	int ans = 0;
	
	for (int i = 30; i >= 0; i--)
	if (d[f[y][i]] >= d[x]) ans = max(ans, val[y][i]), y = f[y][i];
	
	if (x == y) return ans;
	
	for (int i = 30; i >= 0; i--)
	if (f[x][i] != f[y][i])
	{
		ans = max(ans, max(val[x][i], val[y][i]));
		x = f[x][i];
		y = f[y][i];
	}
	return max(ans, max(val[x][0], val[y][0]));
}
int main(){
	freopen ("graph.in" ,"r", stdin);
	freopen ("graph.out", "w", stdout);
	read(n); read(m); read(q);
	
	for (int i = 1; i <= n; i++) fa[i] = i;
	
	for (int i = 1; i <= m; i++)
	{
		read(p[i].u); read(p[i].v); read(p[i].w);
	}
	
	sort(p + 1, p + m + 1, comp);
	
	int now = 1;
	
	for (int i = 1; i <= n; i++)
	{
		while (Find(p[now].u) == Find(p[now].v) && now <= m) now++;
		
		if (now > m) break;
		
		add(p[now].u, p[now].v, p[now].w); add(p[now].v, p[now].u, p[now].w);
		
		fa[Find(p[now].u)] = Find(p[now].v);
		
		now++;
	}
	for (int i = 1; i <= n; i++)
	if (!d[i])
	{
		sum++;
		dfs(i, 0);
	}
	int x, y;
	for (int i = 1; i <= q; i++)
	{
		read(x); read(y);
		if (Rank[x] != Rank[y]) puts("-1");
		else printf("%d\n", solve(x, y));
	}
  return 0;
}
