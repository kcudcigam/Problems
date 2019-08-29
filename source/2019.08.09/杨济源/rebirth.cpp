#include<bits/stdc++.h>
#define LL long long
#define pli pair <LL, int>
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
const int M = 1e6 + 5;
const LL INF = 1e18;
int head[N], ver[M], Edge[M], Next[M], tot;
inline void add(int u, int v, int w)
{
	ver[++tot] = v;
	Edge[tot] = w;
	Next[tot] = head[u];
	head[u] = tot;
}
int Num, n, m;
priority_queue <pli, vector <pli>, greater <pli> > q; 
LL vistime[N];
LL dis[N];
inline void dijkstra()
{
	for (int i = 2; i <= n; i++) dis[i] = INF;
	
	q.push(make_pair(0, 1));
	int fx; LL fy;
	LL t = 0;
	while (!q.empty())
	{
		fx = q.top().second;
		fy = q.top().first;
		q.pop();

		if (dis[fx] != fy) continue;
		
		if (!vistime[fx]) vistime[fx] = ++t;
		
		for (int i = head[fx]; i; i = Next[i])
		{
			int v = ver[i], w = Edge[i];
			
			if (dis[fx] + w < dis[v])
			{
				dis[v] = dis[fx] + w;
				q.push(make_pair(dis[v], v));
			}
		}
	}
}
int dfn[N], low[N], sum;
bool Cut[M];
inline void tarjan(int x, int fa)
{
	dfn[x] = low[x] = ++sum;
	
	for (int i = head[x]; i; i = Next[i])
	{
		int v = ver[i];
		if (!dfn[v])
		{
			tarjan(v, i);
			
			low[x] = min(low[x], low[v]);
			
			if (low[v] > dfn[x]) Cut[i] = Cut[i ^ 1] = 1;
		}
		else if (i != (fa ^ 1)) low[x] = min(low[x], dfn[v]);
	}
}
inline LL del(int x, int i)
{
	LL res = INF;
	
	for (int j = head[x]; j; j = Next[j])
	{
		if (i == j || i == (j ^ 1)) continue;
		
		res = min(res, dis[ver[j]] + 1ll * Edge[j]);
	}
	
	return res;
}
int main(){
	freopen ("rebirth.in", "r", stdin);
	freopen ("rebirth.out", "w", stdout);
	read(Num); read(n); read(m); tot = -1;
	
	int f = 0, s = 0;
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		read(u); read(v); read(w);
		add(u, v, w);
		add(v, u, w);
		
		if (u == v && u == 1) f = max(f, w);
		if (u == 1 || v == 1) s++;
	}
	dijkstra();
	
	for (int i = 1; i <= n; i++)
	if (!dfn[i]) tarjan(i, 0);
	
	if (s <= 1) putchar('0');
	else printf("%d", f);
	for (int x = 2; x <= n; x++)
	{
		LL res = 0;
		
		for (int i = head[x]; i; i = Next[i])
		{
			int v = ver[i];
			if (Cut[i] && vistime[v] < vistime[x])
			{
				res = -1;
				printf(" -1");
				break;
			}
		}
		if (res == -1) continue;
		for (int i = head[x]; i; i = Next[i])
		{
			LL now = del(x, i);
			
			res = max(res, now);
		}
		printf(" %lld", res);
	}
	puts("");
  return 0;
}
