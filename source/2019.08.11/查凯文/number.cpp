#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 ;
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
int a[maxn] ;
int t ;
int tot = 0 ;
long long n ;
void make(long long x){
	if(x>=10)make(x/10) ;
	a[++tot] = x%10 ;
	return ;
}
int b[maxn] ;
int main(){
    freopen("number.in","r",stdin) ;
    freopen("number.out","w",stdout) ;
	read(t) ; 
	while(t--){
		read(n) ;
		tot = 0 ;
		int tmp = 0 ;
		memset(b,0,sizeof(b)) ;
		make(n) ;
		for(int i = 1 ; i <= tot ; i++)
			b[a[i]] = 1 ;
		for(int i = 0 ; i <= 9 ; i++)
			tmp+= b[i] ;
		if(tmp%2==1&&tmp!=1)
			tmp++ ;
		if(tmp==1)
			if(tot==1)
				tmp = 0 ;
			else
				tmp = 4 ;
		printf("%d\n",tmp/2) ;
	}
	return 0;
}
