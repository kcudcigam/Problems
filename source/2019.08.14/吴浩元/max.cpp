#include <bits/stdc++.h>
using namespace std;

#define MODN 1000000007

struct crystal
{
	long long x, y, p;
};
vector<crystal> v[5010];
map<long long, long long> r[5010], nxt[5010];
crystal a[5010];
long long head[5010], p[5010];
long long n, m, q, ans, lb, rb;

long long quickpow(long long a, long long t, long long p)
{
	long long now = a, ans = 1;
	while (t > 0)
	{
		if (t & 1) ans = ans * now % p;
		now = now * now % p;
		t >>= 1;
	}
	return ans;
}

long long inv(long long a, long long b, long long p)
{
	return a * quickpow(b, p - 2, p) % p;
}

bool cmp(crystal a, crystal b)
{
	return a.y < b.y;
}

void calc(long long x)
{
	sort(v[x].begin(), v[x].end(), cmp);
	long long lst = 0;
	for (long long i = 0; i < v[x].size(); i++)
	{
		crystal now = v[x][i];
		long long pnow = 1;
		r[x][now.y] = (r[x][now.y] + now.p * pnow % MODN) % MODN;
		if (now.y != lst)
		{
			nxt[x][now.y] = lst;
			lst = now.y;
		}
		pnow = pnow * (1 - now.p + MODN) % MODN;
	}
	head[x] = lst;
	//cout << r[x] << endl;
}

int main()
{
	// use long long
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> q;
	for (long long i = 1; i <= m; i++) 
	{
		cin >> a[i].x >> a[i].y >> a[i].p;
		v[a[i].x].push_back(a[i]);
	}
	for (long long i = 1; i <= n; i++)
		calc(i);
	/*
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= 3; j++)
			if (nxt[i].find(j) != nxt[i].end()) cout << i << " " << j << " " << nxt[i][j] << endl;
	*/
	for (long long i = 1; i <= q; i++)
	{
		cin >> lb >> rb;
		long long now = 0, res = 0, pnow = 1;
		for (long long j = lb; j <= rb; j++) p[j] = head[j];
		while (true)
		{
			now = 0; res = 0;
			for (long long j = lb; j <= rb; j++)
				now = max(now, p[j]);
			if (now == 0) break;
			for (long long j = lb; j <= rb; j++)
				if (p[j] == now)
				{
					res = (res + r[j][now] * pnow % MODN) % MODN;
					p[j] = nxt[j][now];
				}
			ans = (ans + res * now % MODN) % MODN;
			pnow = pnow * (1 - res + MODN) % MODN;
			//cout << now << " " << res << " " << ans << " " << pnow << endl;
		}
		//cout << ans << endl;
	}
	cout << ans << endl;

	return 0;
}


