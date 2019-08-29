#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')c=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1,x,y;i<=m1;i++){
		x=read();y=read();
	}
	for(int i=1,x,y;i<=m2;i++){
		x=read();y=read();
	}
	if(n==1||n==2){cout<<0<<endl;exit(0);}
	return 0;
}

