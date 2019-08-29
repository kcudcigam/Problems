#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10, maxm = 1e5 + 10;

map<int, int> f[maxn];
int a[maxn];

int dfs(int num, int m){
	if (num <= 0) return 0;
	if (f[num].find(m) != f[num].end()) return f[num][m];
	int re = dfs(num - 1, m);
	if (a[num] <= m) re = max(re, dfs(num - 2, m - a[num]) + 1);
	f[num].insert(make_pair(m, re));
	return re;
}

int n, m;

int main(){
	freopen("toy.in", "r", stdin);
	freopen("toy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	printf("%d\n", dfs(n, m));
	return 0;
}
