#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = LLONG_MIN / 2;
const int N = 1000010;
template <typename T> void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) { a = a * 10 + c - '0'; c = getchar(); }
	a *= f;
}

int A, B, C, D;
int n, top, Max[N];
struct qujian {
	int Maxf, Min;
};
int a[N], f[N];
qujian stk[N];

int F(int x) {
	return ((A * x + B) * x + C) * x + D;
}

signed main() {
	freopen("min.in", "r", stdin); freopen("min.out", "w", stdout);
	read(n); read(A); read(B); read(C); read(D);
	for (int i=1;i<=n;++i) read(a[i]);
	f[1] = F(a[1]); Max[0] = Max[1] = inf;
	stk[++top] = (qujian){inf, a[1]};
	for (int i=2;i<=n;++i) {
		int Fx = F(a[i]);
		qujian tmp = (qujian){inf, a[i]};
		while (top && stk[top].Min >= a[i]) {
			tmp.Maxf = max(stk[top].Maxf, tmp.Maxf);
			--top;
		}
		f[i] = max(tmp.Maxf + Fx, max(Max[top], f[i - 1] + Fx));
		int las = tmp.Maxf;
		tmp.Maxf = max(tmp.Maxf, f[i]);
		stk[++top] = tmp;
		Max[top] = max(Max[top - 1], las + Fx);
	}
	cout << f[n] << endl;
	return 0;
}
