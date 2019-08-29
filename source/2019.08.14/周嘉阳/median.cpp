#include<bits/stdc++.h>
using namespace std;

#define ri register int
const int MAX_N = 500000 + 10;
int n, m, A[MAX_N], B[MAX_N];
int tmp[MAX_N], l1, r1, l2, r2, op;

template<typename Tp> inline void read(Tp &x) {
	int minus = 1; char ch; x = 0;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') minus = -1;
	for (; isdigit(ch); ch = getchar()) x *= 10, x += ch - '0';
	x *= minus;
}

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	read(n), read(m);
	for (ri i = 1; i <= n; i++)
		read(A[i]);
	for (ri i = 1; i <= n; i++)
		read(B[i]);
	for (ri i = 1; i <= m; i++) {
		read(op);
		if (op == 2) {
			read(l1), read(r1), read(l2), read(r2);
			int f1 = l1, f2 = l2, cnt = 0, sz = r1 - l1 + r2 - l2 + 2;
//			cout << sz << " " << (sz + 1) / 2 << endl;
			while (cnt <= sz / 2) {
				if ((f1 <= r1 && A[f1] <= B[f2]) || f2 > r2) tmp[++cnt] = A[f1++];
				else tmp[++cnt] = B[f2++];
			}
//			for (int i = 1; i <= cnt; i++) printf("%d ", tmp[i]); puts("");
			printf("%d\n", tmp[cnt]);
		}
		else {
			read(l1), read(l2), read(r1);
			if (l1) B[l2] = r1;
			else A[l2] = r1;
		}
	}
	return 0;
}

