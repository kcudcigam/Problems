#include <bits/stdc++.h>
#pragma GCC optimize(3) 
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

int k, a[17];
bool v[16][16][16][16];
bool loop(int r1, int r2, int r3, int r4) {
	memset(v, 0, sizeof(v));
	v[r1][r2][r3][r4] = true;
	int killed = 0;
	while(r1 || r2 || r3 || r4) {
		killed = 0;
		if(r1) {
			r1--;
			if(r1) {
				if(r2 == 0) r2 = a[r1];
				else if(r3 == 0) r3 = a[r1];
				else if(r4 == 0) r4 = a[r1];
			} else {
				killed += 1;
			}
		}
		if(r2) {
			r2--;
			if(r2) {
				if(r1 == 0) r1 = a[r2];
				else if(r3 == 0) r3 = a[r2];
				else if(r4 == 0) r4 = a[r2];
			} else {
				killed += 1;
			}
		}
		if(r3) {
			r3--;
			if(r3) {
				if(r1 == 0) r1 = a[r3];
				else if(r2 == 0) r2 = a[r3];
				else if(r4 == 0) r4 = a[r3];
			} else {
				killed += 1;
			}
		}
		if(r4) {
			r4--;
			if(r4) {
				if(r1 == 0) r1 = a[r4];
				else if(r2 == 0) r2 = a[r4];
				else if(r3 == 0) r3 = a[r4];
			} else {
				killed += 1;
			}
		}
		if(killed == 0) return false;
		if(v[r1][r2][r3][r4] == true) return true;
		v[r1][r2][r3][r4] = true;
	}
	return false;
}
int main() {
	freopen("bob.in", "r", stdin);
	freopen("bob.out", "w", stdout);
	read(k);
	
	_rep(i, 1, k - 1) read(a[i]); 
	
	int ans = 0;
	_rep(i, 0, k) {
		_rep(j, 0, k) {
			_rep(kk, 0, k) {
				_rep(l, 0, k) {
					if(loop(i, j, kk, l) == true) {
						ans += 1;
					}
				}
			}
		}
	}
	
	write(ans);
	return 0;
}

