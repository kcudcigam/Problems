#include <bits/stdc++.h>
using namespace std;
#define mr make_pair
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
int K, N, cnt, a[35];
bool E[35][35], f[35][35];
vector <int> S;
vector <int> e[35];
void Ade(int u, int v) { e[u].pb(v); }
void Add()
{
	int len = S.size();
	for (int i = 1; i < len; ++i)
		for (int j = 0; j < i; ++j)
			E[S[i]][S[j]] = 1;
}
void Prepare()
{
	S = { 1, 2 }; Add();
	S = { 3, 4, 5, 6, 7 }; Add();
	S = { 8, 9, 10, 11, 12, 13 }; Add();
	S = { 14, 15, 16, 17, 18 }; Add();
	S = { 19, 20, 21, 22, 23, 24 }; Add();
	S = { 25, 26, 27, 28, 29 }; Add();
	S = { 30, 31 }; Add();
	S = { 3, 8 }; Add();
	S = { 1, 4, 9, 14, 19 }; Add();
	S = { 2, 5, 10, 15, 20, 25 }; Add();
	S = { 6, 11, 16, 21, 26 }; Add();
	S = { 7, 12, 17, 22, 27, 30 }; Add();
	S = { 13, 18, 23, 28, 31 }; Add();
	S = { 24, 29 }; Add();
	S = { 7, 13 }; Add();
	S = { 2, 6, 12, 18, 24 }; Add();
	S = { 1, 5, 11, 17, 23, 29 }; Add();
	S = { 4, 10, 16, 22, 28 }; Add();
	S = { 3, 9, 15, 21, 27, 31 }; Add();
	S = { 8, 14, 20, 26, 30 }; Add();
	S = { 19, 25 }; Add();
	S = { 1, 2, 4, 5, 6, 10, 11 }; Add();
	S = { 3, 4, 8, 9, 10, 14, 15 }; Add();
	S = { 6, 7, 11, 12, 13, 17, 18 }; Add();
	S = { 10, 11, 15, 16, 17, 21, 22 }; Add();
	S = { 14, 15, 19, 20, 21, 25, 26 }; Add();
	S = { 17, 18, 22, 23, 24, 28, 29 }; Add();
	S = { 21, 22, 26, 27, 28, 30, 31 }; Add();
	for (int i = 1; i <= 31; ++i)
		for (int j = 1; j < i; ++j)
			if (E[i][j]) Ade(i, j);
}
void Dfs(int dep)
{
	if (cnt == N) return;
	if (dep > 31) { cnt++; return; }
	if (a[dep])
	{
		for (int i = 0; i < e[dep].size(); ++i)
			if (a[dep] == a[e[dep][i]]) return;
		Dfs(dep + 1);
		return;	
	}
	for (int i = 0; i < e[dep].size(); ++i)
		f[dep][a[e[dep][i]]] = 1;
	for (int i = 1; i <= K && cnt < N; ++i)
		if (!f[dep][i]) a[dep] = i, Dfs(dep + 1);
	if (cnt < N) a[dep] = 0;
	for (int i = 0; i < e[dep].size(); ++i)
		f[dep][a[e[dep][i]]] = 0;
}
int main()
{
	freopen("hexodoku.in", "r", stdin);
	freopen("hexodoku.out", "w", stdout);
	read(K), read(N);
	for (int i = 1; i <= 31; ++i)
		read(a[i]);
	Prepare();
	Dfs(1);
	if (cnt < N) { puts("No way"); return 0; }
	puts("Found");
	for (int i = 1; i <= 31; ++i)
		cout << a[i] << (i == 31 ? '\n' : ' ');
	return 0;
}

