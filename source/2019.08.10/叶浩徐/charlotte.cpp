#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout);
template <typename T> inline void write(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x); puts("");
}
template <typename T> inline void print(T x){
	write(x); putchar(' ');
}
int T,n,x,y,t,lx,ly,lt;
int main(){
	fre("charlotte")
	read(T);
	while (T--){
		bool f=0;
		lt=lx=ly=0;
		read(n);
		for (int i=1;i<=n;i++){
			read(t); read(x); read(y);
			if (f) continue;
			if (abs(x-lx)+abs(y-ly)>t-lt){
				f=1; continue;
			}
			if ((t-lt-abs(x-lx)-abs(y-ly))%2){
				f=1; continue;
			}
			lt=t; lx=x; ly=y;
		}
		if (!f) puts("Yes");
		else puts("No");
	} 
	return 0;
}

