#include<bits/stdc++.h>
#define N 500010
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; char c;
	for (c = getchar(); !isdigit(c); c = getchar());
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
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
int n, m, i;
int a[N], b[N], fs[1010];
inline int ef(int x, int l, int r, int flg){
	int mid;
	while (l < r - 1){
		mid = l + r >> 1;
		if (flg == 0){
			if (a[mid] <= x) l = mid;
			else r = mid - 1;
		}
		else{
			if (b[mid] <= x) l = mid;
			else r = mid - 1;
		}
	}
	return l; 
}
int main(){
	FO("median");
	read(n), read(m);
	for (i = 1; i <= n; ++i)
		read(a[i]);
	for (i = 1; i <= n; ++i)
		read(b[i]);
	for (i = 1; i <= m; ++i){
		int opt;
		read(opt);
		if (opt == 1){
			int x, y, z;
			read(x), read(y), read(z);
			if (x == 0) a[y] = z;
			else b[y] = z;
		}
		else{
			int l1, r1, l2, r2, lgt, ans, cnt, tot = 0, lenth;
			memset(fs, 0, sizeof fs);
			read(l1), read(r1), read(l2), read(r2);
			lenth = (r1 - l1) + 1 + (r2 - l2) + 1;
			for (int k = l1; k <= r1; ++k)
				fs[++tot] = a[k];
			for (int k = l2; k <= r2; ++k)
				fs[++tot] = b[k];
			sort(fs + 1, fs + tot + 1);
			cout << fs[tot / 2 + 1] << endl;
		}
	}
	return 0;
}
