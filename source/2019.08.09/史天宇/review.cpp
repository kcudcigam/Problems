#include<cstdio>
#include<cctype>
#include<cmath>

typedef long long LL;

int N, M, del[100];
LL Y;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

inline LL ksm(LL x, int p) {
	LL ret = 1;
	for (; p; p >>= 1, x *= x) if (p & 1) ret *= x;
	return ret;
}

int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	scanf("%lld", &Y);
	N = log2(Y) + 2;
	if (ksm(2, N - 2) == Y) {
		M = N * (N - 1) / 2;
		printf("%d %d\n", N, M);
		for (int i = 1; i < N; ++i)
			for (int j = i + 1; j <= N; ++j) 
				printf("%d %d\n", i, j);
	}
	else {
		N += 1; M = N * (N - 1) / 2;
		int cnt = 0;
		LL minus = ksm(2, N - 2) - Y;
		while (minus) {
			++cnt;
			if (minus % 2) del[cnt + 1] = 1, --M;
			minus >>= 1;
		}
		printf("%d %d\n", N, M);
		for (int i = 1; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				printf("%d %d\n", i, j);
			}
			if (!del[i]) printf("%d %d\n", i, N);
		}
	}
	return 0;
}
