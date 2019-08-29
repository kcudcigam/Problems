#include<bits/stdc++.h>
using namespace std ;
const int maxn = 200000 + 10 ;
const int INF = 0x3f3f3f3f ;
inline void read(int &x){
	x = 0 ;
	char c ;
	int flag = 1 ;
	while(!isdigit(c)){
		c = getchar() ;
		if(c=='-')
			flag = -1 ;
	}
	while(isdigit(c))x = x*10+c-'0',c = getchar() ;
	x*= flag ;
	return ;
}
struct edge{
	int v,w = 0x3f3f3f3f ;
}mini[maxn] ;
vector<edge>g[maxn] ;
int n , m ;
int dis[maxn] ;
int maxm[maxn] ;
int num ;
bool vis[maxn] ;
int main(){
    freopen("rebirth.in","r",stdin) ;
    freopen("rebirth.out","w",stdout) ;
	read(num) ;
	read(n) ; read(m) ;
	int u , v , w ;
	edge t ;
	for(int i = 0 ; i < m ; i++){
		read(u) ; read(v) ; read(w) ;
		t.v = v ;t.w = w ;
		if(mini[u].w > w){
			mini[u].v = v ;
			mini[u].w = w ;
		}
		g[u].push_back(t) ;
		t.v = u ;
		if(mini[v].w > w){
			mini[v].v = u ;
			mini[v].w = w ;
		}
		g[v].push_back(t) ;
	}
	
	for(int i = 1 ; i <= n ; i++)
		printf("-1 ") ;
	return 0 ;
}


