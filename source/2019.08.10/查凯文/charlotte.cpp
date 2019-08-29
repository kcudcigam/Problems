#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000 ;
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
int t , n ;
int ti[maxn],x[maxn],y[maxn] ;
int main(){
    freopen("charlotte.in","r",stdin) ;
    freopen("charlotte.out","w",stdout) ;
	read(t) ;
	while(t--){
		read(n) ;
		for(int i = 1 ; i <= n ; i++){
			read(ti[i]) ; 
			read(x[i]) ; read(y[i]) ;
		}
		for(int i = 0 ; i < n ; i++){
			int q = ti[i+1] - ti[i] ;
			int dis = abs(x[i+1]-x[i])+abs(y[i+1]-y[i]) ;
			if(q<dis){printf("No\n");break;}
			if(q>=dis)if((q-dis)%2==1){printf("No\n");break;}
			if(i==n-1)
				printf("Yes\n") ;
		}
	}
	return 0;
}


