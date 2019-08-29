#include<bits/stdc++.h>
using namespace std;
const int N=300010;
const int INF=0x777777f;
inline int read()
{
int g=1,x=0;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-'){g=-1;}ch=getchar();}
while(ch<='9'&&ch>='0'){x*=10;x+=(ch-'0');ch=getchar();}return g*x;}

int Head[N],Next[N*2+10],Ver[N*2+10],Edg[N*2+10];
int dep[N],fa[N][25],f[N];
int dis[N][25];
int vis[N];
int n,m,tot,Q;
struct node{
	int x,y,z;
};node a[N*2+10];
inline void add(int x,int y,int z){
	Ver[++tot]=y;
	Edg[tot]=z;
	Next[tot]=Head[x];
	Head[x]=tot;
}
inline int find(int x){
	if(x==f[x]){
		return x;
	}return f[x]=find(f[x]);
}
bool cmp(node x,node y){
	return x.z<y.z;
}
void dfs(int x){
	vis[x]=1;
	for(int i=Head[x];i;i=Next[i]){
		int y=Ver[i],z=Edg[i];
		if(!vis[y]){
			dep[y]=dep[x]+1;
			dis[y][0]=z;
			fa[y][0]=x;
			dfs(y);
		}
	}
}
int lca(int x,int y){
	int le=find(x),re=find(y);
	int ans=-1;
	if(le!=re){
		return -1;
	}
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=20;i>=0;--i){
		if(dep[fa[x][i]]>=dep[y]){
			ans=max(ans,dis[x][i]);
			x=fa[x][i];
		}
	}
	if(x==y){
		return ans;
	}
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			ans=max(ans,dis[x][i]);
			ans=max(ans,dis[y][i]);
			x=fa[x][i];y=fa[y][i];
		}
	}
	ans=max(ans,max(dis[x][0],dis[y][0]));
	return ans;
} 
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	for(int i=1;i<=m;++i){
		a[i].x=read(),a[i].y=read(),a[i].z=read();
	} 
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i){
		int le=find(a[i].x),re=find(a[i].y);
		if(le!=re){
			f[le]=re;
			add(a[i].x,a[i].y,a[i].z);
			add(a[i].y,a[i].x,a[i].z);
		}
	}
	memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			dis[i][0]=-1;
			dep[i]=1;
			dfs(i);
		}
	}
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i<=n;++i){
			fa[i][j]=fa[fa[i][j-1]][j-1];
			dis[i][j]=max(dis[i][j],max(dis[fa[i][j-1]][j-1],dis[i][j-1]));
		}
	}
	int x,y;
	while(Q--){
		x=read(),y=read();
		printf("%d\n",lca(x,y));
	}
	return 0;
}


