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

pair <int, int> p[N];
int head[N], ver[M], Next[M], tot;
inline void add(int u, int v)
{
	ver[++tot] = v;
	Next[tot] = head[u];
	head[u] = tot;
}
int n;
int fat[N], Start[N], End[N], dia[N];
namespace D_Set
{
	inline int query(int x)
	{
		if (fat[x] == x) return x;
		fat[x] = query(fat[x]);
		return fat[x];
	}
	
	inline void merge(int x, int y) { fat[query(x)] = query(y); }
}
namespace LCA
{
	int d[N], f[N][25];
	inline void dfs(int x, int fa)
	{
		d[x] = d[fa] + 1;
		f[x][0] = fa;
		
		for (int i = 1; i <= 20; i++) f[x][i] = f[f[x][i - 1]][i - 1];
		
		for (int i = head[x]; i; i = Next[i])
		{
			int v = ver[i];
			if (v != fa) dfs(v, x);
		} 
	}
	inline int query(int x, int y)
	{
		if (d[x] > d[y]) swap(x, y);
		
		for (int i = 20; i >= 0; i--)
		if (d[f[y][i]] >= d[x]) y = f[y][i];
		
		if (x == y) return x;
		
		for (int i = 20; i >= 0; i--)
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
		
		return f[x][0];
	}
	
	inline int dis(int x, int y)
	{
		return d[x] + d[y] - 2 * d[query(x, y)];
	}
	
}

using namespace D_Set;
using namespace LCA;

inline int solve(int dep)
{
	int x = p[dep].first, y = p[dep].second;
	
	x = query(x); y = query(y);
	
	int nowu, nowv, ans, now;
	if (dia[x] > dia[y])
	{
		nowu = Start[x]; nowv = End[x]; ans = dia[x];
	}
	else
	{
		nowu = Start[y]; nowv = End[y]; ans = dia[y];
	}
	
	now = dis(Start[x], Start[y]);
	if (now > ans)
	{
		nowu = Start[x]; nowv = Start[y]; ans = now;
	}
	
	now = dis(Start[x], End[y]);
	if (now > ans)
	{
		nowu = Start[x]; nowv = End[y]; ans = now;
	}
	
	now = dis(End[x], Start[y]);
	if (now > ans)
	{
		nowu = End[x]; nowv = Start[y]; ans = now;
	}
	
	now = dis(End[x], End[y]);
	if (now > ans)
	{
		nowu = End[x]; nowv = End[y]; ans = now;
	}
	
	D_Set::merge(x, y);
	
	Start[query(y)] = nowu;
	End[query(y)] = nowv;
	
	dia[query(y)] = ans;
	
	return ans;
}
int main(){
	freopen ("town.in", "r", stdin);
	freopen ("town.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) fat[i] = Start[i] = End[i] = i, dia[i] = 0;
	
	int u, v;
	for (int i = 1; i < n; i++)
	{
		read(u); read(v);
		p[i] = make_pair(u, v);
		add(u, v); add(v, u);
	}
	
	LCA::dfs(1, 0);
	
	for (int i = 1; i < n; i++)
	printf("%d\n", solve(i));
	
  return 0;
}
