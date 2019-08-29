#include<bits/stdc++.h>
typedef unsigned long long ll;

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

ll a[6];

int main(int argc, char *argv[])
{
	freopen ("stand.in", "r", stdin);
	freopen ("stand.out", "w", stdout);
	ll n, m;
	read(n), read(m);
	for (ll i = 1; i <= 5; ++i)
		read(a[i]);
	ll ans = 0;
	for (int i = 1; i <= 5; ++i)
		ans += (pow(n, i) * a[i]);
	printf ("%lld\n", ans);
	return 0;
}
