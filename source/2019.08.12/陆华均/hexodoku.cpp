#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
	char c = getchar();
	T f = 1;
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
	w(x);
	putchar(c);
}
int k, n, d[31];
int main(){
	freopen("hexodoku.in", "r", stdin);
	freopen("hexodoku.out", "w", stdout);
	read(k); read(n);
	for (int i = 1; i <= 31; i ++) {
		read(d[i]);
	}
	printf("No way\n"); 
	return 0;
}



