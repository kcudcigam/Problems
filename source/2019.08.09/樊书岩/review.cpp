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
LL y;
int u[5050], v[5050], tot = 0;
void writeedge(int u, int v) {
	writesp(u, ' '); writesp(v);
}
LL qpow(LL a, int x) {
	LL sum = 1;
	while(x) {
		if(x & 1) sum = sum * a;
		a = a * a;
		x >>= 1;
	}
	return sum;
}
int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	read(y);
	LL k = (LL)(log(y) / log(2.0));
//	writesp(k);
	if(y == 1) {
		printf("2 1\n1 2\n");
		return 0;
	} else if(y == 2) {
		printf("3 3\n1 2\n2 3\n1 3\n");
		return 0;
	} else if(y <= 5) {
		if(y == 3) printf("4 5\n1 2\n1 3\n2 3\n2 4\n3 4\n");
		if(y == 4) printf("4 6\n1 2\n1 3\n1 4\n2 3\n2 4\n3 4\n");
		if(y == 5) printf("5 7\n1 2\n1 3\n1 4\n1 5\n2 3\n2 4\n3 4\n");
	} else if(qpow(2ll, k) == y) {
		int n = k + 2, m = n * (n - 1) / 2;
		printf("%d %d\n", n, m);
		_rep(i, 1, n) {
			_rep(j, i + 1, n) {
				writeedge(i, j);
			}
		}
		return 0;
	} else {
		int n = k + 2;
		_rep(i, 1, n) {
			_rep(j, i + 1, n) {
				u[++tot] = i; v[tot] = j;
			}
		}
		y -= 1ll * qpow(2ll, k);
		while(y) {
			LL l = (LL)(log(y) / log(2));
			u[++tot] = l + 2; v[tot] = k + 3;
			y -= qpow(2ll, l);
		}
		printf("%d %d\n", n + 1, tot);
		_rep(i, 1, tot) {
			printf("%d %d\n", u[i], v[i]);
		}
		return 0;
	}
	return 0;
}
