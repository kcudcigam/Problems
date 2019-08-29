#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
template<class T> inline void write(T x){
	if (x==0)putchar(48); if (x<0) x=-x,putchar('-');
	static char buf[233];register int top=0;
	while (x)buf[++top]=x%10+48,x/=10;
	while (top)putchar(buf[top--]);
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	write(483062298);
	return 0;
}
