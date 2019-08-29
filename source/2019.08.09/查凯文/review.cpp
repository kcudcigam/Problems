#include<bits/stdc++.h>
using namespace std ;
const int maxn = 100 ;
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
long long y ;
int a[maxn][2] ;
int k[maxn] ;
int len ;
int m ;
int main(){
    freopen("review.in","r",stdin) ;
    freopen("review.out","w",stdout) ;
	scanf("%lld",&y) ;
	long long tmp = y ;
	if(y==1){
		printf("2 1\n") ;
		printf("1 2\n") ;
		return 0 ;
	}
	while(tmp!=0){
		k[++len] = tmp%2 ;
		tmp/=2 ;
	}
	for(int i = 2 ; i < len ; i++)
		if(k[i]!=0)
			m+=2 ;
	if(k[1]==1)m++ ;
	
	
	printf("%d %d\n",(len-1)*2+2,(len-1)*4+m) ;
	
	int tmp1 = 1 ; 
	a[1][0] = tmp1 ;
	for(int i = 2 ; i <= 100 ; i++)
		for(int j = 0 ; j < 2 ; j++)
			a[i][j] = ++tmp1 ;
	
	k[1] = y%2 ;
	if(k[1]==1)
		printf("1 %d\n",(len-1)*2+2) ;
	
	for(int i = 2 ; i < len ; i++)
		if(k[i]!=0)
			for(int j = 0 ; j < 2 ; j++)
				printf("%d %d\n",a[i][j],(len-1)*2+2) ; 
			
	printf("%d %d\n%d %d\n",a[1][0],a[2][0],a[1][0],a[2][1]) ;
	for(int i = 2 ; i < len ; i++)
		for(int j = 0 ; j < 2 ; j++)
			for(int k1 = 0 ; k1 < 2 ; k1++)
				printf("%d %d\n",a[i][j],a[i+1][k1]) ;
	
	for(int i = 0 ; i < 2 ; i++)
		printf("%d %d\n",a[len][i],(len-1)*2+2) ; 
	return 0;
}


