#include<bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 10 ;
int n,q ;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int f[maxn] ; 
int sum[maxn] ;
int find(int x){
	if(f[x]==x)
		return x ;
	return f[x] = find(f[x]) ;
}
int main(){
    freopen("merge.in","r",stdin) ;
    freopen("merge.out","w",stdout) ;
	read(n) ; read(q) ;
	for(int i = 1 ; i <= n ; i++)
		f[i] = i ;
	
	int a,x,y ;
	for(int i = 1 ; i <= q ; i++){
		read(a) ; read(x) ; read(y) ;
		if(a==1){
			int u = find(x) ;
			int v = find(y) ;
			if(u==v)continue ;
			f[u] = f[v] ;
		}
		if(a==2){
			int u = find(x) ;
			for(int j = 1 ; j <= n ; j++)
				if(find(j)==u)
					sum[j]+= y ;
		} 
	}
	
	for(int i = 1 ; i <= n ; i++)
		printf("%d ",sum[i]) ;
	return 0;
}


