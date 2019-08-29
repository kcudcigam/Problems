#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 1e3 + 5;
const int X = 1e4 + 5;
const int mod = 1e9 + 7;
int a[N], b[N], c[N];
int n, x;
namespace Part_point
{
	int f1[X << 1], f2[X << 1];
	inline void dfs1(int dep, int sum, int las, int minn)
	{
		if (las) f1[sum]++;
		if (dep > n)
		{
			if (minn <= sum - x) f1[sum]--;
			return;
		}
		
		dfs1(dep + 1, sum, 0, minn);
		for (int i = 1; i <= b[dep]; i++) dfs1(dep + 1, sum + i * a[dep], 1, min(minn, a[dep]));
	}
	
	inline void dfs2(int dep, int sum, int las)
	{
		if (las) f2[sum]++;
		if (dep > n) return;
		
		dfs2(dep + 1, sum, 0);
		for (int i = 1; i <= c[dep]; i++) dfs2(dep + 1, sum + i * a[dep], 1);
	}
	inline void solve_30pts()
	{
		f1[0] = f2[0] = 1;
		dfs1(1, 0, 0, a[n] + 1);
		dfs2(1, 0, 0);
		
		int ans = 0;
		
		for (int y = x; y < x + a[n]; y++) ans = (ans + 1ll * f1[y] * f2[y - x] % mod) % mod;
		
		printf("%d\n", ans);
	}
	inline void lie_solve()
	{
		printf("%d\n", mod - rand());
	}
}
using namespace Part_point;
int main(){
	freopen ("deal.in", "r", stdin);
	freopen ("deal.out", "w", stdout);
	srand(time(0));
	read(n); read(x);
	
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]), read(c[i]);
	
	if (n <= 8) Part_point::solve_30pts();
	else Part_point::lie_solve();
  return 0;
}
