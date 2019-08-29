#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10 ;
const int INF = -100000001 ;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n ;
long long a[maxn] ;
long long dp[maxn] ;
long long ans = INF ;
int main(){
    freopen("sum.in","r",stdin) ;
    freopen("sum.out","w",stdout) ;
	read(n) ;
	for(int i = 1 ; i <= n ; i++)
		read(a[i]) ;
	
	dp[0] = INF ;
	long long ans1 , ans2 ;
	for(int i = 2 ; i <= n ; i++){
		ans1 = INF ; ans2 = INF ; 
		for(int j = 1 ; j < i ; j++){
			dp[j] = INF ;
			dp[j] = max(a[j],dp[j-1]+a[j]) ;
			ans1 = max(ans1,dp[j]) ;
		}
		dp[i-1] = INF ;
		for(int j = i ; j <= n ; j++){
			dp[j] = INF ;
			dp[j] = max(a[j],dp[j-1]+a[j]) ;
			ans2 = max(ans2,dp[j]) ;
 		}
 		ans = max(ans,ans1+ans2) ;
	}
	printf("%lld\n",ans) ; 
 	return 0 ;  
}


