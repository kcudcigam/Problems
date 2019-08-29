#include<bits/stdc++.h>

#define FILE "charlotte"

using namespace std;

template<typename T>
void read(T& x)
{
	bool f = 0; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 1;
	for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
	if (f) x = -x;
}

template<typename T, typename ...Args>
void read(T& x, Args&... last)
{
	bool f = 0; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 1;
	for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
	if (f) x = -x;
	read(last...);
}

int T, n, x, y, stp, t, a, b, s, pre;
bool f;

int main()
{
	freopen(FILE".in" , "r", stdin);
	freopen(FILE".out", "w", stdout);
	read(T);
	for (int i = 0; i < T; ++i)
	{
		
		read(n);
		for (int j = 0; j < n; ++j)
		{
			read(t, a, b);
			s = abs(a - x) + abs(b - y);
			stp += t - pre;
			if (s > stp || (s < stp && stp % s & 1))
				printf("No\n"), f = 1;
			else
				x = a, y = b, pre = t, stp = 0;
			if (f)
				for (++j; j < n; ++j)
					read(t, a , b);
		}
		if (!f)
			printf("Yes\n");
		x = y = stp = pre = f = 0;
	}
	return 0;
}
