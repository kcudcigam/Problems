#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
//Õº 
int flag,n,m;
vector<int>e[maxn];
long long len[maxn][maxn],cannot[maxn][maxn];
//SPFA
long long dis[maxn];bool vis[maxn];queue<int>q;
void spfa(){
	for(int i=2;i<=n;++i)dis[i]=1e16;
	dis[1]=0;q.push(1);vis[1]=1;
	while(!q.empty()){
		int now=q.front();q.pop();vis[now]=0;
		for(int i=0;i<e[now].size();++i){
			int to=e[now][i];
			if(dis[to]>dis[now]+len[now][to]){
				dis[to]=dis[now]+len[now][to];
				q.push(to);vis[to]=0;
			}
		}
	}
}
//A*
long long d[maxn],v[maxn];
struct node{
	int x;
	bool operator <(const node rhs)const{
		return d[x]+dis[x]<d[rhs.x]+dis[rhs.x];
	}
}; 
priority_queue<node>qs;
long long astar(int begin){
	while(!q.empty())q.pop();
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;++i)d[i]=1e16;
	qs.push((node){begin});
	v[begin]=1,d[begin]=0;
	while(!qs.empty()){
		int now=qs.top().x;qs.pop();
		for(int i=0;i<e[now].size();++i){
			int to=e[now][i];
			if(cannot[now][to] || v[to])continue;
			if(d[to]>d[now]+len[now][to]){
				d[to]=d[now]+len[now][to];
				qs.push((node){to});
				if(to==1)return d[1];
			}
		}
	}
	return -1;
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%d",&flag);
	if(flag>7)return 0;
	//∂¡Õº 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		long long val; 
		scanf("%d%d%lld",&x,&y,&val);
		e[x].push_back(y),e[y].push_back(x);
		if(len[x][y]==0)len[y][x]=len[x][y]=val;
		else if(val<len[x][y])len[y][x]=len[x][y]=val;
	}
	//SPFA
	spfa();
	//A*
	printf("0 ");
	for(int now=2;now<=n;++now){
		long long ans=-1;
		for(int i=0;i<e[now].size();++i){
			int to=e[now][i];
			cannot[now][to]=cannot[to][now]=1;
			ans=max(ans,astar(now));
			cannot[now][to]=cannot[to][now]=0;
		}
		printf("%lld ",ans);
	} 
	return 0;
} 
