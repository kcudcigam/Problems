#include <bits/stdc++.h>
using namespace std;

int ri()
{
	char c = getchar(); int x = 0; for (; !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) x = x * 10 - '0' + c; return x;
}

int a[2][500010];
int n, m, op, x, y, z, l0, r0, l1, r1;

bool check(int l0, int r0, int l1, int r1, int val)
{
	int res0 = r0 + 1, res1 = r1 + 1, ans = 0;
	int l = l0, r = r0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[0][mid] >= val)
		{
			res0 = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	l = l1; r = r1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[1][mid] >= val)
		{
			res1 = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	ans = (r0 - res0 + 1) + (r1 - res1 + 1);
	if (ans >= ((r0 - l0 + 1) + (r1 - l1 + 1)) / 2 + 1) return true;
	return false;
}

int main()
{
	//use fast read
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	n = ri(); m = ri();
	for (int i = 1; i <= n; i++) a[0][i] = ri();
	for (int i = 1; i <= n; i++) a[1][i] = ri();
	for (int i = 1; i <= m; i++)
	{
		op = ri();
		if (op == 1)
		{
			x = ri(); y = ri(); z = ri();
			a[x][y] = z;
		}
		if (op == 2)
		{
			l0 = ri(); r0 = ri(); l1 = ri(); r1 = ri();
			int l = 0, r = (int)(1e9), ans = 0;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (check(l0, r0, l1, r1, mid))
				{
					ans = mid;
					l = mid + 1;
				}
				else
					r = mid - 1;
			}
			cout << ans << endl;
		}
	}

	return 0;
}


