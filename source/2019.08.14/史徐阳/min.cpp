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
const int N = 2e5 + 5;
int n, s[N], f[N][20], lg[N];
LL ans = 0, A, B, C, D, g[1005][1005];
inline LL F(int num){
	return A * num * num * num
		   + B * num *num
		   + C * num + D;
}
inline void ST_prework(int n){
	for (int i = 1;i <= n ;i ++)
		f[i][0] = s[i];
	int t = lg[n] - 1;
	for (R int j = 1;j <= t;j ++)
		for (R int i = 1;i <=  n - (1<<j) + 1;i ++)
			f[i][j] = min(f[i][j - 1], f[i + (1<<(j-1))][j - 1]);
}
inline int query(int l, int r){
	int t = log2(r - l + 1);
	return min(f[l][t], f[r - (1<<t) + 1][t]);
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n), read(A), read(B), read(C), read(D);
	for (R int i = 1;i <= n;i ++){
		read(s[i]);
		g[i][i] = F(s[i]);
		lg[i] = lg[i - 1] + (1<<lg[i - 1] == i);
	}	
	ST_prework(n);
	for (R int len = 2;len <= n;len ++)
		for (R int i = 1;i <= n- len + 1;i ++){
			int j = i + len - 1;
			g[i][j] = F(query(i, j));
			for (R int k = i;k < j;k ++)
				g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j]);
		}
	writeln(g[1][n]);
	return 0;
}

