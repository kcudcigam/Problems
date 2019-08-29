#include<bits/stdc++.h>
using namespace std;
const int maxn = 300000+10 ;
template <typename T> void read(T &x){
		 x = 0 ;
		 char c ;
		 int flag = 1 ;
		 while(!isdigit(c)){
			 c = getchar() ;
			 if(c=='-')
				 flag = -1 ;
		 }
		 while(isdigit(c))
			 x = x*10+c-'0' , c = getchar() ;
}
vector<pair<int,int> >g[maxn] ;
int n,m,s;
vector<int>dis[maxn] ;
int t ;
int f[maxn],tot,a[maxn],size[maxn];
int num[maxn] ,k ;
bool vis[maxn],vis1[maxn] ;
struct node{
	int v,dis;
};
bool operator<(node x,node y){return x.dis>y.dis;} 

void dij(int s){
	
	dis[s][s] = 0 ;
	node u,v ; int w ;
	priority_queue<node>q ;
	q.push((node){s,0}) ;
	while(!q.empty()){
		u = q.top() ; q.pop() ;
		if(vis[u.v])
			continue ;
		vis[u.v] = 1 ;
		for(int i = 0 ; i < (int)g[u.v].size() ; i++){
			v.v = g[u.v][i].first ; w = g[u.v][i].second ;
			if(dis[s][num[v.v]]>max(dis[s][num[u.v]],w)){
				dis[s][num[v.v]] = max(dis[s][num[u.v]],w) ;
				v.dis = dis[s][num[v.v]] ;
				q.push(v) ;
			}
		}
	}
} 
void dfs(int u){
	int v ;
	vis1[u] = 1 ;
	f[u] = a[tot] ;
	size[f[u]]++ ;
	num[u] = ++k ;
	for(int i = 0 ; i < (int)g[u].size() ; i++){
		v = g[u][i].first ;
		if(vis1[v]==0)
			dfs(v) ;
	}
}
int main(){
    freopen("graph.in","r",stdin) ;
    freopen("graph.out","w",stdout) ;
    
	read(n) ; read(m) ; read(t) ;
	int u , v , w ;
	for(int i = 1 ; i <= m ; i++){
		read(u) ; read(v) ; read(w) ;
		g[u].push_back(make_pair(v,w)) ;
		g[v].push_back(make_pair(u,w)) ;
  	}
  	for(int i = 1 ; i <= n ; i++){
  		if(vis1[i])
  			continue ;
  		a[++tot] = i ;
  		k = 0 ;
  		dfs(i) ;
	}
	
	for(int i = 1 ; i <= tot ; i++)
		dis[i].resize(size[a[i]]+3) ;
	for(int i = 1 ; i <= tot ; i++)
		for(int j = 0 ; j < (int)dis[i].size() ; j++)
			dis[i][j] = 0x3f3f3f3f ;
	for(int i = 1 ; i <= tot ; i++)
  	  	dij(i);
  	int x,y ;
  	while(t--){
  		read(x) ; read(y) ;
  		if(f[x]!=f[y])
  			printf("-1\n") ;
  		else
  			printf("%d\n",max(dis[f[x]][num[x]],dis[f[x]][num[y]])) ;
	}
	return 0;
}


