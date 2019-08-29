#include<cstdio>
#include<cstring>
#include<algorithm>
const int Nt = 524287; const long long inf = 0x3f3f3f3f3f3f3f3f;
int ri() {
    char c = getchar(); int x = 0, f = 1; for(;c < '0' || c > '9'; c = getchar()) if(c == '-') f = -1;
    for(;c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c; return x * f;
}
int a[Nt], st[Nt], tp, n, A, B, C, D;
long long T[Nt << 1], f[Nt], mx[Nt];

void Up(int i, long long x)
{for(T[i += Nt] = x; i >>= 1;) T[i] = std::max(T[i << 1], T[i << 1 | 1]);}

long long Cal(long long x) {return ((A * x + B) * x + C) * x + D;}

int main() {
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
    n = ri(); A = ri(); B = ri(); C = ri(); D = ri();
    for(int i = 1;i <= n; ++i) a[i] = ri();
    std::memset(T, -0x3f, sizeof(T));
    f[0] = 0; mx[1] = 0; st[tp = 1] = a[1]; Up(1, Cal(a[1]));
    for(int i = 1;i <= n; ++i) {
        f[i] = T[1]; long long x = f[i];
        for(;st[tp] > a[i + 1] && tp;) x = std::max(x, mx[tp]), Up(tp--, -inf);
        st[++tp] = a[i + 1]; mx[tp] = x; Up(tp, x + Cal(st[tp]));
    }
    printf("%lld\n", f[n]);
    return 0;
}
