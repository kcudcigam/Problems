#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod = 998244353;
LL n, len;
string st;

inline LL power(LL a, LL p)
{
	LL ans = 1;
	for (; p; p >>= 1, a = a * a % mod) if (p & 1) ans = ans * a % mod;
	return ans;
}
map <string, int> h;
LL ans;
inline bool check(string p)
{
	int tot = -1; bool f;
	f = 1;
	for (int i = 0; i < len; i++)
	{
		tot++;
		if (p[i] != st[tot])
		{
			f = 0;
			break;
		}
	}
	if (f) return 1;
	
	tot = -1, f = 1;
	for (int i = n - len; i <= n - 1; i++)
	{
		tot++;
		if (p[i] != st[tot])
		{
			f = 0;
			break;
		}
	}
	
	if (f) return 1;
	for (int i = 0; i < st.size(); i++)
	{
		tot = -1; f = 1;
		for (int j = 0; j <= i; j++)
		{
			tot++;
			if (p[j] != st[tot])
			{
				f = 0;
				break;
			}
		}
		if (!f) continue;
		for (int j = n - len + i + 1; j <= n - 1; j++)
		{
			tot++;
			if (p[j] != st[tot])
			{
				f = 0;
				break;
			}
		}
		if (f) return 1;	
	}
	return 0;
}
inline void dfs(int dep, string p)
{
	if (dep == n)
	{
		if (h.count(p)) return;
		if (check(p)) ans++;
		h[p] = 1;
		return;
	}
	
	for (char i = 'a'; i <= 'z'; i++)
	dfs(dep + 1, p + i);
}
inline void solve_20pts()
{
	dfs(0, ""); 
	printf("%lld\n", (power(26, n) - ans + mod) % mod);
}
inline void solve_40pts()
{
	if (len == n)
	{
		printf("%lld\n", (power(26, n) - 1 + mod) % mod);
		return;
	}
	LL res = power(26, n - len) + 25 * len * power(26, n - len - 1) % mod;
	printf("%lld\n", (power(26, n) - res + mod) % mod);
}
int main(){
	freopen ("magic.in", "r", stdin);
	freopen ("magic.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> st;
	
	len = st.size();
	
	if (n <= 4) solve_20pts();
	else solve_40pts();
  return 0;
}
