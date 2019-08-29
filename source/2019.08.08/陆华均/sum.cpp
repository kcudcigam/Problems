#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	T  f = 1;
	char c = getchar();
	x = 0;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
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
int n;
long long ans, head, tail, sum, num, a[100005];
inline void solve1() {
	int s = 0;
	for (int i = 1; i <= n; i ++) {
		if (s + a[i] > 0) {
			s += a[i];
			if (s > ans) {
				ans = s;
				tail = i;
			}
		}
		else {
			while(a[i] <= 0 && i <= n) i ++;
			s = a[i];
			if (s > ans) {
				head = tail = i;
				ans = s;
			}
		}
	}
	if (tail == 0) {
		ans = -1e9;
		for (int i = 1; i <= n; i ++) {
			ans = max(ans, a[i]);
		}
	}
}
inline void solve2(int l, int r) {
	long long s = 0, t = 0;
	bool flg = false;
	for (int i = l; i <= r; i ++) {
		if (s + a[i] > 0) {
			s += a[i];
			flg = true;
		}
		else {
			while(a[i] <= 0 && i <= r) i ++;
			s = a[i];
		}
		if (s > t) t = s;
	}
	if (!flg) {
		t = -1e9;
		for (int i = l; i <= r; i ++) {
			t = max(sum, a[i]);
		}
	}	
	sum = max(sum, t);
}
int main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i ++) {
		read(a[i]);
	}
	solve1();
	sum = -1e9;
	solve2(1, head - 1); solve2(tail + 1, n);
	for (int i = head; i <= tail; i ++) {
		num = max(num, -a[i]);
	}
	if (head == tail) ans += sum;
	else ans += max(num, sum);
	write(ans, '\n');
	return 0;
}


