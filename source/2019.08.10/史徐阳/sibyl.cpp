#include<bits/stdc++.h>
using namespace std;
template<class T>inline void read(T&n){
	n = 0;T f = 1;char ch;
	for(;!(ch >= '0' && ch <= '9');ch = getchar())if(ch == '-')f = -1;
	for(;ch >= '0' && ch <= '9';ch = getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
template<class T>void write(T n){
	if (n < 0)n = -n,putchar('-');
	if (!n)return;
	write(n / 10);
	putchar(n % 10 + '0');
}
template<class T>void writeln(T n){
	write(n);
	puts("");
}
const int N = 3e5 + 5;
int n, m, q, s[N];
vector<int>vv[N];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n), read(m), read(q);
	for (int i = 1;i <= m;i ++){
		int u, v;
		read(u), read(v);
		vv[u].push_back(v);
		vv[v].push_back(u);
	}
	while (q --){
		int op, x, y;
		read(op);
		if (!op){
			read(x);
			int num = s[x];
			for (size_t i = 0;i < vv[x].size();i ++)
				num += s[vv[x][i]];
			writeln(num);
		}else{
			read(x), read(y);
			s[x] += y;
		}
	}
	return 0;
}

