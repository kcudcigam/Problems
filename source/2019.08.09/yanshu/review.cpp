#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100010;
struct Node {int x, y;} a[N];
ll bit[N];
int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	ll y; cin >> y; int len = 0;
	for (int i = 2; i <= 63; i++) bit[i] = 1ll << i - 2;
	for (int i = 1; i <= 63; i++)
		for (int j = 1; j < i; j++)
			a[++len] = (Node) {j, i};
	for (int i = 63; i >= 2; i--)
		if (y >= bit[i]) y -= bit[i], a[++len] = (Node) {i, 64};
	cout << 64 << ' ' << len << '\n';
	for (int i = 1; i <= len; i++) cout << a[i].x << ' ' << a[i].y << '\n';
	return 0;
}
