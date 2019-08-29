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
int num[5] ;
int n,m ;
long long ans ;
long long G(int x){
	long long t = (long long)x ;
	return t*num[0]+t*t*num[1]+t*t*t*num[2]+t*t*t*t*num[3]+t*t*t*t*t*num[4];
}
int l[maxn],r[maxn],a[maxn];
bool use[maxn] ;
bool flag = 1 ;
bool check(int ll,int rr,int x,int y){
	if(ll>=x&&ll<=y)
		return true ;
	if(rr>=x&&rr<=y)
		return true ;
	if(ll<=x&&rr>=y)
		return true ;
	return false ;
}
int main(){
    freopen("stand.in","r",stdin) ;
    freopen("stand.out","w",stdout) ;
	read(n) ;
	read(m) ;
	for(int i = 0 ; i < 5 ; i++)
		read(num[i]) ;
	for(int i = 1 ; i <= n ; i++){
		read(l[i]) ; read(r[i]) ;
		if(l[i]!=1||r[i]!=m)
			flag = false ; 
	}
	if(flag)
		printf("%lld",G(n));
	else{
		int k = n ;
		while(k!=0){
			int lm = 0 , rm = 0, tmp = 0;
			for(int i = 1 ; i <= n ; i++)
				for(int j = l[i] ; j <= r[i] ; j++)
					if(use[i]==0)
						a[j]++ ,tmp = max(tmp,a[j]) ;
			for(int i = 1 ; i <= m ; i++){
				if(a[i]==tmp&&a[i-1]!=tmp)
					lm = i ;
				if(a[i]==tmp&&a[i+1]!=tmp)
					rm = i ;
			}
			ans+=G(tmp) ;
			memset(a,0,sizeof(a)) ;
			for(int i = 1 ; i <= n ; i++)
				if(use[i]==0)
					if(check(l[i],r[i],lm,rm))
						k-- , use[i] = 1 ;
		}
		printf("%lld\n",ans) ;
	}
	return 0;
}


