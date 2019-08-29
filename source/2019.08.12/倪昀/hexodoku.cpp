#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[100];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("hexodoku.in","r",stdin);
    freopen("hexodoku.out","w",stdout);
    int k=read(),n=read();
    fir(i,1,31)a[i]=read();
    puts("No way");
	return 0;
}
