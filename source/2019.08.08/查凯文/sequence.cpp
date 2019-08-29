#include<bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 10 ;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n,m ;
long long ans ;
long long a[maxn] ;
int main(){
    freopen("sequence.in","r",stdin) ;
    freopen("sequence.out","w",stdout) ;
	read(n) ; read(m) ;
	
	int l,r;
	long long s,e ;
	bool ok = false ;
	for(int i = 1 ; i <= m ; i++){
		read(l) ; read(r) ;
		read(s) ; read(e) ;
		a[l]+=s ; a[r]+= e ;
		long long add = (e-s)/(r-l) ;
		if(add!=0)
			for(int j = l+1 ; j < r ; j++)
				a[j]+=s+add*(j-l) ;
		else
			a[l]+= s,a[r+1]-= s,ok = true ;
	}
	if(ok)
		for(int i = 2 ; i <= n ; i++)
			a[i]+=a[i-1] ;
			
	ans = a[1] ;
	for(int i = 2 ; i <= n ; i++)
		ans = ans ^ a[i] ;
	
	printf("%lld\n",ans) ;
	return 0;
}


