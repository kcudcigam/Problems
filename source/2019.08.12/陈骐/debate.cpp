#include<bits/stdc++.h>
#define MAXN 400005

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

priority_queue <int> q[4];

int ha(int x)
{
	if (x == 10)
		return 1;
	else if (x == 1)
		return 2;
	else if (x == 0)
		return 3;
	return 0;
}

int main(int argc, char *argv[])
{
	freopen ("debate.in", "r", stdin);
	freopen ("debate.out", "w", stdout);
	int n;
	read(n);
	int tot = 0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		read(x), read(y);
		if (x == 11)
			ans += (long long)y, ++tot;
		else q[ha(x)].push(y);
	}
	while (q[1].size() && q[2].size())
		ans += (long long)q[1].top() + q[2].top(), q[1].pop(), q[2].pop();
	while (q[1].size())
		q[3].push(q[1].top()), q[1].pop();
	while (q[2].size())
		q[3].push(q[2].top()), q[2].pop();
	for (int i = 1; i <= tot; ++i)
	{
		ans += (long long)q[3].top();
		q[3].pop();
		if (!q[3].size())
			break;
	}
	printf ("%lld\n", ans);
	return 0;
}
