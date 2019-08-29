#include <bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; static char c; x = 0,c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return x;
}
inline void write(LL x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar(x % 10 + '0'); }
inline void writeln(LL x){ write(x),putchar('\n'); }
inline void File(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
}
const int N = 800005;
LL n,tp[N],a[N],cnt3; LL sum3,sum1;
LL a0[N],cnt0,a1[N],cnt1,a2[N],cnt2;
int main(){
	File();
	int i;
	n = read();
	cnt0 = cnt1 = cnt2 = cnt3 = 0; sum3 = sum1 = 0;
	for (i = 1; i <= n; ++i){
		tp[i] = read();
		a[i] = read();
		if (tp[i] == 11) ++cnt3,sum3 += a[i];
		else if (tp[i] == 10) { ++cnt2; a2[cnt2] = a[i]; }
		else if (tp[i]){ ++cnt1; a1[cnt1] = a[i]; }
		else { ++cnt0; a0[cnt0] = a[i]; }
	}
	sort(a1+1,a1+cnt1+1); sort(a2+1,a2+cnt2+1);
	while (cnt1 && cnt2) sum1 += a1[cnt1] + a2[cnt2],--cnt1,--cnt2;
	while (cnt1) { ++cnt0; a0[cnt0] = a1[cnt1]; --cnt1; }
	while (cnt2) { ++cnt0; a0[cnt0] = a2[cnt2]; --cnt2; }
	sort(a0+1,a0+cnt0+1);
	while (cnt0 && cnt3) sum1 += a0[cnt0],--cnt0,--cnt3;
	writeln(sum1 + sum3);
	return 0;
}
