#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
bool vis[MAXN];
map <pair <int, int>, int> mp;
vector <pair <int, bool>> a[MAXN];
void work(int pos, int fa, bool fc, int cnta, int cntb) {
	if (vis[pos]) {
		mp[make_pair(-cnta, -cntb)]++;
		return;
	}
	vis[pos] = true;
	for (auto x : a[pos])
		if (x != make_pair(fa, fc)) {
			work(x.first, pos, x.second, cnta + x.second, cntb + !x.second);
			return;
		}
	mp[make_pair(cnta, cntb)]++;
}
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	int num; read(num);
	int n, na, nb; read(n), read(na), read(nb);
	for (int i = 1; i <= na; i++) {
		int x, y; read(x), read(y);
		a[x].emplace_back(y, true);
		a[y].emplace_back(x, true);
	}
	for (int i = 1; i <= nb; i++) {
		int x, y; read(x), read(y);
		a[x].emplace_back(y, false);
		a[y].emplace_back(x, false);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i] && a[i].size() <= 1) work(i, 0, 0, 0, 0);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) work(i, 0, 0, 0, 0);
	int ans = 1;
	for (auto x : mp) {
		pair <int, int> tmp = x.first;
		for (int i = 1; i <= x.second; i++)
			ans = 1ll * ans * i % P;
		if (tmp.first < 0) ans = 1ll * power(2ll * -tmp.first % P, x.second) * ans % P;
		else if (tmp.first != tmp.second) ans = 1ll * power(2ll, x.second) * ans % P;
	}
	int finalans = 1;
	for (int i = 1; i <= n; i++)
		finalans = 1ll * finalans * i % P;
	writeln((finalans - ans + P) % P);
	return 0;
}
