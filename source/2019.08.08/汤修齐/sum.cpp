#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n;
int a[maxn], Maxl[maxn], Maxr[maxn];

int main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = n; i > 1; i--){
		Maxr[i] = a[i];
		if (Maxr[i + 1] > 0) Maxr[i] += Maxr[i + 1];
	}
	for (int i = n - 1; i > 1; i--) Maxr[i] = max(Maxr[i], Maxr[i + 1]);
	for (int i = 1; i < n; i++){
		Maxl[i] = a[i];
		if (Maxl[i - 1] > 0) Maxl[i] += Maxl[i - 1];
	}
	for (int i = 2; i < n; i++) Maxl[i] = max(Maxl[i], Maxl[i - 1]);
	int ans = INT_MIN;
	for (int i = 1; i < n; i++) ans = max(ans, Maxl[i] + Maxr[i + 1]);
	printf("%d\n", ans);
	return 0;
}
