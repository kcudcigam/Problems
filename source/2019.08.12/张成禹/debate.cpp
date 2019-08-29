#include <bits/stdc++.h>
using namespace std;
#define mr make_pair
#define pb push_back
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
int n, cnt, mn, mx;
int v[5][400005];
LL s[5][400005];
LL ans, now, tr;
bool cmp(int x, int y) { return x > y; }
int main()
{
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	read(n);
	for (int i = 1, x, y; i <= n; ++i)
	{	
		read(x); read(y);
		if (x == 10) x = 2;
		if (x == 11) x = 3;
		v[x][++v[x][0]] = y;
	}
// 0 -> 00   1 -> 01   2 -> 10   3 -> 11
	for (int i = 0; i < 4; ++i)
		sort(v[i] + 1, v[i] + v[i][0] + 1, cmp);
	for (int i = 1; i <= v[3][0]; ++i) 
		ans += v[3][i];
	cnt = v[3][0];
	if (v[1][0] < v[2][0])
	{
		for (int i = 1; i <= v[2][0]; ++i)
			swap(v[1][i], v[2][i]);
		swap(v[1][0], v[2][0]);
	}
	for (int i = 1; i <= v[1][0]; ++i)
		s[1][i] = s[1][i - 1] + v[1][i];
	for (int i = 1; i <= v[2][0]; ++i)
		s[2][i] = s[2][i - 1] + v[2][i];
// v[1][0] >= v[2][0]
	for (int i = 0; i <= v[0][0]; ++i)
	{
		if (cnt + v[2][0] < i) break;
		mx = cnt + v[2][0] - i;
		mn = v[2][0] + i - cnt;
		if (mn > v[1][0] || mn > mx) break;
		if (mx > v[1][0]) mx = v[1][0];
		tr = max(tr, now + s[2][v[2][0]] + s[1][mx]);
		now += v[0][i + 1];
	}
	cout << ans + tr << '\n';
	return 0;
}

