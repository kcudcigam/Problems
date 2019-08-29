#include<bits/stdc++.h>
#define MAXN 300005

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

int fa[MAXN], dist[MAXN], maxdist[MAXN];

inline int get(int x)
{
	if (fa[x] == x)
		return x;
	int root = get(fa[x]);
	dist[x] += dist[fa[x]];
	fa[x] = root;
	if (dist[x] > maxdist[fa[x]])
		maxdist[fa[x]] = dist[x];
	return fa[x];
}

void merg(int x, int y)
{
	dist[x] = 1;
	if (maxdist[x] + 1 > maxdist[y])
		maxdist[y] = maxdist[x] + 1;
	fa[x] = y;
}

int main(int argc, char *argv[])
{
	freopen ("town.in", "r", stdin);
	freopen ("town.out", "w", stdout);
	int n;
	read(n);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		read(x), read(y);
		x = get(x), y = get(y);
		merg(x, y);
		printf ("%d\n", maxdist[y]);
	}
	return 0;
}
