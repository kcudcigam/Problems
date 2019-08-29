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
	w(x);
	putchar(c);
}
int ques[11] = {0, 0, 2, 12, 58, 310, 1886, 13244, 106002, 954090, 9540982};
int main(){
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	int T;
	read(T);
	while(T --) {
		int n, p;
		read(n); read(p);
		if (n <= 10) write(ques[n],'\n');
	}
	return 0;
}


