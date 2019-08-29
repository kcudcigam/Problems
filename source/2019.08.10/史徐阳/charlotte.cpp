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
struct Node{
	int x, y, t;
}s[100005];
int T, n;
bool comp(Node a, Node b){
	if (a.t != b.t) return a.t < b.t;
	return a.x + a.y < b.x + b.y;
}
inline int dis(int x, int y, int xx, int yy){
	return abs(x - xx) + abs(y - yy);
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(T);
	while (T --){
		read(n);
		for (int i = 1;i <= n;i ++)	
			read(s[i].t), read(s[i].x), read(s[i].y);
		sort(s + 1, s + n + 1, comp);
		int flag = 1;
		for (int i = 1;i <= n;i ++){
			int d = dis(s[i - 1].x, s[i - 1].y, s[i].x, s[i].y);
			if (s[i - 1].t + d > s[i].t){
				flag = 0;
				break;
			}
			if (((s[i].t - s[i - 1].t) & 1) != (d & 1)){
				flag = 0;
				break;
			}
		}
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
}

