#include<bits/stdc++.h>

#define FILE "sibyl"

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

long long read()
{
	bool f = 0; int x = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 1;
	for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? -x : x;
}

int n, m, q;
vector<int> g[300005];
unordered_map<int, long long> cnt;

long long search(int x)
{
	int ans = cnt[x];
	for (auto& i:g[x])
		ans += cnt[i];
	return ans;
}

int main()
{
	freopen(FILE".in" , "r", stdin);
	freopen(FILE".out", "w", stdout);
	read(n, m, q);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		read(u, v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for (int i = 0; i < q; ++i)
	{
		int t, x;
		read(t, x);
		if (t)
			cnt[x] += read();
		else
			printf("%lld\n", search(x));
	}
	return 0;
}
