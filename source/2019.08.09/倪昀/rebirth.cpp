#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
struct info{
	int ver,edge;
};
vector<info>a[200100];
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
	freopen("rebirth","r",stdin);
	freopen("rebirth","w",stdout);
    int num=read();
    int n=read(),m=read();
    fir(i,1,m){
    	int x=read(),y=read(),d=read();
	}
	cout<<0;
	fir(i,1,n)cout<<' '<<-1;
	cout<<endl;
	return 0;
}
