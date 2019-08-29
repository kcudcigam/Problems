#include<bits/stdc++.h>
#define MAXN 500005

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

int n, m, l[MAXN], r[MAXN], s[MAXN], e[MAXN], a[MAXN], cha[MAXN];

int main(int argc, char *argv[])
{
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	int n, m;
	read(n), read(m);
	bool p = 1;
	for (int i = 1; i <= m; ++i)
	{
		read(l[i]), read(r[i]), read(s[i]), read(e[i]);
		if (s[i] != e[i])
			p = 0;
	}
	if (p)
	{
		for (int i = 1; i <= m; ++i)
		{
			cha[l[i]] += s[i];
			cha[r[i] + 1] -= s[i];
		}
		int sum = 0, ans = 0;
		for (int i = 1; i <= n; ++i)
			sum += cha[i], ans ^= sum, cout << sum << endl;
		printf ("%d\n", ans);
	}
	else
	{
		for (int i = 1; i <= m; ++i)
		{
			int q = (e[i] - s[i]) / (r[i] - l[i]), now = s[i] - q;
			for (int j = l[i]; j <= r[i]; ++j)
			{
				now += q;
				a[j] += now;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = ans ^ a[i];
		printf ("%d\n", ans);
	}
	return 0;
}
