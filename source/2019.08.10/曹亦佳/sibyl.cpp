#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 300010;
vector<int>v[MAXN];
int n, m, q, a[MAXN];

void AddEdge(int x, int y){
	v[x].push_back(y);
}

int main() {
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	read(n);read(m);read(q);
	for (int i = 1; i <= m; ++i) {
		int x, y; read(x); read(y);
		AddEdge(x, y); AddEdge(y, x);
	}
	for (int i = 1; i <= n; ++i) unique(v[i].begin(), v[i].end());
	for (int i = 1; i <= q; ++i) {
		int op;read(op);
		if (op == 1) {
			int x, y; read(x);read(y);
			a[x] += y;
		}
		else {
			int x; read(x);
			int ans = a[x];
			for (int j = 0; j < v[x].size(); ++j) ans += a[v[x][j]];
			cout << ans << endl;
		}
	}

	return 0;
}

