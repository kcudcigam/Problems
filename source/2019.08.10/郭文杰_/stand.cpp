#include<bits/stdc++.h>

#define FILE "stand"

using namespace std;

typedef pair<int, int> P;

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

int n, m, cf[10000005];
size_t a[6];
vector<P> v;
long long ans;

inline bool cmp(P a, P b)
{
	if (a.second < b.second)
		return 1;
	else if (a.second > b.second)
		return 0;
	return a.first < b.first ? 1 : 0;
}

int main()
{
	freopen(FILE".in" , "r", stdin);
	freopen(FILE".out", "w", stdout);
	read(n,m);
	for (int i = 1;i <= 5; ++i)
		read(a[i]);
	for (int i = 1; i <= n; ++i)
	{
		int x,y;
		read(x, y);
		v.emplace_back(make_pair(x, y));
	}
	sort (v.begin(), v.end(), cmp);
	while (!v.empty())
	{
		int Max = 0, pos = 0, sum = 0;
		for (auto& i:v)
			++cf[i.first], --cf[i.second+1];
		for (auto i = v[0].first; i <= v.back().second; ++i)
		{
			sum += cf[i];
			if (sum > Max)
				Max = sum, pos = i;
		}
		for (int i = 1; i <= 5; ++i)
			ans += pow(Max, i) * a[i];
		for (auto i = v.begin(); i != v.end();)
			if (i->first <= pos && i->second >= pos)
				v.erase(i);
			else ++i;
	}
	cout << ans;
	return 0;
}
