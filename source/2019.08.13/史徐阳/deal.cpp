#include<bits/stdc++.h>
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
struct Node{
	int num, x;
	Node(){}
	Node(int _num, int _x){
		num = _num, x = _x;
	}
}a[2005], b[2005];
int n, pay, ans, f[1000005];
void dfs1(int dep, int sum){
	if (dep > n){
		f[sum] ++;
		return;
	}
	for (int i = 0;i <= b[dep].x;i ++)
		dfs1(dep + 1, sum + i * b[dep].num);
}
void dfs2(int dep, int sum, int minn){
	if (sum > pay && minn <= sum - pay)return;
	if (dep > n){
		if (sum < pay || minn <= sum - pay) return;
		ans = (ans + f[sum - pay]) % N;return;
	}
	for (int i = 0;i <= a[dep].x;i ++){
		int tmp;
		if (i)tmp = min(minn, a[dep].num);
		else tmp = minn;
		dfs2(dep + 1, sum + i * a[dep].num, tmp);
	}
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n), read(pay);
	for (int i = 1;i <= n;i ++){
		int num, x, y;
		read(num), read(x), read(y);
		a[i] = Node(num, x);
		b[i] = Node(num, y);
	}
	dfs1(1, 0);
	dfs2(1, 0, INT_MAX);
	writeln(ans);	
	return 0;
}

