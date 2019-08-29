#include<bits/stdc++.h>
#define fir(i,a,b) for(register unsigned i=a;i<=b;i++)
#define N 500100
using namespace std;
int a[N],b[N],tmp[N*2];
inline int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x;
}
inline void write(int x){
	char c=x%10+48;
	x/=10;
	if(x)write(x);
	putchar(c);
}
inline void writeln(int x){
	write(x);
	puts("");
}
int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    int n=read(),m=read();
    fir(i,1,n)a[i]=read();
    fir(i,1,n)b[i]=read();
    fir(i,1,m){
    	int opt=read();
    	if(opt==1){
    		int x=read(),y=read(),z=read();
    		if(!x)a[y]=z;
    		else b[y]=z;
		}else{
			int l1=read(),r1=read(),l2=read(),r2=read();
			fir(i,l1,r1)tmp[i-l1+1]=a[i];
			fir(i,l2,r2)tmp[r1+i-l2+1]=b[i];
			int len=r1-l1+r2-l2+2;
			sort(tmp+1,tmp+len+1);
			writeln(tmp[(len+1)>>1]);
		}
	}
	return 0;
}
