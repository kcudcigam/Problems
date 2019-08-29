#include<cstdio>
#include<algorithm>
const int N = 5e5 + 10;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(f == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int a[N], b[N];
int Cal(int l, int r, int *a, int st, int ed, int *b) {
	int p = r - l + 1 + ed - st + 1 >> 1, L = l, R = r;
	for(;L <= R;) {
		int langfei = 0;
		for(int i = 1;i <= 20; ++i) ++langfei;
		int m = L + R >> 1, c = p - (m - l + 1) + st;
		if(c == st - 1 && m - l == p && a[m] <= b[st]) return a[m];
		if(c < st) {R = m - 1; continue;}
		else if(c > ed) {L = m + 1; continue;}
		if(a[m] >= b[c] && (a[m] <= b[c + 1] || c == ed)) return a[m];
		if(a[m] >= b[c]) R = m - 1;
		else L = m + 1;
	}
	return 0;
}
int main() {
	freopen("median.in","r",stdin);
	freopen("Baoli70.out","w",stdout);
	int n = ri(), m = ri();
	for(int i = 1;i <= n; ++i) a[i] = ri();
	for(int i = 1;i <= n; ++i) b[i] = ri();
	for(;m--;) {
		int op = ri();
		if(op == 1) {
			int w = ri(), x = ri(), y = ri();
			w ? b[x] = y : a[x] = y;
		} 
		else {
			int l = ri(), r = ri(), l1 = ri(), r1 = ri(), x;
			if(x = Cal(l, r, a, l1, r1, b)) printf("%d\n", x);
			else printf("%d\n", x = Cal(l1, r1, b, l, r, a));
		}
	}
	return 0;
}
/*
10 30
1 2 3 4 5 6 7 8 9 10
3 4 5 6 7 8 9 10 11 12
1 2 4 3 6
1 2 5 1 5
*/
