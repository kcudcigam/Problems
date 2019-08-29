#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int fa[500100],ans[500100];
inline int Find(int x){
	if(fa[x]!=x)fa[x]=Find(fa[x]);
	return fa[x];
}
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
    freopen("merge.in","r",stdin);
    freopen("merge.out","w",stdout);
    int n=read(),q=read();
    fir(i,1,n)fa[i]=i;
    memset(ans,0,sizeof(ans));
    fir(i,1,q){
    	int num=read();
    	if(num==1){
    		int x=read(),y=read();
    		fa[Find(y)]=Find(x);
		}else{
			int a=read(),b=read();
			fir(i,1,n)
			    if(Find(i)==Find(a))ans[i]+=b;
		}
	}
	cout<<ans[1];
	fir(i,2,n)cout<<' '<<ans[i];
	cout<<endl;
	return 0;
}

