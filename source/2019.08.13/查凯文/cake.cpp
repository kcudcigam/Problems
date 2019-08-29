#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 ;
const long long inf = 1000000007 ;
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
long long f[maxn][maxn] ;
int n,m ;
int main(){
    freopen("cake.in","r",stdin) ;
    freopen("cake.out","w",stdout) ;
	read(n) ; read(m) ;
	if(n==1&&m==1){
		printf("1\n") ;
		return 0 ;
	}
	f[1][1] = 1 ; f[1][2] = 1 ;
	for(int i = 3 ; i <= 300 ; i++)
		for(int j = 1 ; j < i ; j++)
			f[1][i] = (f[1][i] + f[1][i-j]*f[1][j])%inf ;
	
	for(int i = 2 ; i <= 300 ; i++)
		for(int j = 2 ; j < i ; j++)
			f[i][1] = (f[i][1] + f[i-j][1]*f[j][1])%inf ;
			
	for(int i = 2 ; i <= 300 ; i++)
		for(int j = 1 ; j <= 300 ; j++){
			for(int k = 1 ; k < j ; k++)
				f[i][j] = (f[i][j] + f[i][j-k]*f[i][k])%inf ;
			for(int k = 1 ; k < i ; k++)
				f[i][j] = (f[i][j] + f[i-k][j]*f[k][j])%inf ;		
		}
		
	printf("%lld",f[n][m]) ;
	return 0;
}


