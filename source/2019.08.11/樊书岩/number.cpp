#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define ULL unsigned long long
template <typename T>
inline void read(T &x) {
    x = 0;
    LL f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -f;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {
	write(x); putchar(sp);
}
int t;
LL n;
int diff_dig(LL n) {
	int has = 0, tot = 0;
	if(n == 0) tot = 1;
	while(n) {
		int a = (int)(n % 10); n /= 10;
	//	std::cout << ((has >> (a - 1)) & 1) << std::endl;
		if(((has >> (a - 1)) & 1) == 0) {
			tot++;
			if(tot > 2) return false;
			has |= (1 << (a - 1));// std::cout << a << " " << tot << " " << has << std::endl; 
		}
	}
	return true;
}
LL ns[120], digs;
LL maxN = 0;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	printf("%d\n", diff_dig(388859));
	read(t);
	_rep(i, 1, t) {
		read(ns[i]);
		maxN = std::max(ns[i], maxN);
	//	printf("%d\n", diff_dig(n));
	}
	if(maxN <= 1e13) {
		_rep(i, 1, t) {
			n = ns[i];
			if(diff_dig(n)) {
				puts("1"); continue;
			} else {
				int ans = 3;
				_rep(i, 1, n / 2) {
					if(diff_dig(i) && diff_dig(n - i)) {
						ans = 2;
						break;
					}
				}
				writesp(ans);
			}	
		}
	}
	
	return 0;
}

