#include <bits/stdc++.h>
using namespace std;

int n, m, q, g[3001][3001], a[300005], t[3001];

int main(){
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	memset(a, 0, n + 1);
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][++t[x]] = y;
		g[y][++t[y]] = x;
	}
	for (int i = 1; i <= q; i++){
		int typ;
		scanf("%d", &typ);
		if (typ){
			int x, y;
			scanf("%d%d", &x, &y);
			a[x] += y;
			for (int j = 1; j <= t[x]; j++){
				a[g[x][j]] += y;
			}
		}else{
			int x;
			scanf("%d", &x);
			printf("%d\n", a[x]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
