#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	T f = 1;
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
bool us[300005], c[10];
inline void check(int x) {
	memset(c, false, sizeof(c));
	int xi = x;
	while(xi) {
		c[xi % 10] = true;
		xi /= 10;
	}
	int sum = 0;
	for (int i = 0; i <= 9; i ++) {
		if (c[i]) sum ++;
	}
	if (sum <= 2) us[x] = true; 
}
long long a[110], NUM;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t;
	read(t);
	for (int i = 1; i <= 300000; i ++) {
		check(i);
	}
	for (int i = 1; i <= t; i ++) {
		int x;
		read(x);
		if (us[x]) {
			write(1, '\n');
		}
		else {
			bool flg = false;
			for (int j = 1; j < x; j ++) {
				if (us[j] && us[x - j]) {
					flg = true;
					break;
				}
			}
			if (flg) write(2, '\n');
			else write(3, '\n');
		}		
	}
	return 0;
}

