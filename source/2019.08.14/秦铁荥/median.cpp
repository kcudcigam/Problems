#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

int rd(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int N = 1e6 + 10;
int n, m, a[N], b[N];
int u, v, w, x, op, g;
int l, r, mid, len, ans;

inline int check(int xx) {
	int y = len - xx + w - 1;
	if (xx > len) return 1;
	if (y > x) return 0;
	xx = xx + u - 1;
	if (xx < u && b[y] <= a[u]) {ans = b[y]; return 2;}
	if (y < w && a[xx] <= b[w]) {ans = a[xx]; return 2;}
	if (a[xx] < b[y]) {
		if (xx < v && a[xx + 1] < b[y]) return 0;
		ans = b[y];
		return 2;
	} else if (a[xx] == b[y]) {
		ans = a[xx];
		return 2;
	} else{
		if (y < x && a[xx] > b[y + 1]) return 1;
		ans = a[xx];
		return 2;
	}
}

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n = rd(), m = rd();
	fox (i, 1, n) a[i] = rd();
	fox (i, 1, n) b[i] = rd();
	
	while (m--) {
		op = rd();
		if (op == 1) {
			u = rd(), v = rd(), w = rd();
			if (u == 0) a[v] = w;
			else b[v] = w;
		} else {
			u = rd(), v = rd(), w = rd(), x = rd();
			len = (v - u + x - w + 3) / 2, l = 0, r = v - u + 1;
			while (l <= r) {
				mid = l + r >> 1;
				g = check(mid);
				if (g == 2) break;
				if (g == 0) l = mid + 1;
				if (g == 1) r = mid - 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
