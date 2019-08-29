#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; static char c; x = 0,c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return x;
}
inline void write(int x){ if (x > 9) write(x/10); putchar(x % 10 + '0'); }
inline void File(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
}
const int N = 500050;
int n,m,a[N],b[N];
int main(){
	File();
	int i,op,x,y,z,l1,r1,l2,r2,len1,len2,ans,L,R,Mid,cnt1,cnt2;
	n = read(),m = read();
	for (i = 1; i <= n; ++i) a[i] = read();
	for (i = 1; i <= n; ++i) b[i] = read();
	while (m--){
		op = read();
		if (op&1){ x = read(),y = read(),z = read(); if (x) b[y] = z; else a[y] = z; }
		else{
			l1 = read(),r1 = read(),l2 = read(),r2 = read(),len1 = r1 - l1 + 1,len2 = r2 - l2 + 1;
			ans = max(a[n],b[n]);
			L = l1,R = r1;
			while (L <= R){
				Mid = L + R >> 1;
				cnt1 = Mid - l1,cnt2 = r1 - Mid,x = (cnt2 + len2 - cnt1) >> 1;
				if (x <= len2 && (x < 1 || a[Mid] >= b[l2+x-1])) ans = min(ans,a[Mid]),R = Mid - 1; else L = Mid + 1;
			}
			L = l2,R = r2;
			while (L <= R){
				Mid = L + R >> 1;
				cnt1 = Mid - l2,cnt2 = r2 - Mid,x = (cnt2 + len1 - cnt1) >> 1;
				if (x <= len1 && (x < 1 || b[Mid] >= a[l1+x-1])) ans = min(ans,b[Mid]),R = Mid - 1; else L = Mid + 1;
			}
			write(ans),putchar('\n');
		}
	}
	return 0;
}
