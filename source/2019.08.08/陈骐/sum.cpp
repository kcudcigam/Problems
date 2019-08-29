#include<bits/stdc++.h>
#define MAXN 100005

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

int a[MAXN], s[MAXN];

int main(int argc, char *argv[])
{
	freopen ("sum.in", "r", stdin);
	freopen ("sum.out", "w", stdout);
	int n;
	read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]), s[i] = s[i - 1] + a[i];
	int ans = INT_MIN, reg = INT_MIN, l, r;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			if (s[i] - s[j - 1] > ans)
			{
				ans = s[i] - s[j - 1];
				l = j, r = i;
			}
	for (int i = 1; i <= l; ++i)
		for (int j = 1; j <= i; ++j)
			reg = max(reg, s[i] - s[j - 1]);
	for (int i = r + 1; i <= n; ++i)
		for (int j = r + 1; j <= i; ++j)
			reg = max(reg, s[i] - s[j - 1]);
	printf ("%d\n", reg < 0 ? ans : reg + ans);
	return 0;
}
