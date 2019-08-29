#include<bits/stdc++.h>
using namespace std;
const int N=300010;
map<pair<int,int>,int>mp; 
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){f=-1;}ch=getchar();}
	while(ch<='9'&&ch>='0'){
		x*=10;x+=(ch-'0');ch=getchar();}return x*f;
}
int Head[N],Next[N*2],Ver[N*2];
int dis[N],vis[N];
int cut1,ans[N];
int n,m,tot;
struct node{
	int x,y;
};node a[N];
inline void add(int x,int y){
	Ver[++tot]=y;
	Next[tot]=Head[x];
	Head[x]=tot;
}
queue<int>q;
void bfs(int v){
	q.push(v);vis[v]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=Head[x];i;i=Next[i]){
			int y=Ver[i];
			if(!vis[y]){
				dis[y]=dis[x]+1;
				vis[y]=1;
				q.push(y);
			}
		}
	}
}
void work(int x,int y){
	memset(dis,0,sizeof(dis)),memset(vis,0,sizeof(vis));
	bfs(y);
	int maxx=0,maxxbh=0;
	for(int i=1;i<=n;++i){
		if(dis[i]>maxx){
			maxx=dis[i];maxxbh=i;
		}
	} 
	memset(dis,0,sizeof(dis)),memset(vis,0,sizeof(vis));
	bfs(maxxbh);
	maxx=0,maxxbh=0;
	for(int i=1;i<=n;++i){
		if(dis[i]>maxx){
			maxx=dis[i];
		}
	}
	ans[x]=maxx;return;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read();
	for(int i=1;i<n;++i){
		a[i].x=read(),a[i].y=read();
		add(a[i].x,a[i].y);add(a[i].y,a[i].x);
			work(i,a[i].x);
			printf("%d\n",ans[i]);
	}
	return 0;
}


