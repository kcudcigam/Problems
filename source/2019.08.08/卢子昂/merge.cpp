#include<bits/stdc++.h>
using namespace std;
const int Maxn=500000+10;
int fa[Maxn],b[Maxn];
int n,q;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
int find(int x){
	if((fa[x]==x)||b[x])return x;
	else return fa[x]=find(fa[x]);
}
int Find(int x){
	while(fa[x]!=x)x=find(fa[x]);
	return fa[x];	
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int i,op,x,y,tot,cnt=1;
	read(n);read(q);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=q;i++){
		read(op);read(x);read(y);
		if(op==1){
			x=Find(x);y=Find(y);
			if(x!=y){
				if(b[x]==0)fa[y]=x;
				else if(b[y]==0)fa[x]=y;
				if(b[x]!=0&&b[y]!=0){
					
					fa[x]=fa[y]=n+cnt;
					cnt++;
				}
			}
		}
		if(op==2){
			x=Find(x);b[x]+=y;
		}
	}
	for(i=1;i<=n;i++){	
		tot=0;x=i;tot+=b[x];	
		while(fa[x]!=x){
			x=find(fa[x]);
			tot+=b[x];
		}	
		printf("%d ",tot);
	}
	return 0;
}

