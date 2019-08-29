#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define Inf 600009
using namespace std;
int n,m,Q;
int total,a,b,c,ans,s;
int book[Inf];
int to[Inf],w[Inf],nt[Inf],head[Inf];
inline void add(int u,int v,int t){
	to[++total]=v;
	w[total]=t;
	nt[total]=head[u];
	head[u]=total;
}
inline void  spfa(int k){
	queue<int>q;
	q.push(k);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nt[i]){
			int t=to[i];
			if(!book[t]){
				int p=s;
				s=max(s,w[i]);
				if(b==t) ans=min(ans,s);
				book[t]=1;
				spfa(t);
				if(s!=p) s=p;
				book[t]=0;
			}
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d %d %d",&n,&m,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	while(Q--){
		scanf("%d %d",&a,&b);
		ans=1000009;
		s=0;
		memset(book,0,sizeof(book));
		book[a]=1;
		spfa(a);
		if(ans!=1000009) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
