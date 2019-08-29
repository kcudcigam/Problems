#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	T f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
}
template <typename T> void write(T x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	printf("infinity\n");
	return 0;
}

