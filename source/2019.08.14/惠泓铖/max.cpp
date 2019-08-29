#include <bits/stdc++.h>
using namespace std;

int n, m, q, x[100001], y[100001], p[100001], l[100001], r[100001], ans;

int qread() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

int main(){
	freopen("max.in", "r", stdin);
	freopen("max.out", "w", stdout);
	n = qread(), m = qread(), q = qread();
	for (int i = 1; i <= n; i++){
		x[i] = qread(), y[i] = qread(), p[i] = qread();
	}
	for (int i = 1; i <= q; i++){
		l[i] = qread(), r[i] = qread();
		ans += r[i] - l[i] + 1;
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
