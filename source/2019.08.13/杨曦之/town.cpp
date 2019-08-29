#include<bits/stdc++.h>
using namespace std;
int const maxn=300000+10;
int H[maxn],V[maxn*2],N[maxn*2],tot=0;
int dis[maxn];
void add(int u,int v){
	V[++tot]=v;N[tot]=H[u];H[u]=tot;
}
int n,mfar,Mfar;
void dfs(int u,int fa){
	int i,v;
	for(i=H[u];i;i=N[i]){
		v=V[i];
		if(v==fa) continue;
		dis[v]=dis[u]+1;
		if(dis[v]>Mfar){
			Mfar=dis[v];
			mfar=v;
		}
		dfs(v,u);
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int i,j,u,v;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
		Mfar=-1;
		dis[u]=0;
		dfs(u,0);
		dis[mfar]=0;
		dfs(mfar,0);
		printf("%d\n",Mfar);
	}
	return 0;
}

