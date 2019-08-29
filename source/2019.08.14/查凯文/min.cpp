#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 ;
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
int a,b,c,d ;
int n ;
long long ans ;
long long f(int x){
	return a*x*x*x+b*x*x+c*x+d ;
}
int main(){
 	freopen("min.in","r",stdin) ;
    freopen("min.out","w",stdout) ;
	read(n) ;
	read(a) ; read(b) ; read(c) ; read(d) ; 
	long long k ;
	while(n--){
		read(k) ; 
		ans+=f(k) ;
	}
	printf("%d\n",ans) ;
	return 0;
}


