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
int q, n, mod;
inline void doit()
{
	read(n); read(mod);
	
	if (n == 1) puts("0");
	else if (n == 2) puts("2");
	else
	{
		LL ans = 2;
		
		for (LL i = 3; i <= n; i++)
		{
			if (i % 2) ans = (i * ans % mod + i * (i - 1) % mod) % mod;
			else ans = (i * (ans + 1) % mod + (i - 1) * (i - 2) % mod) % mod;
		}
		printf("%lld\n", ans);
	}
}
int main(){
	freopen ("mod.in", "r", stdin);
	freopen ("mod.out", "w", stdout);
	read(q);
	
	while (q--) doit();
  return 0;
}
