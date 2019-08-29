#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	register T f = 1;
	register char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	w(x);
	putchar(c);
}
int Log[33], ans, n, k;
inline void dfs(int dep, int sum, int t) {
	if (sum > n + ans) return;
	else if (sum >= n) {
		ans = sum - n;
		return;
	}
	if (!dep) return;
	if (sum + (Log[dep] << 1) < n) return;
	if (t < k) dfs(dep - 1, sum + Log[dep], t + 1);
	dfs(dep - 1, sum, t);
}
int main(){
	freopen("glass.in", "r", stdin);
	freopen("glass.out", "w", stdout);
	read(n); read(k);
	for (int i = 1; i <= 30; i ++) {
		Log[i] = (1 << i);
	}
	int si, sum = 0;
	for (int i = 1; i <= 30; i ++) {
		if (Log[i] >= n && Log[i - 1] < n) {
			ans = Log[i] - n;
			si = i - 1;
			break;
		}
	}
	dfs(si, 0, 0);
	write(ans, '\n');
	return 0;
}


