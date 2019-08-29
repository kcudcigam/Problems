#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 500000
using namespace std;
int n,w[N]/*private*/,fa[N],W[N]/*public*/;
vector<int>a[N];
int ch(){
	fir(i,1,n)
	    if(a[i].size()>1){
	    	fir(j,0,a[i].size()-1)
	    	    if(a[a[i][j]].size()>1)return 0;
	    }
	return 1;
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
    freopen("sibyl.in","r",stdin);
    freopen("sibyl.out","w",stdout);
    n=read();
    int m=read(),Q=read();
    fir(i,1,m){
    	int u=read(),v=read();
    	a[u].push_back(v),a[v].push_back(u);
	}
	memset(w,0,sizeof(w)),memset(W,0,sizeof(W));
	if(ch()){
		fir(i,1,n)fa[i]=i;
		fir(i,1,n)
		    if(a[i].size()>1)fir(j,0,a[i].size()-1)fa[a[i][j]]=i;
		    else if(a[i].size()==1&&a[a[i][0]].size()==1)fa[i]=a[i][0];
		fir(i,1,Q){
			int typ=read();
			if(typ){
				int x=read(),y=read();
				if(fa[x]==x)W[x]+=y;
				else w[x]+=y,w[fa[x]]+=y;
			}else{
				int x=read();
				cout<<w[x]+W[fa[x]]<<endl;
			}
		}
	}else fir(i,1,Q){
		int typ=read();
		if(typ){
			int x=read(),y=read();
			w[x]+=y;
			fir(i,0,a[x].size()-1)w[a[x][i]]+=y;
		}else{
			int x=read();
			cout<<w[x]<<endl;
		}
	}
	return 0;
}
