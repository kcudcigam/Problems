#include<bits/stdc++.h>
using namespace std;
const int Maxn=300000+10;
int Head[Maxn],V[Maxn<<1],Next[Maxn<<1],vis[Maxn];
int n,root,ans,cnt,tot;
void Add(int u,int v){
	V[++tot]=v;Next[tot]=Head[u];Head[u]=tot;
}
void dfs_findroot(int now,int dep){
	vis[now]=1;
	if(dep>cnt){root=now;cnt=dep;}
	for(int i=Head[now];i;i=Next[i])if(!vis[V[i]])dfs_findroot(V[i],dep+1);	
	vis[now]=0;
}
void dfs_len(int now,int dep){
	vis[now]=1;
	if(dep>ans){ans=dep;}
	for(int i=Head[now];i;i=Next[i])if(!vis[V[i]])dfs_len(V[i],dep+1);
	vis[now]=0;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	int a,b,i;
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		Add(a,b);Add(b,a);
		ans=0;cnt=0;
		dfs_findroot(a,1);
		dfs_len(root,0);
		printf("%d\n",ans);
	}
	return 0;
}
