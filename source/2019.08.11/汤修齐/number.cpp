#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5, maxn = 3e5 + 10;

int cnt[maxn], f[maxn], tot;

void dfs(int x, int a, int b){
	if (x > MAX || f[x] == 1) return;
	cnt[++tot] = x;
	f[x] = 1;
	if (a != -1){
		dfs(x * 10 + a, a, b);
		if (b != -1) dfs(x * 10 + b, a, b);
		else for (int i = 0; i <= 9; i++)
			if (i != a) dfs(x * 10 + i, a, i);
	} else for (int i = 0; i <= 9; i++)
		if (i != a) dfs(x * 10 + i, i, b);
}

void work(){
	int n;
	scanf("%d", &n);
	if (f[n] <= 2){
		printf("%d\n", f[n]);
		return;
	}
	int ans = INT_MAX;
	for (int i = 1; i <= tot; i++)
		if (n > cnt[i]) 
			ans = min(ans, f[n - cnt[i]] + 1);
	printf("%d\n", ans);
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T;
	scanf("%d", &T);
	memset(f, 0x7f, sizeof f);
	dfs(0, -1, -1);
	for (int i = 1; i <= tot; i++)
		for (int j = 1; j <= tot; j++)
			if (cnt[i] + cnt[j] <= MAX)
				f[cnt[i] + cnt[j]] = min(f[cnt[i] + cnt[j]], 2);
	while (T--) work();
	return 0;
}
