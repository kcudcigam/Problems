#include <bits/stdc++.h>

int ri() {
	char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
	for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
const int N = 5e5+50;

int a[N], b[N];

int kth(int ta[], int sa, int tb[], int sb, int k) {
	if (sa > sb) return kth(tb, sb, ta, sa, k);
	if (sa == 0) return tb[k];
	if (k == 1) return std::min(ta[1], tb[1]);
	int ka = std::min(sa, k/2), kb = k - ka;
	if (ta[ka] < tb[kb]) return kth(ta+ka, sa-ka, tb, sb, k-ka);
	return kth(ta, sa, tb+kb, sb-kb, k-kb);
}

int query(int la, int ra, int lb, int rb) {
	int sa = ra-la+1, sb = rb-lb+1, siz = sa + sb;
	if (siz & 1) return kth(a+la-1, sa, b+lb-1, sb, siz/2+1) * 2;
	int v1 = kth(a+la-1, sa, b+lb-1, sb, siz/2);
	int v2 = kth(a+la-1, sa, b+lb-1, sb, siz/2+1);
	return v1 + v2;
}

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	int n, m;
	n = ri(); m = ri();
	for (int i = 1; i <= n; i++) a[i] = ri();
	for (int i = 1; i <= n; i++) b[i] = ri();
	for (int opt; m--; ) {
		opt = ri();
		if (opt == 2) {
			int la = ri(), ra = ri(), lb = ri(), rb = ri();
			printf("%d\n", query(la, ra, lb, rb) / 2);
		} else {
			int p = ri(), pos = ri(), val = ri();
			if (p == 0) a[pos] = val;
			else b[pos] = val;
		}
	}
	return 0;
}
/*
5 5
12 41 46 68 69
35 61 82 84 96
2 1 4 3 5
1 0 5 75
2 2 4 3 4
2 3 4 1 5
2 1 4 2 4
*/

