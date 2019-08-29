#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int n,m,q,K;
int fa[maxn];
int deep[maxn];
struct zy{
	int v,w;
}st[maxn][20];
vector<zy>G[maxn];
struct node{
	int u,v,w;
}road[maxn];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int a){
	if(fa[a]==a)
		return a;
	return fa[a]=find(fa[a]);
}
void dfs(int a,int anc){
	deep[a]=deep[anc]+1;
	int i,v;
	for(i=0;i<G[a].size();i++){
		v=G[a][i].v;
		if(v==anc)
			continue;
		st[v][0].v=a;
		st[v][0].w=G[a][i].w;
		dfs(v,a);
	}
}
int lca(int u,int v){
	int ans=0;
	if(deep[u]<deep[v])
		swap(u,v);
	int i,k=log(n)/log(2);
	for(i=k;i>=0;i--)
		if(st[u][i].v)
			if(deep[st[u][i].v]>=deep[v]){
//				cout<<i<<"   "<<u<<"   ";
				ans=max(ans,st[u][i].w);
				u=st[u][i].v;
//				cout<<u<<"   "<<ans<<endl;
			}
	if(u==v){
//		cout<<"a";
		return ans;
	}
	for(i=k;i>=0;i--)
		if(st[u][i].v)
			if(st[u][i].v!=st[v][i].v){
				ans=max(ans,st[u][i].w);
				ans=max(ans,st[v][i].w);
				u=st[u][i].v;
				v=st[v][i].v;
			}
	ans=max(ans,max(st[u][0].w,st[v][0].w));
	return ans;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int i,j,u,v,w;
	int k=log(n)/log(2);
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].w);
	sort(road+1,road+m+1,cmp);
	for(i=1;i<=m;i++){
		u=road[i].u;
		v=road[i].v;
		if(find(u)==find(v))
			continue;
		w=road[i].w;
		fa[fa[u]]=fa[v];
		G[u].push_back((zy){v,w});
		G[v].push_back((zy){u,w});
		if(++K==n)
			break;
	}
/*	for(i=1;i<=n;i++){
		cout<<i<<"           ";
		for(j=0;j<G[i].size();j++)
			cout<<G[i][j].v<<"  "<<G[i][j].w<<"     ";
		cout<<endl;
	}*/
	for(i=1;i<=n;i++)
		if(!deep[i])
			dfs(i,i);
/*	for(i=1;i<=n;i++)
		cout<<i<<"  "<<deep[i]<<"    "<<st[i][0].v<<"   "<<st[i][0].w<<endl;*/
	for(i=1;i<=k;i++)
		for(j=1;j<=n;j++)
			if(st[j][i-1].v){
				st[j][i].v=st[st[j][i-1].v][i-1].v;
				st[j][i].w=max(st[j][i-1].w,st[st[j][i-1].v][i-1].w);
			}
/*	for(i=1;i<=n;i++){
		cout<<i<<"        ";
		for(j=1;j<=k;j++)
			if(st[i][j].v)
				cout<<j<<"  "<<st[i][j].v<<"   "<<st[i][j].w<<"    ";
		cout<<endl;
	}*/
	for(i=1;i<=q;i++){
		scanf("%d%d",&u,&v);
		if(find(u)!=find(v)){
			printf("-1\n");
			continue;
		}
		printf("%d\n",lca(u,v));
	}
//	cout<<lca(2,4);
	return 0;
}


