#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(x=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
int x,y,n,m,i,j,k,l,s,d,f,dd,r,T,TT;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	T=read();
	for(TT=1;TT<=T;TT++){
		n=read();
		d=0;
		x=0;
		y=0;
		dd=0;
		for(i=1;i<=n;i++){
			l=read();
			f=read();
			r=read();
			s=abs(f-x)+abs(r-y);
			if((s%2==1&&(l-d)%2==0)||(s%2==0&&(l-d)%2)){
				dd=1;
				cout<<"No"<<endl;
				break;
			}
			else{
				if((s>(l-d))){
					dd=1;
					cout<<"No"<<endl;
					break;
				}
				else{
					d=l;
					x=f;
					y=r;
				}
			}
		}
		if(dd==0){
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}


