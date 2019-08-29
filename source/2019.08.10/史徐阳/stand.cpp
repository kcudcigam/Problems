#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<class T>inline void read(T&n){
	n = 0;T f = 1;char ch;
	for(;!(ch >= '0' && ch <= '9');ch = getchar())if(ch == '-')f = -1;
	for(;ch >= '0' && ch <= '9';ch = getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
template<class T>void write(T n){
	if (n < 0)n = -n,putchar('-');
	if (n <= 9){putchar(n + '0');return;}
	write(n / 10);
	putchar(n % 10 + '0');
}
template<class T>void writeln(T n){
	write(n);
	puts("");
}
struct Node{
	int l, r;
}s[305];
int n, m, g[10], H[305], ch[10000005];
bool comp(Node a, Node b){
	if (a.l != b.l)return a.l < b.l;
	return a.r > b.r;
}
LL G(int num){
	LL tmp = (LL)num, ans = 0;
	for (int i = 1;i <= 5;i ++){
		ans += g[i] * tmp;
		tmp *= num;
	}
	return ans;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n), read(m);
	int res = n;LL ans = 0;
	for (register int i = 1;i <= 5;i ++)
		read(g[i]);
	for (register int i = 1;i <= n;i ++)
		read(s[i].l), read(s[i].r);
	while (res){
		int maxx = 0,index = 0, num = 0;
		memset(ch, 0, sizeof(ch));
		for (register int i = 1;i <= n;i ++){
			if (H[i])continue;
			ch[s[i].l] ++, ch[s[i].r + 1]--;
		}
		for (register int i = 1;i <= m;i ++){
			ch[i] += ch[i - 1];
			if (ch[i] > maxx)
				maxx = ch[i], index = i;
		}
		for (register int i = 1;i <= n;i ++)
			if (!H[i] && s[i].l <= index && s[i].r >= index){
				H[i] = 1;
				num ++;
				res --;
			}
		ans += G(num);		
	}
	writeln(ans);
	return 0;
}

