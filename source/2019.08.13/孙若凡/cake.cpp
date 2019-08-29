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
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
}
const int P = 1000000007,N = 305,M = 305;
int n,m,f[N][M];
int main(){
	File();
	int i,j,k;
	n = read(),m = read();
	for (i = 1; i <= n; ++i)
	for (j = 1; j <= m; ++j) if (i == 1 && j == 1) f[i][j] = 1;
	else{
		f[i][j] = 0;
		for (k = 1; k < i; ++k) f[i][j] = (f[i][j] + (LL)f[k][j] * f[i-k][j]) % P;
		for (k = 1; k < j; ++k) f[i][j] = (f[i][j] + (LL)f[i][k] * f[i][j-k]) % P;
	}
	writeln(f[n][m]);
	return 0;
}
