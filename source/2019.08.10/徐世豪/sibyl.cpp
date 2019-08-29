#include<iostream>
#include<cstdio>
#include<cstring>
#define Inf 600009
using namespace std;
int n,m,Q;
int total,a,b,c;
int to[Inf],nt[Inf],head[Inf];
int x[Inf],book[Inf];
inline void add(int u,int v){
	to[++total]=v;
	nt[total]=head[u];
	head[u]=total;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d %d %d",&n,&m,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		if(a==b) continue;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=Q;i++){
		scanf("%d %d",&c,&a);
		if(c==0){
			int ans=x[a];
			memset(book,0,sizeof(book));
			for(int i=head[a];i;i=nt[i]){
				int t=to[i];
				if(!book[t]){
					ans+=x[t];
					book[t]=1;
				}
			}
			printf("%d\n",ans);
		}
		if(c==1){
			scanf("%d",&b);
			x[a]+=b;
		}
	}
	return 0;
}
