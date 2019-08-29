#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F3F3F3F3F

struct gside
{
	long long y, len;
};

vector<gside> a[200010];
long long d[200010], last[200010];
priority_queue<gside, vector<gside>, greater<gside> > p;
long long num, n, m, x, y, len;
bool vis[200010];

bool operator>(gside x, gside y)
{
	return x.len > y.len;
}

gside mkside(long long y, long long len)
{
	gside gs;
	gs.y = y; gs.len = len;
	return gs;
}

int main()
{
	// need check
	freopen("rebirth.in", "r", stdin);
	freopen("rebirth.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> num;
	cin >> n >> m;
	for (long long i = 1; i <= m; i++)
	{
		cin >> x >> y >> len;
		if (x != y)
		{
			a[x].push_back(mkside(y, len));
			a[y].push_back(mkside(x, len));
		}
	}
	memset(d, 0x3F, sizeof(d));
	d[1] = 0;
	p.push(mkside(1, 0));
	while (!p.empty())
	{
		gside gnow;
		long long now = 0;
		do
		{
			gnow = p.top();
			now = gnow.y;
			p.pop();
		} while (!p.empty() && vis[now]);
		if (now == 0) break;
		vis[now] = true;
		for (long long i = 0; i < a[now].size(); i++)
		{
			long long nxt = a[now][i].y, cost = a[now][i].len;
			if (d[now] + cost < d[nxt])
			{
				d[nxt] = d[now] + cost;
				last[nxt] = now;
				p.push(mkside(nxt, d[nxt]));
			}
		}
	}
	for (long long i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			cout << 0 << " ";
			continue;
		}
		long long ans = INF, mincost = INF, seccost = INF;
		for (long long j = 0; j < a[i].size(); j++)
		{
			long long nxt = a[i][j].y, cost = a[i][j].len;
			if (nxt == last[i])
			{
				if (cost <= mincost)
				{
					seccost = mincost;
					mincost = cost;
				}
				else if (cost <= seccost)
					seccost = cost;
			}
			else {
				ans = min(ans, d[nxt] + cost);
			}
		}
		if (seccost != INF) ans = min(ans, d[last[i]] + seccost);
		if (ans != INF) cout << ans << " "; else cout << -1 << " ";
	}
	cout << endl;

	return 0;
}


