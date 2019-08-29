#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F

struct mat
{
	int a[310][310];
	int matsize;
}A, B, C;
int x, y, ans;
int v[310][310];

const int dx[5] = { 0,-1,0,1,0 };
const int dy[5] = { 0,0,-1,0,1 };

mat operator*(mat A, mat B)
{
	for (int i = 0; i < A.matsize; i++)
		for (int j = 0; j < A.matsize; j++)
			for (int k = 0; k < B.matsize; k++)
				for (int l = 0; l < B.matsize; l++)
					C.a[k * A.matsize + i][l * A.matsize + j] = A.a[i][j] * B.a[k][l];
	C.matsize = A.matsize * B.matsize;
	return C;
}

bool inbound(int x, int y)
{
	return x >= 0 && x < A.matsize && y >= 0 && y < A.matsize;
}

void dfs(int x, int y)
{
	if (v[x][y]) return;
	v[x][y] = true;
	ans++;
	if (x == 0 && y == 0)
	{
		ans = INF; return;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (ans == INF) return;
		int nx = x + dx[i], ny = y + dy[i];
		if (inbound(nx, ny) && !v[nx][ny] && A.a[nx][ny] == A.a[x][y])
			dfs(nx, ny);
	}
}

int main()
{
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> x >> y;
	
	if (x <= 100 && y <= 100)
	{
		B.a[0][0] = 1;
		B.a[0][1] = 1;
		B.a[1][0] = 1;
		B.a[1][1] = -1;
		B.matsize = 2;
		A.a[0][0] = 1;
		A.a[0][1] = 1;
		A.a[1][0] = 1;
		A.a[1][1] = -1;
		A.matsize = 2;
		for (int i = 1; i <= 7; i++)
			A = A * B;
		dfs(x, y);
		if (ans != INF) cout << ans << endl; else cout << "infinity" << endl;
		return 0;
	}
	cout << "infinity" << endl;

	return 0;
}


