#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10 ;
int q = 2e10 ;
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
int n ;
int a[5][maxn] ;
int num[20] , tot[5] ;
long long ans ;
bool cmp(int x,int y){return x > y ;}
int main(){
   freopen("debate.in","r",stdin) ;
   freopen("debate.out","w",stdout) ;
	read(n) ;
	int li,w ;
	num[0] = 3 ; num[1] = 1 ; num[11] = 4 ; num[10] = 2 ; 
	for(int i = 0 ; i < n ; i++){
		read(li) ; read(w) ;
		a[num[li]][tot[num[li]]] = w ;
		tot[num[li]]++ ; 
	}
	for(int i = 1 ; i <= 4 ; i++)
		sort(a[i],a[i]+tot[i],cmp) ;
	for(int i = 0 ; i < min(tot[1],tot[2]) ; i++)
		ans+=(long long)a[1][i] , ans+=(long long)a[2][i] ;
	for(int i = 0 ; i < min(tot[3],tot[4]) ; i++)
		ans+=(long long)a[4][i] ;
	for(int i = 0 ; i < tot[4] ; i++)
		ans+=a[4][i] ;
	printf("%lld\n",ans) ;
	return 0;
}

 
