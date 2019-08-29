#include<bits/stdc++.h>
typedef unsigned long long ll;

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch))
		ch == '-' ? f = -1, ch = getchar() : ch = getchar();
	while (isdigit(ch))
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
	n *= f;
}

const ll ten[11] = {0, 0, 2, 12, 58, 310, 1886, 13244, 106002, 954090, 9540982};
vector <ll> q;

int main(int argc, char *argv[])
{
	freopen ("mod.in", "r", stdin);
	freopen ("mod.out", "w", stdout);
	int T;
	read(T);
	while (T--)
	{
		ll n, p;
		read(n), read(p);
		if (n <= 10)
		{
			printf ("%lld\n", ten[n] % p);
			continue;
		}
		q.clear();
		ll sum = 2;
		for (ll i = 4; i <= n; ++++i)
			sum *= i * (i - 1), q.push_back(sum);
		ll ans = (n >> 1) * 5 - 2, len = q.size();
		for (ll i = 0; i < len; ++i)
			ans = (ans + ((n - (q[i] >> 1)) / q[i] * ((i << 1) + 1) % p + (n / q[i] * ((i << 1) + 2))) % p) % p;
		printf ("%lld\n", ans % p);
	}
	return 0;
}
