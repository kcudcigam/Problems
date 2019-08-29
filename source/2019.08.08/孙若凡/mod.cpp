#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	static int x; x = 0; static bool f; f = 0; static char c; c = getchar();
	while (!isdigit(c)){ if (c == '-') f = 1; c = getchar(); }
	while (isdigit(c)) x = x * 10 + c - '0',c = getchar();
	return f ? -x : x;
}
inline void write(int x){ if (x < 0) putchar('-'),x = -x; if (x > 9) write(x/10); putchar('0'+x%10); }
inline void writeln(int x){ write(x),putchar('\n'); }
inline void File(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
}
LL q,n,P,ans,f,val;
int main(){
	File();
	LL i;
	q = read();
	while (q--){
		n = read(),P = read();
		ans = 0,f = 1;
		for (i = n; i ; --i){
			val = i * (i-1) % P;
			if (!(i&1)){
				val -= i - 2;
				if (val >= P) val -= P; if (val < 0); val += P;
			}
			ans = (ans + val * f) % P;
			f = f * i % P; 
		}
		writeln(ans);
	}
	return 0;
}
