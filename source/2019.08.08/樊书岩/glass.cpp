#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define LD long double
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)

using namespace std;

template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {if(c == '-') f = -f;}
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
string Binary = "";
int cnt = 0, a[34];
void split(int x) {
	Binary = ""; cnt = 0;
	while(x) {
		Binary.push_back(x % 2 + '0');
		cnt += (x % 2);
		x /= 2;
	}
	reverse(Binary.begin(), Binary.end());
}
int main() {
	freopen("glass.in", "r", stdin);
	freopen("glass.out", "w", stdout);
	int x, k;
	read(x); read(k);
	
	a[0] = 1;
	_rep(i, 1, 30) {
		a[i] = a[i - 1] * 2;
	}
	
	int j = 30;
	_rep(i, 1, k - 1) {
		for(; j >= 0; j--) {
			if(x > a[j]) {x -= a[j]; break;}
		}
	}
	
	_rep(i, 1, 30) {
		if(x - a[i] < 0) {
			write(a[i] - x); puts("");
			break;
		}
	}
	return 0;
}

