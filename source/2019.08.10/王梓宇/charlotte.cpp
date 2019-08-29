#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch<='9'&&ch>='0'){x*=10;x+=ch-'0';ch=getchar();}
	return x*f;
}
int T,n;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	int t,x,y;
	while(T--){
		n=read();bool fg=true;
		for(int i=1;i<=n;++i){
			t=read(),x=read(),y=read();
			if(x+y>t){
				fg=false;
			}
			if((t-x-y)%2==1){
				fg=false;
			}
		}
		if(fg){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}


