#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,fa[1<<19],dep[1<<19],up[1<<19],siz[1<<19],vis[1<<19],x[1<<19],y[1<<19],p1[1<<19],p2[1<<19],d[1<<19],Fa[1<<19];
basic_string<int> v[1<<19];
void dfs(int p,int f){
	fa[p]=f;dep[p]=dep[f]+1;siz[p]=1;
	for(int i:v[p])if(i!=f)dfs(i,p),siz[p]+=siz[i];
}
void dfs1(int p,int u){
	up[p]=u;vis[p]=1;
	if(siz[p]==1)return;
	int mx=-1,mp;
	for(int i:v[p])if(!vis[i] && siz[i]>mx)
		mx=siz[i],mp=i;
	dfs1(mp,u);
	for(int i:v[p])if(!vis[i])dfs1(i,i);
}
int dis(int x,int y){
	int re=0;
	while(up[x]!=up[y]){
		if(dep[up[x]]>dep[up[y]])re+=dep[x]-dep[up[x]]+1,x=fa[up[x]];
		else re+=dep[y]-dep[up[y]]+1,y=fa[up[y]];
	}
	return re+abs(dep[x]-dep[y]);
}
int getf(int x){return Fa[x]==x?x:Fa[x]=getf(Fa[x]);}
int main(){
	freopen("town.in","r",stdin),freopen("town.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",x+i,y+i);
		v[x[i]]+=y[i],v[y[i]]+=x[i];
	}
	dfs(1,0),dfs1(1,1);
	for(int i=1;i<=n;i++)Fa[i]=i,p1[i]=p2[i]=i;
	for(int i=1,t;i<n;i++){
		x[i]=getf(x[i]),y[i]=getf(y[i]);Fa[y[i]]=x[i];
		int o1=p1[x[i]],o2=p2[x[i]];
		if(d[y[i]]>d[x[i]])p1[x[i]]=p1[y[i]],p2[x[i]]=p2[y[i]],d[x[i]]=d[y[i]];
		for(int a:{o1,o2})
			for(int b:{p1[y[i]],p2[y[i]]})
				if((t=dis(a,b))>d[x[i]])
					d[x[i]]=t,p1[x[i]]=a,p2[x[i]]=b;
		printf("%d\n",d[x[i]]);
	}
	return 0;
}
