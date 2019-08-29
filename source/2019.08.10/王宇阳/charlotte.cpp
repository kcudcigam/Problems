#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;
	   char c=getchar();
	   while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	   while(c<='9' && c>='0'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	   return x*f;
}
int n,T;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	while(T--){
		bool flag=0;
		int t=0;
		n=read();
		int dix=0,diy=0;
		for(int i=1;i<=n;i++){
			int tim=read(),x=read(),y=read();
			if(flag)continue;
			tim-=t;
			t=tim;
			int jr=abs(x-dix)+abs(y-diy);
			dix=x;
			diy=y;
			if(jr>tim){
				flag=1;
			}else{
				if((jr-tim)%2!=0){
					flag=1;
				}
			}
		}
		if(flag){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}


