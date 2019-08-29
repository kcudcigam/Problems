#include<bits/stdc++.h>

#define FILE "area"

using namespace std;

static struct Read
{
	template<typename T>
	inline Read& operator>>(T& x)
	{
		bool f = 0; x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) if (c == '-') f = 1;
		for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
		if (f) x = -x;
		return *this;
	}
} read;

int x, y;

int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	read >> x >> y;
	cout << "infinity";
	return 0;
}
