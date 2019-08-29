#include <bits/stdc++.h>
using namespace std;

int num, n, m1, m2, ans, x, y;
struct connection
{
	int x, y;
}a[100010], b[100010];
int p[100010];
set<connection> r, s;

connection conn(int x, int y)
{
	connection c;
	c.x = x; c.y = y;
	return c;
}

bool operator<(connection c, connection d)
{
	if (c.x == d.x)
		return c.y < d.y;
	return c.x < d.x;
}

bool check()
{
	for (int i = 1; i <= m1; i++)
		if (r.find(conn(p[a[i].x], p[a[i].y])) != r.end() || r.find(conn(p[a[i].y], p[a[i].x])) != r.end()) continue; else return true;
	for (int i = 1; i <= m2; i++)
		if (s.find(conn(p[b[i].x], p[b[i].y])) != s.end() || s.find(conn(p[b[i].y], p[b[i].x])) != s.end()) continue; else return true;
	return false; 
}

int main()
{
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> num;
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= m1; i++)
	{
		cin >> x >> y;
		a[i].x = x; a[i].y = y;
		r.insert(a[i]);
	}
	for (int i = 1; i <= m2; i++)
	{
		cin >> x >> y;
		b[i].x = x; b[i].y = y;
		s.insert(b[i]);
	}
	for (int i = 1; i <= n; i++) p[i] = i;
	while (next_permutation(p + 1, p + n + 1))
	{
		if (check())
		{
			ans++;
			//for (int i = 1; i <= n; i++) cout << p[i] << " ";
			//cout << endl;
		}
	}
	cout << ans << endl;

	return 0;
}


