#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 300100
using namespace std;
vector<int>edge[N];
int len[N],fa[N],vis[N],dis[N];
queue<int>q;
inline int Find(int x){
	if(fa[x]!=x)fa[x]=Find(fa[x]);
	return fa[x];
}
inline int bfs(int s){
	while(q.size())q.pop();
	q.push(s);
	memset(vis,0,sizeof(vis));
	vis[s]=1,dis[s]=0;
	int l=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=0;i<edge[x].size();i++)
			if(!vis[edge[x][i]]){
				q.push(edge[x][i]);
				vis[edge[x][i]]=1;
				dis[edge[x][i]]=dis[x]+1;
				l=max(l,dis[edge[x][i]]);
			}
	}
	return l;
}
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("town.in","r",stdin);
    freopen("town.out","w",stdout);
    int n=read();
    memset(len,0,sizeof(len));
    fir(i,1,n)fa[i]=i;
    fir(i,1,n-1){
    	int a=read(),b=read();
    	int ans=max(bfs(a)+bfs(b)+1,max(len[Find(a)],len[Find(b)]));
    	cout<<ans<<endl;
    	edge[a].push_back(b),edge[b].push_back(a);
    	fa[Find(b)]=Find(a);
    	len[Find(a)]=ans;
	}
	return 0;
}
