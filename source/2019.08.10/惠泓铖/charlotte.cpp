#include <bits/stdc++.h>
using namespace std;

int T, n, t[100001], x[100001], y[100001], tmp = 0;

int main(){
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		t[0] = x[0] = y[0] = tmp = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d%d%d", &t[i], &x[i], &y[i]);
			int s = abs(y[i] - y[i - 1]) + abs(x[i] - x[i - 1]);
			int tt = t[i] - t[i - 1];
			if (s > tt || (s - tt) % 2)	tmp = 1;
		}
		if (tmp) printf("No\n");
		else printf("Yes\n"); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
