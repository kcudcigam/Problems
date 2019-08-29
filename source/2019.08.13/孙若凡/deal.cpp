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
inline void writeln(int x){ write(x),putchar('\n'); }
inline void File(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
}
const int N = 1005,M = 20005,P = 1000000007;
inline int add(int x,int y){ return (x+=y)>=P?x-P:x; }
inline int dev(int x,int y){ return (x-=y)<0?x+P:x; }
inline int mul(LL x,int y){ return x*y-x*y/P*P; }
int n,valx,m,a[N],b[N],v[N];
int dp1[M],dp2[M],id[M],pre[M];
int main(){
	File();
	int i,j;
	n = read(),valx = read();
	for (i = 1; i <= n; ++i) v[i] = read(),a[i] = read(),b[i] = read(),swap(a[i],b[i]);
	dp1[0] = 1; m = 20000;
	for (i = 1; i <= n; ++i)
	for (j = 0; j <= m; ++j)
	id[j] = j / v[i],pre[j] = j < v[i] ? dp1[j] : add(pre[j-v[i]],dp1[j]),dp1[j] = id[j] <= a[i] ? pre[j] : dev(pre[j],pre[j-(a[i]+1)*v[i]]);
	int mn,val,ans = 0;
	dp2[0] = 1;
	for (i = n; i ; --i){
		mn = v[i];
		for (j = 0; j <= m; ++j){
			val = dp2[j];
			id[j] = j / v[i],pre[j] = j < v[i] ? dp2[j] : add(pre[j-v[i]],dp2[j]),dp2[j] = id[j] <= b[i] ? pre[j] : dev(pre[j],pre[j-(b[i]+1)*v[i]]);
			if (j >= valx){
				dp2[j] = dev(dp2[j],val);
				if (mn > j - valx) ans = add(ans,mul(dp2[j],dp1[j-valx]));
				dp2[j] = add(dp2[j],val);
			}
		}
	}
	writeln(ans);
	return 0;
}
