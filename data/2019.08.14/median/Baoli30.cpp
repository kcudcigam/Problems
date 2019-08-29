#include<cstdio>
#include<algorithm>
const int N = 1e5 + 10;
int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(f == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int a[N], b[N], t[N];
void Solve(int l, int r, int l1, int r1) {
	int p1 = l, p2 = l1, tp = 0;
	for(;p1 <= r && p2 <= r1;) {
		if(a[p1] < b[p2]) t[++tp] = a[p1++];
		else t[++tp] = b[p2++];
	}
	for(;p1 <= r;) t[++tp] = a[p1++];
	for(;p2 <= r1;) t[++tp] = b[p2++];
	printf("%d\n", t[tp / 2 + 1]);
}
int main() {
	freopen("median.in","r",stdin);
	freopen("Baoli30.out","w",stdout);
	int n = ri(), m = ri();
	for(int i = 1;i <= n; ++i) a[i] = ri();
	for(int i = 1;i <= n; ++i) b[i] = ri();
	for(;m--;) {
		int op = ri();
		if(op == 1) {
			int w = ri(), x = ri(), y = ri();
			!w ? a[x] = y : b[x] = y;
		} 
		else {
			int l = ri(), r = ri(), l1 = ri(), r1 = ri();
			Solve(l, r, l1, r1);
		}
	}
	return 0;
}
