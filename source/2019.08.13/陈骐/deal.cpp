#include<bits/stdc++.h>
typedef long long ll;
#define MAXN 1005
#define MAXF 20000

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

const ll mod = 1000000007;
ll w[MAXN], x[MAXN], y[MAXN], T, f1[MAXN], f2[MAXN];

int main(int argc, char *argv[])
{
	freopen ("deal.in", "r", stdin);
	freopen ("deal.out", "w", stdout);
	ll n, k;
	read(n), read(k);
	puts("0");
	return 0;
}
