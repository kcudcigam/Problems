#include<bits/stdc++.h>
#define MAXN 300005
#define MAXE 600005

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
}

int n, e, tot, mindis[MAXN], ver[MAXE], edge[MAXE], Next[MAXE], head[MAXN], last[MAXN], vis[MAXN], v[MAXN];
priority_queue < pair<int, int> > q;

void add(int x, int y, int z)
{
	edge[++e] = z;
	ver[e] = y;
	Next[e] = head[x];
	head[x] = e;
}

void prim(int spos)
{
	++tot;
	q.push(make_pair(0, spos));
	mindis[spos] = 0;
	last[spos] = spos;
	while (!q.empty())
	{
		int x = q.top().second;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = tot;
		for (int i = head[x]; i; i = Next[i])
		{
			int y = ver[i], z = edge[i];
			if (mindis[y] > z)
			{
				if (!vis[y])
					mindis[y] = z, last[y] = x;
				q.push(make_pair(-mindis[y], y));
			}
		}
	}
}

int ask(int x, int y)
{
	memset (v, 0, sizeof(v));
	while (last[y] != y)
		v[last[y]] = max(v[y], mindis[y]), y = last[y];
	if (v[x])
		return v[x];
	while (last[x] != x)
	{
		if (v[last[x]])
			return max(v[last[x]], max(v[x], mindis[x]));
		v[last[x]] = max(v[x], mindis[x]), x = last[x];
	}
	return -1;
}

int main(int argc, char *argv[])
{
	freopen ("graph.in", "r", stdin);
	freopen ("graph.out", "w", stdout);
	memset (mindis, 0x7f, sizeof(mindis));
	int m, q;
	read(n), read(m), read(q);
	for (int i = 1; i <= m; ++i)
	{
		int x, y, z;
		read(x), read(y), read(z);
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			prim(i);
	for (int i = 1; i <= q; ++i)
	{
		int x, y;
		read(x), read(y);
		if (vis[x] != vis[y])
		{
			puts("-1");
			continue;
		}
		printf ("%d\n", ask(x, y));
	}
	return 0;
}
