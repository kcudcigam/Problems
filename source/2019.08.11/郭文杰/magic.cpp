#include<bits/stdc++.h>

#define FILE "magic"
#define MOD 998244353

using namespace std;
using ull = unsigned long long;

ull ans, n, len;
char s[1000005];

ull Pow(ull a, ull b)
{
	ull ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

inline ull fact(ull a)
{
	ull ans = a;
	if (a == 0)
		return 1;
	for (auto i = 2ull; i < a; ++i)
		ans *= i;
	return ans;
}

int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	scanf("%llu%s", &n, s);
	len = strlen(s);
	if (len == n)
		printf("%llu", Pow(26, len) - 1);
	else
		printf("%llu", Pow(Pow(26, len) - 1, fact(n)/(fact(len) * fact(n - len))));
	return 0;
}
