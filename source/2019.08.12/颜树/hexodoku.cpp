#include <bits/stdc++.h>
#define pb emplace_back
#define ll long long
using namespace std;
template <typename T> void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
const int N = 50;
int K, n, used[N];
vector <int> e[N]; int a[N];
void link(vector <int> a) {
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a.size(); j++)
			if (i != j) e[a[i]].pb(a[j]);
}
void dfs(int x) {
	if (x == 32) {
		n--;
		if (!n) {
			puts("Found");
			for (int i = 1; i <= 31; i++)
				cout << a[i] << (i == 31 ? '\n' : ' ');
			exit(0);
		}
		return;
	}
	if (a[x]) return dfs(x + 1), void();
	int s = 0;
	for (int y : e[x]) s |= used[y];
	for (int i = 1; i <= K; i++) {
		if (s & (1 << i - 1)) continue;
		a[x] = i, used[x] = 1 << i - 1;
		dfs(x + 1), a[x] = 0, used[x] = 0;
	}
}
int main() {
	freopen("hexodoku.in", "r", stdin);
	freopen("hexodoku.out", "w", stdout);
	read(K), read(n);
	link({1, 2}), link({3, 4, 5, 6, 7}), link({8, 9, 10, 11, 12, 13});
	link({30, 31}), link({25, 26, 27, 28, 29}), link({19, 20, 21, 22, 23, 24});
	link({14, 15, 16, 17, 18});
	link({1, 2, 4, 5, 6, 10, 11}), link({3, 4, 8, 9, 10, 14, 15});
	link({6, 7, 11, 12, 13, 17, 18}), link({14, 15, 19, 20, 21, 25, 26});
	link({17, 18, 22, 23, 24, 28, 29}), link({21, 22, 26, 27, 28, 30, 31});
	link({10, 11, 15, 16, 17, 21, 22});
	link({3, 8}), link({1, 4, 9, 14, 19}), link({2, 5, 10, 15, 20, 25});
	link({6, 11, 16, 21, 26}), link({7, 12, 17, 22, 27, 30});
	link({13, 18, 23, 28, 31}), link({24, 29});
	link({7, 13}), link({2, 6, 12, 18, 24}), link({1, 5, 11, 17, 23, 29});
	link({4, 10, 16, 22, 28}), link({3, 9, 15, 21, 27, 31});
	link({8, 14, 20, 26, 30}), link({19, 25});
	for (int i = 1; i <= 31; i++) {
		read(a[i]);
		if (a[i]) used[i] |= 1 << a[i] - 1;
	}
	dfs(1); puts("No way");
	return 0;
}
