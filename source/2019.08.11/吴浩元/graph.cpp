#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > a[1000010];
pair<int, int> t[1000010];
int fa[1000010], f[1000010], d[1000010], b[1000010][25];
int maxz, cnt, n, m, q, x, y, z;

int anc(int x)
{
	if (fa[x] == x) return x;
	fa[x] = anc(fa[x]);
	return fa[x];
}

void merge(int x, int y, int z)
{
	int ax = anc(x), ay = anc(y);
	if (ax == ay) return;
	cnt++;
	t[cnt] = make_pair(ax, ay);
	f[cnt] = z;
	fa[cnt] = cnt;
	fa[ax] = cnt; fa[ay] = cnt;
}

void build(int x, int from)
{
	b[x][0] = from;
	d[x] = d[from] + 1;
	for (int i = 1; i <= 20; i++)
		b[x][i] = b[b[x][i - 1]][i - 1];
	if (x > n)
	{
		build(t[x].first, x);
		build(t[x].second, x);
	}
}

int lca(int x, int y)
{
	if (d[x] < d[y]) swap(x, y);
	for (int i = 20; i >= 0; i--) if (d[b[x][i]] >= d[y]) x = b[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--)
		if (b[x][i] != b[y][i]) { x = b[x][i]; y = b[y][i]; }
	return b[x][0];
}

int main()
{
	// use fast read
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[z].push_back(make_pair(x, y));
		maxz = max(maxz, z);
	}
	cnt = n;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= maxz; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			merge(a[i][j].first, a[i][j].second, i);
	}
	for (int i = 1; i <= cnt; i++)
	{
		if (anc(i) == i)
		{
			d[i] = 1;
			build(i, 0);
		}
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &x, &y);
		if (anc(x) != anc(y))
		{
			cout << -1 << endl;
			continue;
		}
		printf("%d\n", f[lca(x, y)]);
	}

	return 0;
}

