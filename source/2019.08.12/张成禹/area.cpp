#include <bits/stdc++.h>
using namespace std;
int X, Y, n, a, b;
long long ans;
bool col, inf;
bitset <16384> m[16384];
queue <int> x;
queue <int> y;
bool calc(int a, int b)
{
	return m[a / 16384][b / 16384] ? (m[a - ((a >> 14) << 14)][b - ((b >> 14) << 14)] == col)
		: ((1 - m[a - ((a >> 14) << 14)][b - ((b >> 14) << 14)]) == col);
}
int main()
{
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	cin >> X >> Y;
	if (X > 10000 || Y > 10000) { puts("infinity"); return 0; }
	n = 2; m[0][0] = m[0][1] = m[1][0] = 1, m[1][1] = 0;
	for ( ; n < 16384; n *= 2)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				m[n + i][j] = m[i][n + j] = m[i][j],
				m[n + i][n + j] = 1 - m[i][j];
	}
	col = m[a / 16384][b / 16384] ? m[a - ((a / 16384) * 16384)][b - ((b / 16384) * 16384)]
		: 1 - m[a - ((a / 16384) * 16384)][b - ((b / 16384) * 16384)];
	x.push(X);
	y.push(Y);
	while (!x.empty())
	{
		a = x.front(), b = y.front(); x.pop(), y.pop(); ans++;
		if (a == 0) { inf = 1; break; }
		if (b == 0) { inf = 1; break; }
		if (calc(a - 1, b)) x.push(a - 1), y.push(b);
		if (calc(a + 1, b)) x.push(a + 1), y.push(b);
		if (calc(a, b - 1)) x.push(a), y.push(b - 1);
		if (calc(a, b + 1)) x.push(a), y.push(b + 1);
	}
	if (inf) puts("infinity");
	else cout << ans << '\n';
	return 0;
}
