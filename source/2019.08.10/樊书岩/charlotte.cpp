#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define LD long double
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {
		if(c == '-') f = -f;
	}
	for(; isdigit(c); c = getchar()) {
		x = (x << 3) + (x << 1) + c - '0';
	}
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {write(x); putchar(sp);}
const int maxn = 100010;
int T, n, t[maxn], x[maxn], y[maxn];
int manhattan(int x, int y, int x1, int y1) {
	return abs(x - x1) + abs(y - y1);
}
int main() {
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	read(T);
	while(T--) {
//		memset(t, 0, sizeof(t));
//		memset(x, 0, sizeof(x));
//		memset(y, 0, sizeof(y));
		read(n);
		int nx = 0, ny = 0, nt = 0;
		int px = 0, py = 0, pt = 0;
		bool flg = true;
		_rep(i, 1, n) {
			px = nx; py = ny; pt = nt;
			read(nt); read(nx); read(ny); 
			int dist = manhattan(nx, ny, px, py);
			if(dist > nt - pt) {
				flg = false;
			}
			if(dist < nt - pt && (nt - pt - dist) % 2) {
				flg = false;
			}
		//	cout << flg << " " << nt - pt << endl;
		}
		puts(flg? "Yes" : "No");
	}
	return 0;
}

