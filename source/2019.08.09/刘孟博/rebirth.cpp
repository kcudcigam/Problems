#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
const int MAXN=2e5+10;
const ll INF=1e15;
struct Edge{int to;ll dis;};
vector<Edge>edges;
vector<int>g[MAXN];
int num,n,m,qaq,a[1001][1001];
ll d[MAXN];
inline void ins(int x,int y,ll dis){edges.push_back((Edge){y,dis});g[x].push_back(edges.size()-1);}
priority_queue<pair<int,int> >q;
bool vis[MAXN];
inline void dijkstra(int s){
	for(int i=1;i<=n;i++)d[i]=INF;
	for(int i=1;i<=n;i++)vis[i]=0;
	q.push(mp(0,1));d[1]=0;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			int t=g[x][i];int to=edges[t].to;
			if(t==qaq)continue;
			if(d[to]>d[x]+edges[t].dis){
				d[to]=d[x]+edges[t].dis;
				q.push(mp(-d[to],to));
			}
		}
	}
}
int main(){
	freopen("rebirth.in","r",stdin);freopen("rebirth.out","w",stdout);
	num=read(),n=read(),m=read();
	for(int i=1,x,y;i<=m;i++){
		x=read(),y=read();ll z;scanf("%lld",&z);
		if(x!=y)ins(x,y,z),ins(y,x,z);
	}qaq=-1;
	dijkstra(1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<g[i].size();j++){
			int to=edges[g[i][j]].to;
			if(d[to]==d[i]+edges[g[i][j]].dis)a[to][++a[to][0]]=g[i][j];
		}
	cout<<"0 ";
	for(int i=2;i<=n;i++){
		ll ans=INF;
		for(int j=1;j<=a[i][0];j++){
			qaq=a[i][j];dijkstra(1);
			ans=min(ans,d[i]);
		}
		if(ans==INF)printf("-1 ");else printf("%d ",ans);
	}
	return 0;
}
