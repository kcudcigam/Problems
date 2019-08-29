#include<bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; char c; T f = 1;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
template <typename T> inline void write(T n){
	if (n < 0){
		putchar('-');
		n = -n;
	}
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}
template <typename T> inline void writeln(T n){
	write(n);
	putchar('\n');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int n;
LL A, B, C, D;
int a[200010], Mn[400010][20];
LL f[200010];
inline int Min(int a, int b){
	return a < b ? a : b;
}
inline int getmin(int l, int r){
	int lg = log2(r - l + 1);
	return Min(Mn[l][lg], Mn[r - (1 << lg) + 1][lg]);
}
inline LL w(LL x){
	return x * x * x * A + x * x * B + x * C + D;
}
inline LL chkmax(LL &a, LL b){
	a = a > b ? a : b;
}
int main(){
	FO("min");
	read(n), read(A), read(B), read(C), read(D);
	for (int i = 1; i <= n; ++i){
		read(a[i]);
		Mn[i][0] = a[i];
	}
	if (A == 0 && B == 0 && C <= 0){
		LL minn = INT_MAX;
		LL ans = 0;
		for (int i = 1; i <= n; ++i){
			minn = Min(minn, a[i]);
			if (w(minn) > 0){
				ans += w(minn);
				minn = INT_MAX;
			}
		}
		if (minn != INT_MAX) ans += w(minn);
		writeln(ans);
		return 0;
	}
	for (int k = 0; k <= 18; ++k)
		for (int i = n + 1; i <= 400010; ++i)
			Mn[i][k] = INT_MAX;
	Mn[0][0] = INT_MAX;
	for (int k = 1; k <= 18; ++k)
		for (int i = 0; i <= n; ++i)
			Mn[i][k] = Min(Mn[i][k - 1], Mn[i + (1 << k) - 1][k - 1]);
	memset(f, 0, sizeof f);
	f[1] = w(a[1]);
	for (int i = 2; i <= n; ++i){
		for (int j = 1; j < i; ++j)
			f[i] = chkmax(f[i], f[j] + w(getmin(j + 1, i)));
	}
	writeln(f[n]);
	return 0;
}
