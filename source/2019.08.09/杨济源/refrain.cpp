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
const int mod = 1e9 + 7;
int Num;
int vis[1001][1001];
int p[1001];
pair <int, int> p1[N], p2[N];
int n, m1, m2;
inline void solve_30pts()
{
	int x, y;
	for (int i = 1; i <= m1; i++)
	{
		read(x); read(y);
		p1[i] = make_pair(x, y);
		vis[x][y] = vis[y][x] = 1;
	}
	
	for (int i = 1; i <= m2; i++)
	{
		read(x); read(y);
		p2[i] = make_pair(x, y);
		vis[x][y] = vis[y][x] = 2;
	}
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	int ans = 0;
	do
	{
		bool f = 0;
		for (int i = 1; i <= m1; i++) if (vis[p1[i].first][p1[i].second] != vis[p[p1[i].first]][p[p1[i].second]])
		{
			f = 1;
			break;
		}
		ans += f;
		if (f) continue;
	
		for (int i = 1; i <= m2; i++) if (vis[p2[i].first][p2[i].second] != vis[p[p2[i].first]][p[p2[i].second]])
		{
			f = 1;
			break;
		}
		ans += f;
	}while (next_permutation(p + 1, p + n + 1));
	
	printf("%d\n", ans % mod);
}
inline LL power(int a, int p)
{
	LL ans = 1;
	for (; p; p >>= 1, a = a * a % mod) if (p & 1) ans = ans * a % mod;
	return ans;
}
inline void solve_50pts()
{
	LL ans = 1;
	for (int i = 1; i <= n; i++) ans = ans * i % mod;
	
	LL now, jc;
	jc = 1;
	for (int i = 1; i <= m1; i++) jc = jc * i % mod;
	now = jc;
	
	jc = 1;
	for (int i = 1; i <= m2; i++) jc = jc * i % mod;
	now = (now * jc) % mod;
	
	jc = 1;
	for (int i = 1; i <= n - 2 * (m1 + m2); i++) jc = jc * i % mod;
	
	now = now * power(2, m1 + m2) % mod * jc % mod;
	printf("%lld\n", (ans - now + mod) % mod); 
}
int main(){
	freopen ("refrain.in", "r", stdin);
	freopen ("refrain.out", "w", stdout);
	read(Num);
	read(n); read(m1); read(m2);
	
	if (Num <= 2) { puts("0"); return 0; }
	else if (Num <= 6) solve_30pts();
	else if (Num <= 10) solve_50pts();
  return 0;
}
