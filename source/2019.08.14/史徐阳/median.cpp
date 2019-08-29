#include<bits/stdc++.h>
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
const int N = 5e5 + 5;
LL a[N], b[N];
int n, m;
LL merge(int l1, int r1, int l2, int r2){
	int len = r1 - l1 + 1 + r2 - l2 + 1;
	R int i = l1, j = l2;
	for (R int k = 1;k <= len / 2;k ++){
		if (a[i] < b[j] && i < r1) i ++;
		else j ++;
	}            
	if (a[i] < b[j] && i <= r1) return a[i];
	else return b[j];                
}
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	read(n), read(m);
	for (int i = 1;i <= n;i ++)
		read(a[i]);
	for (int i = 1;i <= n;i ++)
		read(b[i]);
	while(m --){
		int op;
		read(op);
		if (op == 1){
			int x, y, z;
			read(x), read(y), read(z);
			if (x == 0) a[y] = z;
			else b[y] = z;
		}else{
			int l1, r1, l2 ,r2;
			read(l1), read(r1), read(l2), read(r2);
			writeln(merge(l1, r1, l2, r2));
		}
	}
	return 0;
}

