#include<bits/stdc++.h>
using namespace std;

#define modnum 998244353

long long n, ans;
string s;

long long quickpow(long long a, long long t, long long p)
{
	long long now = a, ans = 1;
	while (t > 0)
	{
		if (t & 1) ans = ans * now % p;
		now = now * now % p;
		t >>= 1;
	}
	return ans;
}

int main()
{
	//use long long
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> n;
	cin >> s;
	ans = (s.length() + 1) * quickpow(26, n - s.length(), modnum) % modnum;
	for (long long i = 1; n - s.length() - i >= 0; i++)
		ans = (ans - quickpow(26, n - s.length() - i, modnum) + modnum) % modnum;
	if ((n - s.length()) / 2 >= 1) ans = (ans - quickpow(26, (n - s.length()) / 2, modnum) + modnum) % modnum;
	ans = (quickpow(26, n, modnum) - ans + modnum) % modnum;
	cout << ans << endl;

	return 0;
}

