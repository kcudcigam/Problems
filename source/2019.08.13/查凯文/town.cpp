#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10 ;
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
		 x = x * flag ;
}
int n ;
int f[maxn] ;
int sz[maxn] ;
int find(int x){
	if(f[x]==x)	
		return x ;
	return f[x] = find(f[x]) ;
}
int main(){
    freopen("town.in","r",stdin) ;
    freopen("town.out","w",stdout) ;
	read(n) ;
	for(int i = 1 ; i <= n ; i++)
		f[i] = i ;
	int u , v , x , y ;
	for(int i = 1 ; i < n ; i++){
		read(x) ; read(y) ;
		u = find(x) ; v = find(y) ;
		if(u==v)
			continue ;
		f[u] = f[v] ;
		sz[v] = sz[v] + sz[u] + 1 ;
		printf("%d\n",sz[v]) ;
	}
	return 0;
}


