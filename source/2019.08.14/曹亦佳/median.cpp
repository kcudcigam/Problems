#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 5e5 + 10;
int n, m, a[MAXN], b[MAXN];

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= n; ++i) read(b[i]);

	for (int i = 1; i <= m; ++i) {
		int op; read(op);
		if (op == 1) {
			int x, y, z; read(x); read(y); read(z);
			if (x == 0) a[y] = z;
			else b[y] = z;
		}
		else {
			int l1, r1, l2, r2; read(l1); read(r1); read(l2); read(r2);
			
			int x = (r1 - l1 + r2 - l2) / 2 + 1, cnt = 0;
			while (cnt < x) {
				if (a[r1] > b[r2]) r1--;
				else r2--;
				cnt++;
			}
			
			cout << max(a[r1], b[r2]) << endl; 
		}
	}			
	
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int MAXN = 5e5 + 10;
int n, m, a[MAXN], b[MAXN];

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= n; ++i) read(b[i]);
//	cerr <<MAXN;
	for (int i = 1; i <= m; ++i) {
		int op; read(op);
		if (op == 1) {
			int x, y, z; read(x); read(y); read(z);
			if (x == 0) a[y] = z;
			else b[y] = z;
		}
		else {
			int l1, r1, l2, r2; read(l1); read(r1); read(l2); read(r2);
			int x = (r1 - l1 + r2 - l2) / 2 + 1, cnt = 0;
			while (cnt < x && l1 + 1 < r1 && l2 + 1 < r2) {
				int mid1 = l1 + r1 >> 1, mid2 = l2 + r2 >> 1;
				if (a[mid1] < b[mid2]) {cnt += mid1 - l1; l1 = mid1; r2 = mid2;}
				else {cnt += mid2 - l2; r1 = mid1; l2 = mid2;}
			}
			while (cnt < x) {
				cnt++;
				if (l1 > r1) {l2++; continue;}
				if (l2 > r2) {l1++; continue;}
				if (a[l1] > a[l2]) l2++;
				else l1++;
			}
			cout << min(a[l1], a[l2]) << endl;
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

