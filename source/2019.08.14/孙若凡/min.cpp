#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; static bool f; static char c; f = x = 0,c = getchar();
	while (!isdigit(c)) {if (c == '-') f = 1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return f ? -x : x;
}
inline void write(LL x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar(x % 10 + '0'); }
inline void File(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
}
const int N = 200005;
LL n,A,B,C,D,a[N],mxf[N],st[N],top,f[N]; multiset<LL>s;
inline LL F(LL x){ return ((A * x + B) * x + C) * x + D; }
int main(){
	File();
	int i; LL val;
	n = read(),A = read(),B = read(),C = read(),D = read();
	for (i = 1; i <= n; ++i) a[i] = read();
	st[top = 1] = a[1]; mxf[top] = 0; s.insert(0 + F(a[1]));
	for (i = 1; i <= n; ++i){
		if (top && st[top] > a[i]){
			val = f[i-1];
			while (top && st[top] > a[i]){
				val = max(val,mxf[top]);
				s.erase(s.find(mxf[top] + F(st[top]))); --top;
			}
			++top,st[top] = a[i],mxf[top] = val; s.insert(val + F(a[i]));
		}
		else ++top,st[top] = a[i],mxf[top] = f[i-1],s.insert(f[i-1] + F(a[i]));
		f[i] = *--s.end();
	}
	write(f[n]),putchar('\n');
	return 0;
}
