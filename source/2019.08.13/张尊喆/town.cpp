#include<iostream>
#include<cstring>
#include<cstdio>
//#include<set>
using namespace std;
const int N = 300005;
int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

int n, tot;
int h[N], to[N<<1], ne[N<<1];
int dp[N][4];

inline void add(int x,int y) {
	ne[++tot] = h[x];
	h[x] = tot, to[tot] = y;
}
int ans;
int dfs(int x,int f) {
	dp[x][1] = dp[x][2] = 0;
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i];
		if (y == f) continue;
		int k = dfs(y, x) + 1;
		if (k > dp[x][1]) {
			dp[x][2] = dp[x][1];
			dp[x][1] = k;
		}
		else if (k > dp[x][2])
			dp[x][2] = k;
	}
	ans = max(ans, dp[x][1] + dp[x][2]);
	return dp[x][1];
}

int main() {
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n = read();
	for (int i = 1;i < n; i++) {
		int x = read(), y = read();
		add(x, y);
		add(y, x);
		ans = 0;
		dfs(x, 0);
		ans = max(ans, dp[x][1] + dp[x][2]);
		printf ("%d\n", ans);
	}
	return 0;
}
/*
5
3 5
3 4
1 2
1 3
*/
