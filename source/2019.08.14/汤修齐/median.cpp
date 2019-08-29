#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;

int read() {
	char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
	for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}

int n, m;
int a[maxn], b[maxn];

inline int Find(int l, int r, int val, int a[]){
	int mid; r++;
	while (l + 1 < r){
		mid = l + r >> 1;
		if (a[mid] <= val) l = mid;
		else r = mid;
	}
	return l;
}

inline int query(int l1, int r1, int l2, int r2){
	int cnt = 0, len = (r1 - l1 + r2 - l2 + 3) >> 1, tl;
	while (l1 <= r1 && l2 <= r2){
		if (a[l1] < b[l2]){
			tl = Find(l1, r1, b[l2], a);
			cnt += tl - l1 + 1;
			if (cnt >= len) return a[tl - (cnt - len)];
			l1 = tl + 1;
		} else {
			tl = Find(l2, r2, a[l1], b);
			cnt += tl - l2 + 1;
			if (cnt >= len) return b[tl - (cnt - len)];
			l2 = tl + 1;
		}
	}
	return l1 <= r1 ? a[l1 + len - cnt - 1] : b[l2 + len - cnt - 1];
}

int main(){
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	
	for (int i = 1; i <= m; i++){
		int opt = read();
		if (opt == 1){
			int x = read(), y = read(), z = read();
			if (x) b[y] = z;
			else a[y] = z;
		} else {
			int l1 = read(), r1 = read(), l2 = read(), r2 = read();
			printf("%d\n", query(l1, r1, l2, r2));
		}
	}
	return 0;
}
