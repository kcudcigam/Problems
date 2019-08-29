#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int tot,n,m,num;
long long edge[1000010];
bool vis[200010];
int ver[1000010],Next[1000010],head[200010];
struct node{
	int las;
	long long num;
}l[200010];

void add(int x,int y,long long e){
	ver[++tot]=y;edge[tot]=e;Next[tot]=head[x];head[x]=tot;
	ver[++tot]=x;edge[tot]=e;Next[tot]=head[y];head[y]=tot;
}

inline void spfa(int k){
	q.push(k);
	while (!q.empty()){
		int x=q.front();
		vis[x]=0;
		q.pop();
		for (int i=head[x];i;i=Next[i]){
			if (l[x].num+edge[i]<l[ver[i]].num){
				int y=ver[i];
				l[y].num=l[x].num+edge[i];
				l[y].las=i;
				if (!vis[y])	q.push(y),vis[y]=1;
			}
		}
	}
}

long long spfa2(int k){
	long long ll[200010];
	for (int i=2;i<=n;++i)	ll[i]=1e18,vis[i]=0;
	ll[1]=0;
	q.push(1);
	while (!q.empty()){
		int x=q.front();
		vis[x]=0;
		q.pop();
		for (int i=head[x];i;i=Next[i]){
			if (ll[x]+edge[i]<ll[ver[i]]){
				int y=ver[i];
				ll[y]=ll[x]+edge[i];
				if (!vis[y])	q.push(y),vis[y]=1;
			}
		}
	}
	return ll[k];
}

int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num;
	scanf("%d",&num);
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;++i)	l[i].num=1e18;
	l[1].las=0;
	for (int i=1;i<=m;++i){
		int x,y;
		long long len;
		scanf("%d%d%lld",&x,&y,&len);
		add(x,y,len);
	}
	spfa(1);
	for (int i=1;i<=n;++i){
		int a=l[i].las;
		long long t=edge[a];
		edge[a]=1e18;
		if (spfa2(i)<1e18)	printf("%lld ",spfa2(i));
			else printf("-1 ");
		edge[a]=t;
	}
	return 0;
}

