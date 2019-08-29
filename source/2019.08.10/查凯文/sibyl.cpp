#include<bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10 ;
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
			 x = x*10+c-'0',c = getchar() ;
			 
}
int n,m,q ;
vector<int>g[maxn] ;
int ans[maxn] ;
int main(){
    freopen("sibyl.in","r",stdin) ;
    freopen("sibyl.out","w",stdout) ;
	read(n) ; read(m) ; read(q) ;
	int u,v ;
	for(int i = 1 ; i <= m ; i++){
		read(u) ; read(v) ;
		g[u].push_back(v) ;
		g[v].push_back(u) ;
	}
	
	int k,x,d ;
	while(q--){
		read(k) ;
		if(k==1){
			read(x) ; read(d) ;
			ans[x]+= d ;
			for(int i = 0 ; i < (int)g[x].size() ; i++)
				ans[g[x][i]]+= d ;
		}
		else{
			read(x) ;
			printf("%d\n",ans[x]) ;
		}
	}
	return 0;
}


