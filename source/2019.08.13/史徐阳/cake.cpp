#include<bits/stdc++.h>
#define LL long long
using namespace std;
namespace In_Out_put{
	template<class T>inline void read(T&n){
		n = 0;T f = 1;char ch;
		for (;!(ch >= '0' && ch <= '9');ch = getchar())if(ch == '-')f *= -1;
		for (;ch >= '0' && ch <= '9';ch = getchar())n = (n<<1) + (n<<3) + (ch^48);
		n *= f;
	}
	template<class T>inline void write(T n){
		if (n == 0)putchar('0');
		if (n < 0) n = -n,putchar('-');
		static char buf[233];int tmp = 0;
		while (n) buf[++ tmp] = n % 10 + '0', n /= 10;
		while (tmp) putchar(buf[tmp --]);
	}
	template<class T>inline void writeln(T n){
		write(n);
		puts("");
	}
}
using namespace In_Out_put;
const int N = 1000000007;
LL n, m, f[305][305];
LL dg(LL x, LL y){
	if (f[x][y]) return f[x][y];
	for (register int i = 1;i < x;i ++) 
		f[x][y] = (f[x][y] + dg(i, y) * dg(x - i, y) % N) % N;
	for (register int j = 1;j < y;j ++)
		f[x][y] = (f[x][y] + dg(x, j) * dg(x, y - j) % N) % N;
	return f[x][y] % N;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	f[1][1] = 1;
	read(n), read(m);
	writeln(dg(n, m) % N);
	return 0;
}

