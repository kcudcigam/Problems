#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define rint register int
using namespace std;
const int maxn=1e6+7;
const int inf=1e8;

int head[maxn],cnt=0;
int n;
bool vis[maxn];
int point1;
int maxd=-inf;

struct EDGE{
	int next;
	int to;
}e[maxn];

void add(int u,int v){
	++cnt;
	e[cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}

void dfs2(int x,int d){
	memset(vis,false,sizeof(vis));
	vis[x]=true;
	for(rint i=head[x];i;i=e[i].next){
		maxd=max(maxd,d);
		if(vis[i]) return;
		dfs2(i,d+1);
	}
}

void dfs1(int x){
	vis[x]=true;
	for(rint i=head[x];i;i=e[i].next){
		if(vis[i]) return;
		dfs1(i);
	}
	for(rint i=head[x];i;i=e[i].next){
		if(!vis[i]) return;
		point1=x;
		dfs2(point1,0);
	}
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	int x,y;
	for(rint i=1;i<=n-1;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		dfs1(x);
		printf("%d\n",maxd);
	}
	return 0;
}
