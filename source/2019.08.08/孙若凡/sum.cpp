#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; x = 0; static bool f; f = 0; static char c; c = getchar();
	while (!isdigit(c)){ if (c == '-') f = 1; c = getchar(); }
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return f ? -x : x;
}
inline void write(LL x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar('0'+x%10); }
inline void writeln(LL x){ write(x),putchar('\n'); }

inline void File(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
}
const int N = 100005;
int n,a[N]; LL f[N],g[N],ans = -(1ll<<62);
int main(){
	File();
	int i;
	n = read();
	for (i = 1; i <= n; ++i) a[i] = read(),f[i] = max(f[i-1],0ll) + a[i];
	for (i = n; i; --i) g[i] = max(g[i+1],0ll) + a[i];
	for (i = 2; i <= n; ++i) f[i] = max(f[i],f[i-1]);
	for (i = n-1; i; --i) g[i] = max(g[i],g[i+1]);
	for (i = 1; i <= n-1; ++i) ans = max(ans,f[i] + g[i+1]);
	writeln(ans);
	return 0;
}
