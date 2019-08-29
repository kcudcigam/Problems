#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define N 500005
using namespace std;
int n,q;
int fa[N],cnt,siz[N];
int fd(int x){return x==fa[x]?x:fd(fa[x]);}
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=ip(),q=ip();
	rep(i,1,n) fa[i]=i;
	while(q--){
		int x,y,opt;opt=ip(),x=ip(),y=ip();
		if(opt==1){
			x=fd(x),y=fd(y);if(x!=y) fa[x]=y;
		}
		if(opt==2){
			rep(i,1,n){
				if(x==i) continue; siz[x]+=y;
				if(fd(i)==fd(x)) siz[i]+=y;
			}
		}
	}
	rep(i,1,n){cout<<siz[i]<<" ";}
	return 0;
}

