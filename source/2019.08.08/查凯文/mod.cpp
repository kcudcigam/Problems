#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000000 + 10 ;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int q ;
int n,p ;	
int sum[] = {0,0,2,12,58,310,1886,13244,106002,
			 954090,9540982} ;
long long ans[maxn] ;
int main(){
   freopen("mod.in","r",stdin) ;
   freopen("mod.out","w",stdout) ;
	read(q) ;
	for(int i = 1 ; i <= 5 ; i++)
		ans[i] = sum[i] ;
	while(q--){
		read(n) ; read(p) ;
		for(int i = 5 ; i < n ; i++){
			if(i%2==0)
				ans[i+1] = (((ans[i]+i)%p)*((i+1)%p))%p ;
			else
				ans[i+1] = (((ans[i]+i-1)%p)*(i+1)+2)%p ;
		}
		printf("%lld\n",ans[n]) ;
	}
	return 0;
}


