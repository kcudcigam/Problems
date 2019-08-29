#include<bits/stdc++.h>
using namespace std;
int T,n,tx,ty,tt,t,x,y;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	while(T--){
		n=read();tx=ty=tt=0;bool flag=1;
		for(int i=1;i<=n;i++){
			t=read(),x=read(),y=read();
			int p=t-tt,pp=abs(x-tx)+abs(y-ty);
			if((pp>p)||(p-pp)%2==1){flag=0;break;}
			tt=t,tx=x,ty=y;
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
