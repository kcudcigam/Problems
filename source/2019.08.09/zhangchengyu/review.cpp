#include <bits/stdc++.h>
using namespace std;
#define mr make_pair
#define pk push_back
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
LL Y, N, M;
vector <int> e;
int main()
{
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	read(Y); N = 64, M = 1953;
	for (int i = 2; i <= 63; ++i)
		if ((Y >> (63 - i)) & 1) e.pk(i), M++;		
	cout << N << ' ' << M << '\n';
	for (int i = 2; i <= 63; ++i)
		for (int j = i + 1; j <= 64; ++j)
			cout << i << ' ' << j << '\n';
	for (int i = 0; i < e.size(); ++i)
		cout << 1 << ' ' << e[i] << '\n';
	return 0;
}
