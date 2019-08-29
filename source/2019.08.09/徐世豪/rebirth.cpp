#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define Inf 500009
using namespace std;
int num,n,m;
int total;
int dis[Inf],book[Inf];
int to[Inf],w[Inf],nt[Inf],head[Inf];
inline void add(int u,int v,int q){
	to[++total]=v;
	w[total]=q;
	nt[total]=head[u];
	head[u]=total;
}
inline void spfa(int k){
	queue<int>q;
	q.push(k);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nt[i]){
			int t=to[i];
			if(book[x]==w[i]&&book[t]==w[i]) continue;
			if(dis[t]>dis[x]+w[i]){
				q.push(t);
				dis[t]=dis[x]+w[i];
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%d",&num);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==b) continue;
		add(a,b,c);
		add(b,a,c);
	}
	printf("0 ");
	for(int i=2;i<=n;i++){
		int ans=0;
		for(int j=head[i];j;j=nt[j]){
			int t=to[j];
			book[t]=w[j];
			book[i]=w[j];
			for(int k=1;k<=n;k++) dis[k]=0x7fffffff;
			dis[i]=0;
			spfa(i);
			book[t]=0;
			book[i]=0;
			if(dis[1]!=0x7fffffff) ans=max(ans,dis[1]);
		}
		if(ans) printf("%d ",ans);
		else printf("-1");
	}
	return 0;
}
