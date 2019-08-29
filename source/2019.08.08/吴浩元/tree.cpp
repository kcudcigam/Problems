#include<bits/stdc++.h>
using namespace std;

vector<int> a[200010];
int fa[200010], st[200010], fin[200010];
int cases, n, m, x, y;
bool v[200010], l[200010], ch[200010];
bool flag = true;
queue<int> q;

void build(int x)
{
	bool isleaf = true;
	for (int i = 0; i < a[x].size(); i++)
	{
		int nxt = a[x][i];
		if (v[nxt] == false)
		{
			isleaf = false;
			v[nxt] = true;
			fa[nxt] = x;
			build(nxt);
		}
	}
	if (isleaf)
		l[x] = true;
}

void change(int x, int k)
{
	if (k == 0) return;
	if (x == 0)
	{
		flag = false;
		return;
	}
	ch[x] ^= 1;
	if (ch[x] == true)
		q.push(x);
	change(fa[x], k - 1);
}

bool scan(int x)
{
	bool flag = false;
	for (int i = 0; i < a[x].size(); i++)
	{
		int nxt = a[x][i];
		if (fa[nxt] == x && scan(nxt))
			flag = true;
	}
	if (!flag && ch[x])
	{
		flag = true;
		q.push(x);
	}
	if (flag)
		return true;
	return false;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> cases;
	for (int times = 1; times <= cases; times++)
	{
		flag = true;
		memset(fa, 0, sizeof(fa));
		memset(v, false, sizeof(v));
		memset(ch, false, sizeof(ch));
		memset(l, false, sizeof(l));
		while (!q.empty())
			q.pop();
		
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			a[i].clear();
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		v[1] = true;
		fa[1] = 0;
		build(1);
		for (int i = 1; i <= n; i++)
			cin >> st[i];
		for (int i = 1; i <= n; i++)
			cin >> fin[i];
		for (int i = 1; i <= n; i++)
		{
			if (st[i] == fin[i])
				ch[i] = false;
			else
				ch[i] = true;
			if (l[i])
				q.push(i);
		}
		do
		{
			while (!q.empty())
			{
				int now = q.front();
				q.pop();
				if (ch[now])
					change(now, m);
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
		while (scan(1));
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}

