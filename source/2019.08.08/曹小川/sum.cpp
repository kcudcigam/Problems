#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
int a[100010];
template <typename T> inline void read(T &n){
	n = 0; bool f = 1; char c;
	for (c = getchar(); !isdigit(c); c= getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	if (f == 0) n = -n;
}
template <typename T> inline void write(T n){
	if (n < 0){
		n = -n;
		putchar('-');
	}
	if (n > 9) write(n / 10);
	write(n % 10);
}
template <typename T> inline void writeln(T n){
	write(n);
	putchar('\n');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
long long qz[N], ans;
int main(){
	FO("sum");
	read(n);
	if (n == 0){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i){
		read(a[i]);
		qz[i] = qz[i - 1] + a[i];
	}
	long long minn = 0, l, ll = 0, r, maxn = LONG_LONG_MIN;
	for (int i = 1; i <= n; ++i){
		if (qz[i] - minn > maxn){
			ll = l;
			r = i;
			maxn = qz[i] - minn;
		}
		if (qz[i] < minn){
			l = i + 1;
			minn = qz[i];
		}
	}
	ans += maxn;
	minn = 0, maxn = LONG_LONG_MIN;
	for (int i = 1; i < ll; ++i){
		if (qz[i] - minn > maxn)
			maxn = qz[i] - minn;
		if (qz[i] < minn)
			minn = qz[i];
	}
	minn = 0; int sum = 0;
	for (int i = r + 1; i <= n; ++i){
		sum += a[i];
		if (sum - minn > maxn)
			maxn = sum - minn;
		if (sum < minn)
			minn = sum;
	}
	int nmaxn = 0, nminn = LONG_LONG_MAX; sum = 0;
	for (int i = ll; i < r; ++i){
		sum += a[i];
		if (sum - nmaxn < nminn)
			nminn = sum - nmaxn;
		if (sum > nmaxn)
			nmaxn = sum;
	}
	ans = max(ans + maxn, ans - nminn);
	cout << ans << endl;
	return 0;
}
