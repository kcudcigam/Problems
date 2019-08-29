#include<bits/stdc++.h>
#define MAXN 20005

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

const int dx[5] = {0,0,1,0,-1};
const int dy[5] = {0,1,0,-1,0};
bool vis[MAXN][MAXN], a[MAXN][MAXN];

bool check(int x, int y)
{
	if (x >= 0 && y >= 0)
		return 1;
	return 0;
}

inline int dfs(int x, int y)
{
	int ans = 1;
	vis[x][y] = 1;
	for (int i = 1; i <= 4; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (check(nx, ny) && a[nx][ny] == a[x][y])
			ans += dfs(nx, ny);
	}
	return ans;
}

void get(int dep, int x, int y)
{
	if (dep > 13)
		return;
	for (int i = 0; i <= x; ++i)
		for (int j = 0; j <= y; ++j)
			if (i + x + 1 < MAXN && j + y + 1 < MAXN)
				a[i][j + y + 1] = a[i + x + 1][j] = a[i][j], a[i + x + 1][j + y + 1] = a[i][j] ^ 1;
	get(dep + 1, x * 2 + 1, y * 2 + 1);
}

int main(int argc, char *argv[])
{
	freopen ("area.in", "r", stdin);
	freopen ("area.out", "w", stdout);
	int x, y;
	read(x), read(y);
	a[0][0] = a[0][1] = a[1][0] = 1;
	a[1][1] = 0;
	get(1, 1, 1);
	if (a[x][y] == 1)
		puts("infinity");
	else printf ("%d\n", dfs(x, y));
	return 0;
}
