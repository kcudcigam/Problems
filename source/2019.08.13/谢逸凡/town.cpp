#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define N 300005
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
int head[N],nxt[N],to[N],cnt;
int n,a[N],b[N],fa[N],siz[N],dis[N];
vector<int>ans;
bool vis[N];
void Get(int a,int b){
	nxt[++cnt]=head[a];head[a]=cnt;to[cnt]=b;siz[cnt]=1;
	nxt[++cnt]=head[b];head[b]=cnt;to[cnt]=a;siz[cnt]=1;
}
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int fd(int x){
	return x==fa[x]?x:fd(fa[x]);
}
queue<int>q;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=ip();
	rep(I,1,n){
		int ans=0;
		int u=ip(),v=ip();fa[u]=v;
		rep(i,1,n) dis[i]=INF;
		Get(u,v);
//		q.push(u);vis[u]=1;dis[u]=0;
//		while(!q.empty()){
//			int nmsl=q.front();q.pop();
//			if(vis[nmsl]) continue;
//			if(dis[u]>dis[nmsl]+siz[nmsl]){
//				dis[u]=dis[nmsl]+siz[nmsl];
//				vis[nmsl]=1;q.push(nmsl);
//			}
//		}
		sort(dis+1,dis+1+cnt); 
		for(int i=head[1];i;i=nxt[i]){
			if(fd(to[i])==fd(I+1)) ans++;
		}
		printf("%d",ans?ans+I:I);
	}
	return 0;
}


