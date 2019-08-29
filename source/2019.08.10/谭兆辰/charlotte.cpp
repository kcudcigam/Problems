#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
inline int abs(int x){
	if(x<0) return -x;
	return x;
}
int n; 
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		int nowx=0,nowt=0,nowy=0;
		bool fg=0;
		for(int i=1;i<=n;i++){
			int x,y,t;
			read(t),read(x),read(y);
			nowt=nowt+abs(nowx-x)+abs(nowy-y);
			nowx=x,nowy=y;
			if((t-nowt)&1||nowt>t){
				fg=1;
			}
		}
		if(fg){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
	}
	return 0;
}
