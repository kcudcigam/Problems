#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline LL read(){
	static LL x; x = 0; static bool f; f = 0; static char c; c = getchar();
	while (!isdigit(c)){ if (c == '-') f = 1; c = getchar(); }
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return f ? -x : x;
}
inline void write(LL x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar('0'+x%10); }
inline void writeln(LL x){ write(x),putchar('\n'); }
inline void File(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
const int N = 500005;
int n,m;
LL a[N],ans;
int main(){
	File();
	LL i,l,r,s,e,d;
	n = read(),m = read();
	while (m--){
		l = read(),r = read(),s = read(),e = read();
		d = (e - s) / (r - l);
		a[l] += s,a[l+1] += d-s,a[r+1] -= e + d,a[r+2] += e;
	}
	for (i = 1; i <= n; ++i) a[i] += a[i-1];
	for (i = 1; i <= n; ++i) a[i] += a[i-1];
	for (ans = 0,i = 1; i <= n; ++i) ans ^= a[i];
	writeln(ans);
	return 0;
}
