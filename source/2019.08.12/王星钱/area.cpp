#include <bits/stdc++.h>
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int x,y;
	read(x),read(y);
	if (x==1||y==1) puts("infinity");
	else printf("%d\n",5);
	return 0;
}
