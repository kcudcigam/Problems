#include<bits/stdc++.h>

#define FILE "town"

using namespace std;

static struct Read
{
	template<typename T>
	Read& operator>>(T& x)
	{
		int f = 1; x = 0; char c = getchar();
		for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
		for (;  isdigit(c); c = getchar()) x = x * 10 + c - '0';
		x *= f;
		return *this;
	}
} read;

int n, pre[300001];
vector<int> g[300001];
bool book[300001];
vector<int> q;
unordered_set<int> s;

void bfs(int cnt, int stp, int& ans)
{
	while (cnt--)
	{
		int v = q[0];
		q.erase(q.begin());
		book[v] = 1;
		for (auto& i:g[v])
			if (!book[i])
				q.emplace_back(i);
	}
	if (!q.empty())
		bfs(q.size(), stp + 1, ans);
	ans = max(ans, stp);
}

inline int find(int x)
{
	return pre[x] == x ? x : pre[x] = find(pre[x]);
}

int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	read >> n;
	for (auto i = 1; i <= n; ++i)
		pre[i] = i;
	for (int i = 1; i < n; ++i)
	{
		int a, b, ans = 0;
		read >> a >> b;
		pre[find(a)] = find(b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		s.insert({a, b});
		for (auto& i:s)
			if (find(i) == find(b))
			{
				q.clear();
				q.emplace_back(i);
				memset(book, 0, sizeof(book));
				bfs(1, 0, ans);
			}
		printf("%d\n", ans);
	}
	return 0;
}
