#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;
const int inf=1e8;

int head[maxn],cnt;
int dis[maxn];
int Num,n,m;

struct NODE{
	int u;
	int d;
	friend bool operator < (const NODE &a,const NODE &b){
		return a.d>b.d;
	}
};

struct EDGE{
	int next;
	int to;
	int w;
	bool del=false;
}e[maxn<<1];

void add(int u,int v,int w){
	++cnt;
	e[cnt].next=head[u];
	e[cnt].w=w;
	e[cnt].to=v;
	head[u]=cnt;
}

void dijkstra(int sta){
	dis[sta]=0;
	priority_queue<NODE> q;
	NODE x;
	x.u=sta; x.d=0;
	q.push(x);
	while(!q.empty()){
		NODE fr=q.top(); q.pop();
		int u=fr.u,d=fr.d;
		if(d!=dis[u]) continue;
		for(rint i=head[u];i;i=e[i].next){
			if(e[i].w==-1) continue;
			int v=e[i].to,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				NODE y; y.u=v; y.d=dis[v];
				q.push(y);
			}
		}
	}
}

int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%d",&Num);
	scanf("%d%d",&n,&m);
	for(rint i=1;i<=n;++i) dis[i]=inf;
	int x,y,w;
	for(rint i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w); add(y,x,w);
	}
	int ans=-22232;
	for(rint o=1;o<=n;++o){
		for(rint i=head[o];i;i=e[i].next){
			for(rint p=1;p<=n;++p) dis[p]=inf;
			//e[i].w=-1;
			dijkstra(o);
		}
		if(o==1){
			printf("0 ");
			continue;
		}
		if(dis[1]!=inf) ans=max(ans,dis[1]);
		printf("%d ",ans);
		ans=-1222;
	}
	return 0;
}


/*
3
7 6
1 2 1
1 3 1
2 4 1
2 5 1
3 6 1
3 7 1
*/

/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/






