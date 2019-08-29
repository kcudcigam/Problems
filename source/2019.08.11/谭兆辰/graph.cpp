//结论:两点x,y路径中最长路最小值一定在这张图最小生成树上(x,y)路径上
//证明：如果存在一条路径不属于最小生成树且最长路比最小生成树上路径小,那我一定可以把最小生成树上最大那条边断开
//然后将这条路径上的一条边加入最小生成树,所得到的这棵树一定比之前的最小生成树优秀,假设不成立 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
inline void print(int x){
	if(!x) return ;
	print(x/10);
	putchar(x%10+'0');
	return ;
}
#define N 300300
struct node{
	int nxt,to,age;
}s[2*N];
int head[N],tot=0;
inline void edge(int x,int y,int z){
	s[++tot].to=y,s[tot].nxt=head[x],head[x]=tot,s[tot].age=z;
	return ;
}
struct code{
	int x,y,z;
}a[N];
int fa[N];
inline int getfather(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfather(fa[x]);
}
int n,m,q;
int siz[N];
inline void kruskal(){
//	cout<<"___________\n";
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int fx=getfather(a[i].x),fy=getfather(a[i].y);
		if(fx!=fy){
			if(siz[fx]<siz[fy]) swap(fx,fy);
			siz[fx]+=siz[fy];
			fa[fy]=fx;
			edge(a[i].x,a[i].y,a[i].z),edge(a[i].y,a[i].x,a[i].z);
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
		}
	}
//	cout<<"_______________\n";
	return ;
}
#include <algorithm>
inline bool cmp(code x,code y){
	return x.z<y.z;
}
bool vis[N];
int lg[N],f[N][20],depth[N],maxx[N][20];
inline void dfs(int x,int father,int k){
//	cout<<x<<" ";
	depth[x]=depth[father]+1;
	vis[x]=1;
	f[x][0]=father,maxx[x][0]=k;
	for(int i=1;i<=lg[depth[x]-1];i++) f[x][i]=f[f[x][i-1]][i-1],maxx[x][i]=max(maxx[x][i-1],maxx[f[x][i-1]][i-1]);
	for(int i=head[x];i;i=s[i].nxt){
		int y=s[i].to;
		if(y!=father){
			dfs(y,x,s[i].age);
		}
	}
	return ;
}
inline int lca(int x,int y){
	int ans=0;
	while(depth[x]<depth[y]) swap(x,y);
	while(depth[x]!=depth[y]){
		ans=max(ans,maxx[x][lg[depth[x]-depth[y]]]);
		x=f[x][lg[depth[x]-depth[y]]];
	}
	if(x==y){
		return ans;
	}
	cout<<1;
	for(int i=lg[depth[x]-1];i>-1;i--){
		if(f[x][i]!=f[y][i]){
			ans=max(ans,max(maxx[x][i],maxx[y][i]));
			x=f[x][i],y=f[y][i];
//			cout<<x<<" "<<y<<"\n";
		}
	}
	ans=max(ans,max(maxx[x][0],maxx[y][0]));
	return ans;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=m;i++){
		int x,y,z;
		read(a[i].x),read(a[i].y),read(a[i].z);
	}
	sort(a+1,a+1+m,cmp); 
	kruskal();
	lg[1]=0;
	for(int i=2;i<=n;i++) lg[i]=lg[i-1]+((1<<lg[i-1]+1)==i);
//	for(int i=1;i<=n;i++){
//		cout<<lg[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0,0);
		}
	}
	while(q--){
		int x,y;
		read(x),read(y);
		int fx=getfather(x),fy=getfather(y);
		if(fx!=fy){
			printf("-1\n");
		}
		else{
			print(lca(x,y));
			putchar('\n');
		} 
	}
	return 0;
}
