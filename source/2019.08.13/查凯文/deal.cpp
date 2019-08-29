#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10 ;
const int maxm = 2e5 + 5 ;
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
int n , x ;
int lowbit(int x){
	return x&(-x) ;
}
int a[maxn],b[maxn],c[maxn] ;
long long ans ;
long long dp[2][maxm] , dp1[2][maxm] ;
int main(){
    freopen("deal.in","r",stdin) ;
    freopen("deal.out","w",stdout) ;
	read(n) ; read(x) ;
	int now1 = 0 ;
	for(int i = 1 ; i <= n ; i++)
		read(a[i]) , read(b[i]) , read(c[i]) ;
	
	int n1 = 0 ,n2 = 0 ;
	dp[0][0] = dp1[0][0] = 1 ;
	for(int i = n ; i >= 1 ; i--){
		memset(dp[(n1^1)],0,sizeof(dp[n1^1])) ;
	
		for(int j = 0 ; j < x+a[n] ; j++){
			dp[n1^1][j] = dp[n1^1][j]+dp[n1][j]  ;
			if(dp[n1][j]>=1)
				for(int k = 1 ; k <= b[i] ; k++)
					if(k*a[i]+j<x+a[i])
						dp[n1^1][j+k*a[i]]++ ;
					else break ;
		}
		n1 = n1 ^ 1 ;
		
		memset(dp1[n2^1],0,sizeof(dp1[n2^1])) ;
		
		for(int j = 0 ; j < x+a[n] ; j++){
			dp1[n2^1][j] = (dp1[n2^1][j]+dp1[n2][j])%inf ;
			if(dp1[n2][j]>=1)
				for(int k = 1 ; k <= c[i] ; k++)
					if(k*a[i]+j<x+a[n])
						dp1[n2^1][j+k*a[i]]++ ;
					else break ;
		}
		n2 = n2^1 ;
	}
	for(int i = x ; i < x+a[n] ; i++)
		ans = (ans+dp[n1][i]*dp1[n2][i-x])%inf ;
	printf("%lld",ans) ;
	return 0;
}


