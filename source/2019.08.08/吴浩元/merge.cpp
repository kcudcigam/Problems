#include<bits/stdc++.h>
using namespace std;

struct tnode
{
	int ls, rs;
}a[1000010];
int cnt, n, m, op, x, y, d;
int fa[1000010], f[1000010];

template <typename T> void read(T &x)
{
	long long f = 1; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}

int anc(int x)
{
	if (fa[x] == x) return x;
	fa[x] = anc(fa[x]);
	return fa[x];
}

void merge(int x, int y)
{
	cnt++;
	a[cnt].ls = anc(x);
	a[cnt].rs = anc(y);
	fa[anc(x)] = anc(cnt);
	fa[anc(y)] = anc(cnt);
}

void dfs(int x, int val)
{
	if (x <= n)
	{
		f[x] += val;
		return;
	}
	dfs(a[x].ls, val + f[x]);
	dfs(a[x].rs, val + f[x]);
}

int main()
{
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	read(n); read(m);
	cnt = n;
	for (int i = 1; i <= 1000000; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		read(op);
		if (op == 1)
		{
			read(x); read(y);
			if (anc(x) != anc(y)) merge(x, y);
		}
		if (op == 2)
		{
			read(x); read(d);
			f[anc(x)] += d;
		}
	}
	for (int i = 1; i <= cnt; i++)
		if (fa[i] == i) dfs(i, 0);
	for (int i = 1; i <= n; i++)
		if (i == 1) cout << f[i]; else cout << " " << f[i];
	cout << endl;

	return 0;
}

