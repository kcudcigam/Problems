#include<bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 2e5 + 5;
const LL INF = 1e14;
int a[N];
int n, A, B, C, D;
inline LL Calc(LL x)
{
	return A * x * x * x + B * x * x + C * x + D;
}
namespace ST
{
	int f[N][25], Log[N];
	inline void prework()
	{
		Log[0] = -1;
		for (int i = 1; i <= n; i++) f[i][0] = a[i], Log[i] = Log[i >> 1] + 1;
		
		for (int j = 1; j <= 20; j++)
		 for (int i = 1; i <= n - (1 << j) + 1; i++)
		  f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	}
	
	inline int query(int l, int r)
	{
		int k = Log[r - l + 1];
		return min(f[l][k], f[r - (1 << k) + 1][k]);
	}
}
namespace dp
{
	LL f[N];
	int q[N], l, r;
	
	inline LL solve_30pts()
	{
		
		for (int i = 1; i <= n; i++)
		{
			f[i] = Calc(ST::query(1, i));
			
			for (int j = 1; j < i; j++)
			f[i] = max(f[i], f[j] + Calc(ST::query(j + 1, i)));
			
		}
		return f[n];
	}
	inline LL solve_50pts()
	{
		LL ans = 0;
		if (D >= 0)
		{
			for (int i = 1; i <= n; i++) ans += Calc(a[i]);
		}
		else
		{
			ans = Calc(ST::query(1, n));
		}
		
		return ans;
	}
	inline LL fake_solve()
	{
		q[0] = 1;
		f[1] = a[1];
		
		for (int i = 2; i <= n; i++)
		{
			f[i] = f[q[0]] + Calc(ST::query(q[0] + 1, i));
			
			while (l <= r && f[i] > f[q[r]] + Calc(ST::query(q[r] + 1, i))) r--;
			q[++r] = i;
		}
		
		return f[n];
	}
}

using namespace ST;
using namespace dp;
int main(){
	freopen ("min.in", "r", stdin);
	freopen ("min.out", "w", stdout);
	read(n); read(A); read(B); read(C); read(D);
	
	for (int i = 1; i <= n; i++) read(a[i]);
	
	ST::prework();
	
	if (n <= 1000) printf("%lld\n", dp::solve_30pts());
	else if (A == 0 && B == 0 && C <= 0) printf("%lld\n", dp::solve_50pts());
	else printf("%lld\n", dp::fake_solve());
  return 0;
}
