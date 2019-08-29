#include <bits/stdc++.h>
using namespace std;

int n, cmp[2001], dis[2001][2001];
int g[2001][2001];

template <typename T> void qread(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}

int dfs(int a, int b){
	int ans = 0;
	if(cmp[a] == cmp[b]){
		return 1;
	}
	for (int i = 1; i <= cmp[a]; i++){
		dis[b][g[a][i]] = min(dis[b][a] + 1, dis[b][g[a][i]]);
		ans = max(dis[b][g[a][i]], ans);
	}
	for (int i = 1; i <= cmp[b]; i++){
		dis[a][g[b][i]] = min(dis[a][b] + 1, dis[a][g[b][i]]);
		ans = max(dis[a][g[b][i]], ans);
	}
	return ans;
}

int main(){
	freopen("town.in", "r", stdin);
	freopen("town.out", "w", stdout);
	memset(g, 0, sizeof(g));
	memset(cmp, 0, sizeof(cmp));
	scanf("%d", &n);
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++){
			dis[i][j] = 2001;
		}
	}
	for (int i = 1; i < n; i++){
		int x, y;
		qread(x), qread(y);
		g[x][++cmp[x]] = y;
		g[y][++cmp[y]] = x;
		dis[x][y] = dis[y][x] = 1;
		int ans = dfs(x, y);
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
