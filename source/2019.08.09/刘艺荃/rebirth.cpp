#include<bits/stdc++.h>
using namespace std;
int num,n,m,INF,tot=0;
bool use[200010];
int v[200010],nxt[200010],head[200010],len[200010];
int dis[200010],vis[200010],a[400010];
queue<int> q;
void add(int x,int y,int z){
	v[++tot]=y;len[tot]=z;
	nxt[tot]=head[x];head[x]=tot;
}
void dijkstra(int s){
//	cout<<"s="<<s<<endl;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!q.empty())q.pop();
	INF=dis[1];
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int p=q.front();q.pop();
	//	cout<<p<<" "; 
		if(vis[p])continue;
		vis[p]=1;
		for(int i=head[p];i;i=nxt[i]){
			if(use[i])continue;
			int y=v[i],z=len[i];
			if(dis[y]>dis[p]+z){
				dis[y]=dis[p]+z;
				q.push(y);
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>num>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z);add(y,x,z);
		a[tot-1]=tot;
		a[tot]=tot-1;
	}
	cout<<0<<" ";
	for(int i=2;i<=n;i++){
		int res=0,flg=0;
		for(int j=head[i];j;j=nxt[j]){
			use[j]=1;use[a[j]]=1;
			dijkstra(i);
			use[j]=0;use[a[j]]=0;
			if(dis[1]==INF){
				cout<<-1<<" ";flg=1;
				break; 
			}else{
				res=max(res,dis[1]);
			}
		}
		if(!flg)cout<<res<<" ";
	}
	return 0;
}
/*
1 
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/

