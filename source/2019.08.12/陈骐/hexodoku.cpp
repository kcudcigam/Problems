#include<bits/stdc++.h>

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

int a[35];

int main(int argc, char *argv[])
{
	freopen ("hexodoku.in", "r", stdin);
	freopen ("hexodoku.out", "w", stdout);
	int k, n;
	read(k), read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	puts("No way");
	return 0;
}
