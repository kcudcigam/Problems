#include <bits/stdc++.h>
using namespace std;
#define mr make_pair
#define pk push_back
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const LL  infll = 0x3f3f3f3f3f3f3f3fll, INFLL = 0x7fffffffffffffffll;
template <typename T> void read(T &x)
{
	x = 0; int f = 1; char c = getchar();
	for ( ; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for ( ; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void chkmax(T &x, T y) { x = x < y ? y : x; }
template <typename T> void chkmin(T &x, T y) { x = x > y ? y : x; }
int n, m, l0, r0, l1, r1, L, R, len, mid, x, y, z, tp, ans;
int a[2][500005];
int chk0(int x)
{	
	if ((x - l0) > (len / 2)) return len / 2 + 1;
	int y = l1 + (len / 2) - x + l0 - 1;
	if (y > r1) return len / 2 - 1;
	if (y < l1)
	{
		if (a[0][x] <= a[1][l1]) return len / 2;
		return len / 2 + 1;
	}
	if (y == r1)
	{
		if (a[0][x] >= a[1][y]) return len / 2;
		return len / 2 - 1;
	}
	if (y < r1)
	{
		if (a[0][x] >= a[1][y] && a[0][x] <= a[1][y + 1]) return len / 2;
		if (a[0][x] > a[1][y + 1]) return len / 2 + 1;
		return len / 2 - 1;
	}
}
int chk1(int x)
{
	if ((x - l1) > (len / 2)) return len / 2 + 1;
	int y = l0 + (len / 2) - x + l1 - 1;
	if (y > r0) return len / 2 - 1;
	if (y < l0)
	{
		if (a[1][x] <= a[0][l0]) return len / 2;
		return len / 2 + 1;
	}
	if (y == r0)
	{
		if (a[1][x] >= a[0][y]) return len / 2;
		return len / 2 - 1;
	}
	if (y < r0)
	{
		if (a[1][x] >= a[0][y] && a[1][x] <= a[0][y + 1]) return len / 2;
		if (a[1][x] > a[0][y + 1]) return len / 2 + 1;
		return len / 2 - 1;
	}
}
int main()
{
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; ++i)
		read(a[0][i]);
	for (int i = 1; i <= n; ++i)
		read(a[1][i]);
	while (m--)
	{
		read(tp);
		if (tp == 1)
		{
			read(x), read(y), read(z);
			a[x][y] = z;
		}
		else
		{
			read(l0), read(r0), read(l1), read(r1);
			len = r0 - l0 + 1 + r1 - l1 + 1; ans = 0;
			L = l0, R = r0 + 1;
			while (L + 1 < R)
			{
				mid = L + R >> 1;
				if (chk0(mid) > (len / 2)) R = mid;
				else L = mid;
			}
			if (chk0(L) == (len / 2)) ans = a[0][L];
			
			L = l1, R = r1 + 1;
			while (L + 1 < R)
			{
				mid = L + R >> 1;
				if (chk1(mid) > (len / 2)) R = mid;
				else L = mid;
			}
			if (chk1(L) == (len / 2)) ans = a[1][L];
			
			cout << ans << '\n';
		}
	}
	return 0;
}
