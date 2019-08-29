#include <bits/stdc++.h>
using namespace std;

vector<int> a[300010];
queue<int> q;
bool v[300010];
int d[300010];
int n, x, y;

int dist(int x)
{
	while (!q.empty()) q.pop();
	memset(v, false, sizeof(v));
	memset(d, 0, sizeof(d));
	int lst;
	q.push(x);
	v[x] = true;
	while (!q.empty())
	{
		int now = q.front();
		lst = now;
		q.pop();
		for (int i = 0; i < a[now].size(); i++)
		{
			int nxt = a[now][i];
			if (!v[nxt])
			{
				q.push(nxt);
				v[nxt] = true;
 			}
		}
	}
	memset(v, false, sizeof(v));
	q.push(lst);
	v[lst] = true;
	while (!q.empty())
	{
		int now = q.front();
		lst = now;
		q.pop();
		for (int i = 0; i < a[now].size(); i++)
		{
			int nxt = a[now][i];
			if (!v[nxt])
			{
				q.push(nxt);
				v[nxt] = true;
				d[nxt] = d[now] + 1;
 			}
		}
	}
	return d[lst];
}

int main()
{
	// need check / further thinking
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		cout << dist(x) << endl;
	}

	return 0;
}


