#include<iostream>
#include<cstdio>
#include<algorithm>
#define rint register int
#define ll long long
using namespace std;
const int maxn=1e6+7;
const int inf=1e8;

int n,m,q;
int val[maxn];
int cnt,head[maxn];
bool vis[maxn];
int lazy=0;

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

void modify(int x,int w){
	if(x==1){
		lazy+=w;
		val[1]+=w;
		return;
	}
	val[x]+=w;
	for(rint i=head[x];i;i=e[i].next){
		val[e[i].to]+=w;
	}
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int u,v;
	for(rint i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	int cho,x,y;
	for(rint i=1;i<=q;++i){
		scanf("%d",&cho);
		if(cho){
			scanf("%d%d",&x,&y);
			modify(x,y);
		}
		else{
			for(rint i=head[1];i;i=e[i].next) vis[e[i].to]=true;
			scanf("%d",&x);
			if(vis[x]) printf("%d\n",val[x]+lazy);
			else printf("%d\n",val[x]);
		}
	}
	return 0;
}



/*
8 8 6
1 2
1 3
1 4
1 5
1 6
3 7
4 7
4 8
1 1 2
0 3
1 7 3
0 4
1 2 4
0 1
*/








