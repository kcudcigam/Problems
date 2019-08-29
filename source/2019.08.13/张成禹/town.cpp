#include <bits/stdc++.h>
using namespace std;
#define pk push_back
template <typename T> void read(T &x)
{
	x = 0; int f = 1; char c = getchar();
	for ( ; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for ( ; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
const int N = 300005, LG = 18;
int f[LG + 2][N], dp[N], n, Lg[N];
vector <int> e[N];
struct node { int x, y; } a[N];
void Ade(int u, int v) { e[u].pk(v), e[v].pk(u); }
void Dfs(int x, int fa)
{
	dp[x] = dp[fa] + 1; f[0][x] = fa;
	for (int i = 1; i <= LG; ++i)
		f[i][x] = f[i - 1][f[i - 1][x]];
	for (int i = 0, v; i < e[x].size(); ++i)
		if ((v = e[x][i]) != fa) Dfs(v, x);
}
int LCA(int u, int v)
{
	if (dp[u] < dp[v]) swap(u, v);
	for (int i = dp[u] - dp[v]; i; i -= i & -i)
		u = f[Lg[i & -i] - 1][u];
	if (u == v) return u;
	for (int i = LG; i >= 0; --i)
		if (f[i][u] != f[i][v]) u = f[i][u], v = f[i][v];
	return f[0][u];
}
int fu, fv, mx, mxa, mxb, fa[N], L[N][3], A, B, C;
int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
void Insert(int u, int v)
{
	fu = gf(u), fv = gf(v); mx = 0;
	for (int i = 0; i <= 1; ++i)
	{
		A = L[fu][i];
		for (int j = 0; j <= 1; ++j)
		{
			B = L[fv][j], C = LCA(A, B);
			if (dp[A] + dp[B] - 2 * dp[C] > mx)
				mx = dp[A] + dp[B] - 2 * dp[C], mxa = A, mxb = B;
		}
	}
	if (L[fv][2] > L[fu][2]) L[fu][0] = L[fv][0], L[fu][1] = L[fv][1], L[fu][2] = L[fv][2];
	if (mx > L[fu][2]) L[fu][0] = mxa, L[fu][1] = mxb, L[fu][2] = mx;
	mx = L[fu][2]; cout << mx << '\n'; fa[fv] = fu;
}
int main()
{
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i) Lg[i] = Lg[i - 1] + (i == (1 << Lg[i - 1]));
	for (int i = 1, x, y; i < n; ++i)
		read(x), read(y), Ade(x, y), a[i] = (node) { x, y };
	Dfs(1, 0);
	for (int i = 1; i <= n; ++i) L[i][0] = L[i][1] = fa[i] = i;
	for (int i = 1; i < n; ++i)
		Insert(a[i].x, a[i].y);
	return 0;
}

