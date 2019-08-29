# include <bits/stdc++.h>
using namespace std;
# define mr make_pair
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const LL  infll = 0x3f3f3f3f3f3f3f3fll, INFLL = 0x7fffffffffffffffll;
template <typename T> void read(T &x)
{
	x = 0; int f = 1; char c = getchar();
	for ( ; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for ( ; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void chkmax(T &x, T y) { x = x < y ? y : x; }
template <typename T> void chkmin(T &x, T y) { x = x > y ? y : x; }
const int N = 5005, M = 16005;
int NUM, n, m, cnt;
struct edge { int to, w, nxt; } e[M];
bool vis[N];
LL dis[N];
int pre[N], lst[N], fir[N];
struct que
{
	int id; LL dis;
	que(int a, LL b) { id = a, dis = b; }
	bool operator < (const que &r) const
		{ return dis > r.dis; }
};
priority_queue <que> q;
void Ade(int u, int v, int w)
{
	e[++cnt] = (edge) { v, w, fir[u] }, fir[u] = cnt;
	e[++cnt] = (edge) { u, w, fir[v] }, fir[v] = cnt;
}
void Dij(int S)
{
	int u, v, d;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[S] = 0; vis[S] = 1; q.push(que(S, 0));
	while (!q.empty())
	{
		while (!q.empty() && vis[q.top().id]) q.pop();
		u = q.top().id, d = q.top().dis; vis[u] = 1;
		for (int i = fir[u]; ~i; i = e[i].nxt)
		{
			v = e[i].to;
			if (dis[u] + e[i].w < dis[v])
			{
				dis[v] = dis[u] + e[i].w;
				pre[v] = u; lst[v] = i;
				q.push(que(v, dis[v]));
			}
		}
	}
}
void Wk(int S)
{
	int u, v, d;
	memset(dis, 63, sizeof dis);
	memset(vis, 0, sizeof vis);
	while (!q.empty()) q.pop();
	dis[S] = 0; vis[S] = 1; q.push(que(S, 0));
	while (!q.empty())
	{
		while (!q.empty() && vis[q.top().id]) q.pop();
		u = q.top().id, d = q.top().dis; vis[u] = 1;
		if (u == 1) return;
		for (int i = fir[u]; ~i; i = e[i].nxt)
		{
			if (i == lst[S] || i == (lst[S] ^ 1)) continue;
			v = e[i].to;
			if (dis[u] + e[i].w < dis[v])
			{
				dis[v] = dis[u] + e[i].w;
				q.push(que(v, dis[v]));
			}
		}
	}
}
int main()
{
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	cnt = -1; memset(fir, -1, sizeof fir);
	read(NUM), read(n), read(m);
	for (int i = 1, x, y, w; i <= m; ++i)
		read(x), read(y), read(w), Ade(x, y, w);
	Dij(1);
	cout << 0;
	for (int i = 2; i <= n; ++i)
		Wk(i), cout << ' ' << (dis[1] == infll ? -1 : dis[1]);
	cout << '\n';
	return 0;
}

