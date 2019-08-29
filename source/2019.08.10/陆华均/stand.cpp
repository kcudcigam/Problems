#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	T f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f= -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
template <typename T> inline void w(T x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}
template <typename T> inline void write(T x, char c) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	w(x);
	putchar(c);
}
long long fun[6];
inline long long f(long long x) {
	long long s = 0;
	for (int i = 1; i <= 5; i ++) {
		if (fun[i]) {
			long long mi = 1;
			for (int j = 1; j <= i; j ++) mi *= x;
			s += mi * fun[i];
		}
	}
	return s;
}
int lr[300], rr[300], vis[10000007];
bool us[300];
int main(){
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	int n, m, sum = 0, pos = 0;
	bool flg = true;
	read(n); read(m);
	for (int i = 1; i <= 5; i ++) {
		read(fun[i]);
	}
	for (int i = 1; i <= n; i ++) {
		read(lr[i]); read(rr[i]); 
		if (lr[i] != 1 || rr[i] != m) flg = false;
	}
	if (flg) {
		write(f((long long) n), '\n');
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = lr[i]; j <= rr[i]; j ++) {
			vis[j] ++;
			if (vis[j] > sum) {
				sum = vis[j];
				pos = j;
			}
		}
	}
	int ti = 0;
	long long ans = 0;
	while(ti < n) {
		ans += f((long long) sum);
		if (sum + ti == n) break;
		for (int i = 1; i <= n; i ++) {
			if (!us[i] && lr[i] <= pos && rr[i] >= pos) {
				for (int j = lr[i]; j <= rr[i]; j ++) {
					vis[j] --;
				}
				us[i] = true;
				ti ++;
			}
		}
		sum = 0;
		for (int i = 1; i <= m; i ++) {
			if (sum < vis[i]) {
				sum = vis[i];
				pos = i;
			}
		}
	}
	write(ans, '\n'); 
	return 0;
}



