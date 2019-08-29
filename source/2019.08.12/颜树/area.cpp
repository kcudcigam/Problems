#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 16384;
bitset <N> vis[N]; int ans, lg[N + 1];
int num(int x, int y) {
	if (!x && !y) return 1;
	int t = max(lg[x], lg[y]);
	if ((x >> t & 1) && (y >> t & 1)) return num(x ^ (1 << t), y ^ (1 << t)) ^ 1;
	return num(x & ~(1 << t), y & ~(1 << t));
}
void dfs(int x, int y) {
	if (!x || !y) {cout << "infinity\n"; exit(0);}
	if (vis[x][y]) return; int t = num(x, y);
	ans++, vis[x][y] = 1;
	if (num(x, y - 1) == t) dfs(x, y - 1);
	if (num(x, y + 1) == t) dfs(x, y + 1);
	if (num(x - 1, y) == t) dfs(x - 1, y);
	if (num(x + 1, y) == t) dfs(x + 1, y);
}
int main() {
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	lg[1] = 0;
	for (int i = 2; i < 16384; i++) lg[i] = lg[i >> 1] + 1;
	int x, y; cin >> x >> y; dfs(x, y), cout << ans << '\n';
	return 0;
}
