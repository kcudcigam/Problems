#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
  for (; isdigit(c);c=getchar()) x=x*10+c -'0';
  x*=f;
}
int T,n,xx,yy,tt,f,t,x,y,s;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
    read(T);
    for(int w=1;w<=T;w++){
    	read(n);
    	xx=0;yy=0;tt=0;f=0;
    	for(int i=1;i<=n;i++){
    		read(t);read(x);read(y);
    		s=abs(x-xx)+abs(y-yy);
    		if((t-tt-s<0)||(t-tt-s>0&&(t-tt-s)%2==1)){
    			f=1;
    			break;
			}
			tt=t;xx=x;yy=y;
		}
		if(f==0)
		   cout<<"Yes"<<endl;
		   else cout<<"No"<<endl;
	}
	return 0;
}


