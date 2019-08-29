#include<bits/stdc++.h>
#define MAXN 300005

using namespace std;

template<class T>
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

set <int> neighbour[MAXN];
long long val[MAXN];

int main(int argc, char *argv[])
{
	freopen ("sibyl.in", "r", stdin);
	freopen ("sibul.out", "w", stdout);
	int n, m, q;
	read(n), read(m), read(q);
	for (int i = 1; i <= n; ++i)
		neighbour[i].insert(i);
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		read(x), read(y);
		neighbour[x].insert(y);
		neighbour[y].insert(x);
	}
	for (int i = 1; i <= q; ++i)
	{
		int op, x, y;
		read(op);
		if (op == 1)
		{
			read(x), read(y);
			for (int a : neighbour[x])
				val[a] += (long long)y;
		}
		else if (op == 0)
		{
			read(x);
			printf ("%lld\n", val[x]);
		}
	}
	return 0;
}
