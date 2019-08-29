#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 ;
const int mod  = 998244353 ;
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
			 x = x*10+c-'0' , c = getchar() ;
}
long long n ; 
string s ;
long long mi(long long x,long long p){
	long long t , y ;
	t = 1 ; y = x ;
	while(p){
		if(p&1==1)
			t = t*y%mod ;
		y = y*y%mod ; p = p>>1 ; 
	}
	return t ;
}
int main(){
    freopen("magic.in","r",stdin) ;
    freopen("magic.out","w",stdout) ;
	read(n) ;
	char c ;
	while(~(c=getchar()))s+=c ;
	long long len = s.size() ;
	if(len==n){
		printf("%lld\n",mi(26,n)-1) ;
		return 0 ;
	}
	else{
		long long ans ;
		ans = mi(26,n) - mi(26,n-len)*(len+1)%mod + mi(26,n-len-1) ;
		if(ans<0)
			ans+=mod ;
		ans%=mod ;
		printf("%lld\n",ans) ; 
	}
	return 0;
}

	
