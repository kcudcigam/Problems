#include<bits/stdc++.h>
#define MAXN 500005

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch))
		ch == '-' ? f = -1, ch = getchar() : ch = getchar();
	while (isdigit(ch))
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
	n *= f;
}

int fa[MAXN];
long long a[MAXN];

inline int get(int x)
{
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main(int argc, char *argv[])
{
	freopen ("merge.in", "r", stdin);
	freopen ("merge.out", "w", stdout);
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		int op, x, y;
		read(op), read(x), read(y);
		if (op == 1)
			fa[get(x)] = get(y);
		else if (op == 2)
		{
			int father = fa[x];
			for (int i = 1; i <= n; ++i)
				a[i] += (fa[i] == father ? y : 0);
		}
	}
	for (int i = 1; i < n; ++i)
		printf ("%lld ", a[i]);
	printf ("%lld\n", a[n]);
	return 0;
}
