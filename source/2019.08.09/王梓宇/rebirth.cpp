#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=500005;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();
	}while(ch<='9'&&ch>='0'){x*=10;x+=(ch-'0');ch=getchar();}return x*f;}
int n,m,num,tot;
int Head[N],Next[M*2],Ver[M*2],Edg[M*2],vis[N];
long long dis[N];
int xo[N];
struct node{
	int x;
	long long y;
};
struct cmp{
	bool operator()(node x,node y){
		return x.y>y.y;
	}
};
priority_queue<node,vector<node>,cmp>q;
void csh(){
	for(int i=0;i<=200000;++i){
		dis[i]=50000000000100;
	}
}
inline void add(int x,int y,int z){
	Ver[++tot]=y;Edg[tot]=z;Next[tot]=Head[x];Head[x]=tot;
}
void dij(int le,int re,long long v){
	while(!q.empty()){
		q.pop();
	}
	csh();
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	q.push(node{1,0});
	while(!q.empty()){
		node x=q.top();q.pop();
		if(vis[x.x]){
			continue;
		}vis[x.x]=1;
		for(int i=Head[x.x];i;i=Next[i]){
			int y=Ver[i];long long z=Edg[i];
			if((z==v&&y==le&&x.x==re)||(z==v&&y==re&&x.x==le)){
				continue;
			}
			if(dis[y]>dis[x.x]+z){
				dis[y]=dis[x.x]+z;
				q.push(node{y,dis[y]});
			}
		}
	}
}	
void work1(){
	printf("0 ");
	for(int i=2;i<=n;++i){
		for(int j=Head[i];j;j=Next[j]){
			if(Ver[j]==i-1){
				dij(i-1,i,Edg[j]);
			}
		}
		if(vis[i]){
			printf("%lld ",dis[i]);
		}
		else{
			printf("-1 ");
		}
	}
	return;
}
void work2(){
	printf("0 ");
	for(int i=2;i<=n;++i){
	long long ans=-2;
	bool fg=false;
		for(int j=Head[i];j;j=Next[j]){
			int y=Ver[j];long long z=Edg[j];
			dij(i,y,z);
			if(vis[i]){
				fg=true;
				ans=max(ans,dis[i]);
			}
			else{
				break;
			}
		}
		if(!fg){
			printf("-1 ");
		}
		else{
			printf("%lld ",ans);
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	num=read();
	n=read(),m=read();
	int x,y,z;
	for(int i=1;i<=m;++i){
		x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	if(num<=16&&num>=12){
		work1();return 0;
	}
	work2();
	return 0;
}

