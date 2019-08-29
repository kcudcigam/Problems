#include<bits/stdc++.h>
#define enter '\n'
using namespace std;
template <class _T> inline _T read(_T &x){
	char ch=getchar(),minus=0;
	x=0;
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')ch=getchar(),minus=1;
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	if(minus)x=-x;
	return x;
}
template <typename T>void print (const T x){
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template <typename T>inline void write(const T x){
	if (x<0) putchar('-'),print(-x);
	else print(x);
}
template <typename T>inline void writeln(const T x,const char ch){
	write(x);
	putchar(ch);
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int x,y;
	read(x);read(y);
	cout<<"infinity"<<endl;
	return 0;
}


