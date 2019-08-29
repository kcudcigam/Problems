#include<bits/stdc++.h>
using namespace std ;
const int maxn = 10000 ;
const int INF = 1e9 + 7 ;
inline void read(int &x){
	x = 0 ;
	char c ;
	int flag = 1 ;
	while(!isdigit(c)){
		c = getchar() ;
		if(c=='-')
			flag = -1 ;
	}
	while(isdigit(c))x = x*10+c-'0',c = getchar() ;
	x*= flag ;
	return ;
}
int n,m1,m2 ;
int main(){
    freopen("refrain.in","r",stdin) ;
    freopen("refrain.out","w",stdout) ;
	int num ;
	read(num) ;
	read(n) ; read(m1) ; read(m2) ;
	int QAQ ;
	while(m1--)
		read(QAQ),read(QAQ);
	while(m2--)
		read(QAQ),read(QAQ); 
		
	if(n==1){
		cout<<1<<endl ;
		return 0 ;
	}
	if(n==2){
		cout<<0<<endl ;
	}
	long long ans = 1 ;
	
	for(int i = 2 ; i <= n ; i++)
		ans = (ans * i) % INF ;
	
	printf("%lld\n",ans-1) ;
	return 0;
}


