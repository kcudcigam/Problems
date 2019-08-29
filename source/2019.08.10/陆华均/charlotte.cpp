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
struct info{
	int t, x, y;
}pl[100005];
int main(){
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	int T;
	read(T);
	while(T --) {
		int n, nx = 0, ny = 0, nt = 0;
		read(n);
		bool flg = true;
		for (int i = 1; i <= n; i ++) {
			read(pl[i].t); read(pl[i].x); read(pl[i].y);
		}
		for (int i = 1; i <= n; i ++) {
			int xi = pl[i].x, yi = pl[i].y, ti = pl[i].t;
			int z = abs(xi - nx) + abs(yi - ny);
			if ((z > ti - nt)|| (z < ti - nt && (ti - nt - z) % 2 != 0)) {
				flg = false;
				break;
			}
			nx = xi;
			ny = yi;
			nt = ti;
		}
		if (flg) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}



