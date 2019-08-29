#include<iostream>
#include<cstdio>
#include<queue>
#define Inf 300009
using namespace std;
int n,total,ans,s[Inf];
int dis[Inf],f[Inf],to[Inf],nt[Inf],head[Inf];
inline int find(int k){if(f[k]==k) return k;else return f[k]=find(f[k]);}
inline void add(int u,int v){to[++total]=v;nt[total]=head[u];head[u]=total;}
inline void spfa(int k){
	queue<int>q;
	q.push(k);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nt[i]){
			int t=to[i];
			if(dis[t]>dis[x]+1){
				dis[t]=dis[x]+1;
				ans=max(ans,dis[t]);
				q.push(t);
			}
		}
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
		int x=find(a),y=find(b);
		if(x!=y) f[x]=y;
		ans=0;
		for(int i=1;i<n;++i)
			if(f[i]==y){
				for(int j=1;j<=n;++j)
					dis[j]=Inf;
				dis[i]=0;
				spfa(i);
			}
		printf("%d\n",ans);
	}
	return 0;
}
