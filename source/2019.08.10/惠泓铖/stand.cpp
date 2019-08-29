#include <bits/stdc++.h>
using namespace std;

int n, m, l[251], r[251], a[1000001], ans, k[6];

int main(){
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	scanf("%d%d%d%d%d%d%d", &n, &m, &k[1], &k[2], &k[3], &k[4], &k[5]);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (i >= l[j] && i <= r[j]) a[i] ++;
		}
	}
	sort(a+1, a+m+1);
	for (int t = m; t > 0, n > 0; t--){
		while (n - a[t] < 0) t--;
		n -= a[t];
		ans += k[1] * a[t] + k[2] * a[t] * a[t] + k[3] * a[t] * a[t] * a[t] + k[4] * a[t] * a[t] * a[t] * a[t] + k[5] * a[t] * a[t] * a[t] * a[t] * a[t];
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
