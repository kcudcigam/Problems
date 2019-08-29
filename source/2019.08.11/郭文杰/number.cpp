#include<bits/stdc++.h>

#define FILE "number"

using namespace std;

template<typename T>
inline void read(T& x)
{
	bool f = 0; x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 1;
	for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
	if (f) x = -x;
}

int t;

int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	read(t);
	for(auto i = 0ll; i < t; ++i)
		printf("1\n");
	return 0;
}
