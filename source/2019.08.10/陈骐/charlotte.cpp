#include<bits/stdc++.h>
#define MAXN 100005

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

struct point
{
	int t, x, y;
}node[MAXN];

bool operator < (const point &a, const point &b)
{
	return a.t < b.t;
}

int calc(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(int argc, char *argv[])
{
	freopen ("charlotte.in", "r", stdin);
	freopen ("charlotte.out", "w", stdout);
	int T;
	read(T);
	while (T--)
	{
		int n;
		read(n);
		for (int i = 1; i <= n; ++i)
			read(node[i].t), read(node[i].x), read(node[i].y);
		sort (node + 1, node + n + 1);
		int nowx = 0, nowy = 0, now = 0;
		bool flag = 0;
		for (int i = 1; i <= n; ++i)
		{
			int tmp = calc(nowx, nowy, node[i].x, node[i].y), tim = node[i].t - now;
			if (tim >= tmp && (tim - tmp) % 2 == 0)
				nowx = node[i].x, nowy = node[i].y, now = node[i].t;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)puts("No");
		else puts("Yes");
	}
	return 0;
}
