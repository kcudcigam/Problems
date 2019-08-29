#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10 ;
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
		 x = x * flag ;
}
int n , m ;
int a[maxn],b[maxn],c[maxn*2],tp;
int la[maxn],lb[maxn] ;
bool ok ;
int found_a(int x){
	int l = 1 , r = n ;
	int mid ;
	int ret = 0 ;
	while(l<=r){
		mid = (l+r)/2 ;
		if(b[mid]>a[x])
			r = mid - 1 ;
		else
			l = mid + 1 , ret = mid ;
	}
	return ret ;
}
int found_b(int x){
	int l = 1 , r = n ;
	int mid ;
	int ret = 0 ;
	while(l<=r){
		mid =  (l+r)/2 ; 
		if(a[mid]>b[x])	
			r = mid - 1 ;
		else
			l = mid + 1 , ret = mid; 
	}
	return ret ;
} 
void found1(int l1,int r1,int l2,int r2){
	int l = l1 , r = r1 ;
	int mid,f ;
	int need = (r2-l2+r1-l1+3)/2 ;
	while(l<=r){
		mid = (l+r)/2 ;
		f = mid-l1+1+max(la[mid]-l2+1,0) ;
		if(f==need){
			ok = 1 ;
			printf("%d\n",a[mid]) ; 
			return ;
		}
		if(f<need)
			l = mid + 1 ;
		else
			r = mid - 1 ;
	}
}
void found2(int l1,int r1,int l2,int r2){
	int l = l2 , r = r2 ;
	int mid,f ;
	int need = (r2-l2+r1-l1+3)/2 ;
	while(l<=r){
		mid = (l+r)/2 ;
		f = mid-l2+1+max(lb[mid]-l1+1,0) ;
		if(f==need){
			ok = 1 ;
			printf("%d\n",b[mid]) ; 
			return ;
		}
		if(f<need)
			l = mid + 1 ;
		else
			r = mid - 1 ;
	}
}
int main(){
	freopen("median.in","r",stdin) ;
    freopen("median.out","w",stdout) ;
	read(n) ; read(m) ;
	for(int i = 1 ; i <= n ; i++)
		read(a[i]) ;
	for(int i = 1 ; i <= n ; i++)
		read(b[i]) ;
		
	for(int i = 1 ; i <= n ; i++){
		la[i] = found_a(i) ;
		lb[i] = found_b(i) ;
 	}
 	
 	int k ; 
 	int x,y,z ;
 	int l1,r1,l2,r2 ;
 	while(m--){
 		read(k) ;
 		if(k==1){
 			read(x) ; read(y) ; read(z) ;
 			if(x==0){
 				int tmp = a[y] ;
 				int tmp2 = la[y] ;
 				a[y] = z ;
 				if(tmp==z)
 					continue ;
 				la[y] = found_a(y) ;
 				if(tmp<z)
 					for(int i = tmp2 + 1 ; i <= la[y] ; i++)
 						lb[i]-- ;
				 else
				 	for(int i = la[y] + 1 ; i <= tmp2 ; i++)
				 		lb[i]++ ;
			}
			else{
				int tmp = b[y] ;
				int tmp2 = lb[y] ;
				b[y] = z ;
 				if(tmp==z)
 					continue ;
 				lb[y] = found_b(y) ;
 				if(tmp<z)
 					for(int i = tmp2 + 1 ; i <= lb[y] ; i++)
 						la[i]-- ;
				 else
				 	for(int i = lb[y] + 1 ; i <= tmp2 ; i++)
				 		la[i]++ ;
			}
		 }
		 else{
		 	ok = 0 ;
		 	read(l1) ; read(r1) ; read(l2) ; read(r2) ;
			if(a[r1]<=b[l2]){
				if(r1-l1+1>=(r2-l2+r1-l1+3)/2)
					printf("%d\n",a[l1+(r2-l2+r1-l1+2)/2]) ;
				else
					printf("%d\n",b[l2+(r2-l2+r1-l1+2)/2-(r1-l1+1)]) ;
				continue ;
			}
			if(b[r2]<=a[l1]){
				if(r2-l2+1>=(r2-l2+r1-l1+3)/2)
					printf("%d\n",b[l2+(r2-l2+r1-l1+2)/2]) ;
				else
					printf("%d\n",a[l1+(r2-l2+r1-l1+2)/2-(r2-l2+1)]) ;
				continue ;
			}
			int len1 = r1-l1+1 , len2 = r2-l2+1 ;
			found1(l1,r1,l2,r2) ;
			if(ok==0)found2(l1,r1,l2,r2) ;
			if(ok==0){
				memset(c,0,sizeof(c)) ;
				tp = 0 ;
				for(int i = l1 ; i <= r1 ; i++)
					c[tp++] = a[i] ;
				for(int i = l2 ; i <= r2 ; i++)
					c[tp++] = b[i] ;
				sort(c,c+tp) ;
				printf("%d\n",c[(r2-l2+r1-l1+2)/2]) ;
			}
		 }
	}
	return 0;
}


