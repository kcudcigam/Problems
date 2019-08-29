#include<cstdio>
#include<algorithm>
int ri() {
    char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
    for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int A, B, C, D, n, a[100000]; long long f[100000];
long long Cal(long long x) {return ((A * x + B) * x + C) * x + D;}
int main() {
	freopen("min.in","r",stdin);
	freopen("Baoli.out","w",stdout);
    n = ri(); A = ri(); B = ri(); C = ri(); D = ri();
    for(int i = 1;i <= n; ++i) a[i] = ri();
    for(int i = 1;i <= n; ++i) {
        f[i] = -2e18;
        for(int j = i, mn = a[i]; j; mn = std::min(a[--j], mn))
            f[i] = std::max(f[i], f[j - 1] + Cal(mn));
    }
    printf("%I64d\n", f[n]);
    return 0;
}

