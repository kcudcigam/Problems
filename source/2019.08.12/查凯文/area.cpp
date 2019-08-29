#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 ;
template <typename T> void read(T &x){
		 x = 0 ;
		 char c = getchar() ;
		 int flag = 1 ;
		 while(!isdigit(c)){
			 c = getchar() ;
			 if(c=='-')
				 flag = -1 ;
		 }
		 while(isdigit(c)){
			 x = x*10+c-'0' ;
			 c = getchar() ;
		 }
		 x = x*flag ;
}
int x,y ;
long long a[] = {1,2,4,16,256,65536} ;
long long f[maxn] ;
int main(){
    freopen("area.in","r",stdin) ;
    freopen("area.out","w",stdout) ;
	read(x) ; read(y) ;
	x++ ; y++ ;
	f[1] = 1 ;
	int i ;
	for(i = 1 ; a[i]*a[i] <= max(x,y) ; i++) ;
	for(int j = 2 ; j <= i ; j++)
		f[j] = a[j-1]*a[j-1] + f[j-1] ;
	
	printf("%lld",f[i]) ;
	return 0;
}


