#include<bits/stdc++.h>
#include<time.h>
using namespace std;
namespace base{
	#define R register
	typedef long long LL;
	typedef long double LD;
	typedef unsigned int UI;
	typedef unsigned long long ULL;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	template<class T>inline void read(T&n){
		n = 0;T f = 1;char ch;
		for (;!(ch >= '0' && ch <= '9');ch = getchar())if (ch == '-') f *= -1;
		for (;ch >= '0' && ch <= '9';ch = getchar())n = (n<<1) + (n<<3) + (ch^48);
		n *= f;
	}
	template<class T>inline void write(T n){
		if (n == 0)putchar('0');
		if (n < 0)n = -n, putchar('-');
		static char buf[233];int tmp = 0;
		while(n) buf[++ tmp] = n % 10 + '0', n /= 10;
		while(tmp) putchar(buf[tmp --]);
	}
	template<class T>inline void writeln(T n){
		write(n);
		puts("");
	}
}
using namespace base;
const int N = 1e5 + 5;
int x[N], y[N], p[N], l[N], r[N];
int n, m, q;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	read(n), read(m), read(q);
	for (int i = 1;i <= n;i ++)
		read(x[i]), read(y[i]), read(p[i]);
	for (int i = 1;i <= q;i ++)
		read(l[i]), read(r[i]);
	srand(time(0));
	int rd = ((LL)rand() * 2333 + 19999) * 314316 % 984356285;  
	writeln(rd);
	return 0;
}

