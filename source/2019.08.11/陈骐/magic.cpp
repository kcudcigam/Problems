#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
}

inline bool readstring(string &s)
{
	s = "";
	char ch = getchar();
	while (!islower(ch))
		ch = getchar();
	char res = ch;
	bool flag = 1;
	while (islower(ch))
	{
		if (ch != res)
			flag = 0;
		s = s + ch, ch = getchar();
	}
	return flag;
}

const ll mod = 998244353, phimod = 998244352;

ll fastpow(ll a, ll n)
{
	n %= phimod;
	ll ans = 1;
	for (; n; n >>= 1, a = a * a % mod)
		ans = ans * (n & 1 ? a : 1) % mod;
	return ans;
}

int main(int argc, char *argv[])
{
	freopen ("magic.in", "r", stdin);
	freopen ("magic.out", "w", stdout);
	ll n;
	string s;
	read(n);
	bool flag = readstring(s);
	ll total = fastpow(26, n), len = s.size();
	ll able = ((len + 1) % mod * fastpow(26, n - len)) % mod;
	if (len == n)
		able = 1;
	printf ("%lld\n", ((total - able + flag * len) % mod + mod) % mod);
	return 0;
}
