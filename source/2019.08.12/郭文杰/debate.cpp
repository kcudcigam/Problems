#include<bits/stdc++.h>

#define FILE "debate"

using namespace std;

typedef long long ll;

struct Node
{
	int w;
	bool a:1, b:1;
} p[400005];

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
	inline Read& operator>>(Node& x);
} read;

int n, cnt, cnt_;
ll sum; bool f;
priority_queue<Node> q, q1, q2;

inline bool operator<(const Node& a, const Node& b)
{
	return a.w < b.w ? 1 : 0;
}

int main()
{
	freopen(FILE".in",  "r", stdin);
	freopen(FILE".out", "w", stdout);
	read >> n;
	for (int i = 1; i <= n; ++i)
	{
		read >> p[i];
		if (p[i].a == 1 && p[i].b == 1)
			++cnt, sum += p[i].w;
		else if (p[i].a == 1 && p[i].b == 0)
			q1.push(p[i]);
		else if (p[i].a == 0 && p[i].b == 1)
			q2.push(p[i]);
		else q.push(p[i]);
	}
	cnt_ = q1.size();
	if (q1.size() > q2.size())
		f = 1, cnt_ = q2.size();
	while (cnt_--)
	{
		sum += q1.top().w + q2.top().w;
		q1.pop(), q2.pop();
	}
	while (cnt--)
	{
		int a = 0, b = 0;
		priority_queue<Node> &Q = (f ? q1 : q2);
		if (!Q.empty())
			a = Q.top().w;
		if (!q.empty())
			b = q.top().w;
		if (a > b)
		{
			sum += a;
			if (!Q.empty())
				Q.pop();
		}
		else
		{
			sum += b;
			if (!q.empty())
				q.pop();
		}
	}
	cout << sum;
	return 0;
}

inline Read& Read::operator>>(Node& x)
{
	char c;
	while (!isdigit(c = getchar()));
	x.a = c - '0';
	x.b = getchar() - '0';
	read >> x.w;
	return *this;
}
