#include<cstdio>
#include<cctype>
#include<algorithm>

int T, n, t, x, y, nowx, nowy, dis, lastt;
bool flag;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

int main() {
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	T = read();
	for (; T; T--) {
		n = read(); nowx = 0; nowy = 0; flag = 1;
		lastt = 0;
		for (int i = 1; i <= n; ++i) {
			t = read(); x = read(); y = read();
			dis = abs(x - nowx) + abs(y - nowy);
			if (t < dis) flag = 0;
			else
			if (abs(abs(t - lastt) - dis) & 1) flag = 0;
			nowx = x; nowy = y; lastt = t;
		}
		if (flag) puts("Yes"); else puts("No");
	}
	return 0;
}
