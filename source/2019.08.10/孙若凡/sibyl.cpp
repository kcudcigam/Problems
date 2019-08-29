#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; static char c; x = 0,c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return x;
}
inline void write(int x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar(x % 10 + '0'); }
inline void File(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
}
const int N = 300005,M = 300005;

int n,m,q,deg[N],size,ex[M],ey[M],val[N],ans[N]; bool type[N];
int To1[M<<1],Ne1[M<<1],He1[N],_k1 = 0; inline void add1(int x,int y){ ++_k1; To1[_k1] = y,Ne1[_k1] = He1[x],He1[x] = _k1; }
int To2[M<<1],Ne2[M<<1],He2[N],_k2 = 0; inline void add2(int x,int y){ ++_k2; To2[_k2] = y,Ne2[_k2] = He2[x],He2[x] = _k2; }

int main(){
	File();
	int i,x,y,sum,p;
	n = read(),m = read(),q = read(); size = 1 + (int)sqrt(m);
	for (i = 1; i <= m; ++i) ex[i] = read(),ey[i] = read(),++deg[ex[i]],++deg[ey[i]];
	for (i = 1; i <= n; ++i) type[i] = deg[i] <= size ? 0 : 1;
	for (i = 1; i <= m; ++i){
		if (!type[ex[i]]) add1(ex[i],ey[i]); else add2(ey[i],ex[i]);
		if (!type[ey[i]]) add1(ey[i],ex[i]); else add2(ex[i],ey[i]);
	}
	while (q--){
		if (read()){ // modify
			x = read(),y = read(),val[x] += y;
			for (p = He2[x]; p; p = Ne2[p]) ans[To2[p]] += y;
		}
		else{ // query
			x = read();
			if (type[x]) write(val[x] + ans[x]),putchar('\n');
			else{
				sum = val[x];
				for (p = He1[x]; p; p = Ne1[p]) sum += val[To1[p]];
				write(sum),putchar('\n');
			}
		}
	}
	return 0;
}
