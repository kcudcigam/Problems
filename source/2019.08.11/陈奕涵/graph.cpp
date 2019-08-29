#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	while(ch< '0' || ch >'9')ch=getchar();
	int ans=0;
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
const int maxn=300010;
//图 
int n,m,Q;
struct edges{
	int x,y,v;
	bool operator <(const edges rhs)const{
		return v<rhs.v;
	}
};
vector<edges>edge;
vector<int>e[maxn];
inline int get(int x,int i){
	if(edge[i].x==x)return edge[i].y;
	return edge[i].x;
}
//并查集(维护连通性)
int fa[maxn];
int find(int x){
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)fa[x]=y; 
}
//DFS
int vis[maxn];
int ans,mubiao,canfind;
void dfs(int x){
	if(x==mubiao){
		canfind=true;
		return;
	}
	vis[x]=1;
	for(int i=0;i<e[x].size() && !canfind;++i){
		int opt=e[x][i];
		int to=get(x,opt);
		if(!vis[to]){
			ans=max(ans,edge[opt].v);
			dfs(to);
		}
	}
	vis[x]=0;
} 
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),z=read();
		edge.push_back((edges){x,y,z});
	}
	sort(edge.begin(),edge.end());
	for(int i=0;i<m;++i){
		edges now=edge[i];
		int x=now.x,y=now.y;
		if(find(x)==find(y))continue;
		else{
			merge(x,y);
			e[x].push_back(i);
			e[y].push_back(i);
		}
	}
	while(Q--){
		int x=read(),y=read();
		if(find(x)!=find(y)){
			printf("-1\n");
			continue;
		}
		//跑 
		canfind=0;mubiao=y;ans=-1;
		dfs(x);
		printf("%d\n",ans); 
	}
	return 0;
}
