# include <bits/stdc++.h>
using namespace std;
# define mr make_pair
#define pb push_back
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const LL  infll = 0x3f3f3f3f3f3f3f3fll, INFLL = 0x7fffffffffffffffll;
template <typename T> void read(T &x)
{
	x = 0; int f = 1; char c = getchar();
	for ( ; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for ( ; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void chkmax(T &x, T y) { x = x < y ? y : x; }
template <typename T> void chkmin(T &x, T y) { x = x > y ? y : x; }
const int p = 1e9 + 7, N = 200005;
int NUM, n, m1, m2, x, y, cntl, cntp, col, ans;
bool vis[N];
struct edge { int to, w; };
vector <edge> e[N];
int ml(int x, int y) { return 1ll * x * y - 1ll * x * y / p * p; }
int ad(int x, int y) { x += y; return x >= p ? x - p : x < 0 ? x + p : x; }
void Ade(int u, int v, int w)
{
	e[u].pb((edge) { v, w });	
	e[v].pb((edge) { u, w });
}
void Dfs(int u)
{
	if (e[u].size() == 1) col = e[u][0].w;
	for (int i = 0, v; i < e[u].size(); ++i)
		if (!vis[v = e[u][i].to]) vis[v] = 1, cntp++, Dfs(v);
}
int Pow(int x, int k)
{
	int d = 1;
	for ( ; k; x = ml(x, x), k >>= 1)
		if (k & 1) d = ml(d, x);
	return d;
}
int JC[N], P2[N], cnt0[N], cnt1[N], cnt2[N], cnt3[N];
int main()
{
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	read(NUM), read(n), read(m1), read(m2);
	for (int i = 1; i <= m1; ++i)
		read(x), read(y), Ade(x, y, 0);
	for (int i = 1; i <= m2; ++i)
		read(x), read(y), Ade(x, y, 1);
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			vis[i] = 1, cntp = 1, col = 2, cntl = 0;
			Dfs(i);
			if (col == 2) cntl = cntp;
			else cntl = cntp - 1;
			if (cntp == cntl) cnt2[cntp]++;
			if ((cntp & 1) && cntp != cntl) cnt3[cntp]++;
			if ((cntp % 2 == 0) && cntp != cntl && col == 1) cnt1[cntp]++;
			if ((cntp % 2 == 0) && cntp != cntl && col == 0) cnt0[cntp]++;
		}
	JC[0] = P2[0] = 1; ans = 1;
	for (int i = 1; i <= n; ++i) JC[i] = ml(JC[i - 1], i);
	for (int i = 1; i <= n; ++i) P2[i] = ml(P2[i - 1], 2);
	for (int i = 1; i <= n; ++i)
		ans = ml(ans, JC[cnt0[i]]), ans = ml(ans, JC[cnt1[i]]), ans = ml(ans, JC[cnt2[i]]), ans = ml(ans, JC[cnt3[i]]);
	for (int i = 1; i <= n; ++i)
	{
		ans = ml(ans, P2[cnt0[i]]);
		ans = ml(ans, P2[cnt1[i]]);
		ans = ml(ans, Pow(i, cnt2[i]));
	}
	ans = ad(JC[n], -ans);
	cout << ans << '\n';
	return 0;
}

