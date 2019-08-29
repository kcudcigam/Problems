#include<bits/stdc++.h>

#define FILE "median"
#define N 500005

using namespace std;

typedef pair<int, int> P;

inline int read()
{
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x;
}

int n, m;
P a[N], b[N];

int lower(P x[], int sta, int end, int& key)
{
	int tmp = sta - 1;
	while (sta <= end)
	{
		int mid = sta + end >> 1;
		if (x[mid].first <= key)
			sta = mid + 1;
		else
			end = mid - 1;
	}
	return x[end].first <= key ? x[end].second : tmp;
}

void solve(P x[], P y[], int& l1, int& r1, int& l2, int& r2, int& mid)
{
	int ll = l1, lr = r1;
	while (1)
	{
		int rl = l2, rr = r2;
		int mid1 = ll + lr >> 1, size;
		while (rl <= rr)
		{
			int mid2 = rl + rr >> 1;
			size = lower(x, l1, r1, y[mid2].first) - l1 + mid2 - l2 + 2;
			if (size > mid)
				rr = mid2 - 1;
			else if (size < mid)
				rl = mid2 + 1;
			else
			{
				printf("%d\n", y[mid2]);
				return;
			}
		}
		size = lower(y, l2, r2, x[mid1].first) - l2 + mid1 - l1 + 2;
		if (size == mid)
		{
			printf("%d\n", x[mid1]);
			return;
		}
		if (size < mid)
			ll = mid1 + 1;
		else
			lr = mid1 - 1;
	}
}

int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = make_pair(read(), i);
	for (int i = 1; i <= n; ++i)
		b[i] = make_pair(read(), i);
	for (int i = 1; i <= m; ++i)
	{
		int k = read();
		if (k == 1)
		{
			int x = read(), y = read(), z = read();
			if (x)
				b[y].first = z;
			else
				a[y].first = z;
		}
		else
		{
			int l1 = read(), r1 = read(), l2 = read(), r2 = read();
			int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1, len = len1 + len2;
			int mid = len / 2;
			if (a[r1].first <= b[l2].first)
			{
				if (len1 > mid)
					printf("%d\n", a[l1 + mid].first);
				else
					printf("%d\n", b[l2 + mid - len1].first);
			}
			else if (a[l1].first >= b[r2].first)
			{
				if (len2 > mid)
					printf("%d\n", b[l2 + mid].first);
				else
					printf("%d\n", a[l1 + mid - len2].first);
			}
			else if (len1 > len2)
				solve(b, a, l2, r2, l1, r1, ++mid);
			else
				solve(a, b, l1, r1, l2, r2, ++mid);
		}
	}
	return 0;
}
