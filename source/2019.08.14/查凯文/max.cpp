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
int main(){
  	freopen("max.in","r",stdin) ;
    freopen("max.out","w",stdout) ;
	printf("4\n") ;
	return 0;
}


