#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 ;
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
int n , k ;
int a[20][20] ;
int y[] = {5,7,2,4,6,8,10,1,3,5,7,9,11,2,4,6,8,10,1,3,5,7,9,11,2,4,6,8,10,5,7} ;
int x[] = {1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7} ;
int cy[] = {6,3,9,6,3,9,6} ;
int cx[] = {2,3,3,4,5,5,6} ; 
int dy[] = {-1,1,-2,2,-1,1} ;
int dx[] = {-1,-1,0,0,1,1} ;
int sx[32],sy[32] ;
int tot , sum ;
bool line1[10][32] , line2[25][32] , line3[30][32],line4[7][32];
bool check(){
	memset(line1,0,sizeof(line1)) ;
	memset(line2,0,sizeof(line2)) ;
	memset(line3,0,sizeof(line3)) ;
	memset(line4,0,sizeof(line4)) ;
	int p ;

	for(int i = 0 ; i < 31 ; i++){
		p = a[x[i]][y[i]] ;
		if(p==0)
			continue ;
		if(line1[x[i]][p]==1)
			return false ;
		line1[x[i]][p] = 1 ;
	}
	
	for(int i = 0 ; i < 31 ; i++){
		p = a[x[i]][y[i]] ;
		if(p==0)
			continue ;
		if(line2[x[i]+y[i]][p]==1)
			return false ;
		line2[x[i]+y[i]][p] = 1 ;
	}
	
	for(int i = 0 ; i < 31 ; i++){
		p = a[x[i]][y[i]] ;
		if(p==0)
			continue ;
		if(line3[x[i]-y[i]+11][p]==1)
			return false ;
		line3[x[i]-y[i]+11][p] = 1 ;
	}
	
	for(int i = 0 ; i < 7 ; i++){
		for(int j = 0 ; j < 6 ; j++){
			int nx = cx[i] + dx[j],ny = cy[i]+dy[j] ; 
			if(a[nx][ny]==0)
				continue ;
			if(line4[i][a[nx][ny]]==1)
				return false ;
			line4[i][a[nx][ny]] = 1 ;
		}
	}
	
	return true ;
}
void dfs(int dep){
	if(check()==false)
		return ;
	if(dep==tot){
		sum++ ;
		if(sum==n){
			printf("Found\n") ;
			for(int i = 0 ; i < 31 ; i++)
				printf("%d ",a[x[i]][y[i]]) ;
			exit(0) ;
		}
		return ; 
	}
	for(int i = 1 ; i <= k ; i++){
		a[sx[dep]][sy[dep]] = i ;
		dfs(dep+1) ;
		a[sx[dep]][sy[dep]] = 0 ;
	}
}
int main(){
   freopen("hexodoku.in","r",stdin) ;
   freopen("hexodoku.out","w",stdout) ;
	read(k) ; read(n) ;
	int num ; 
	for(int i = 0 ; i < 31 ; i++){
		read(num) ; 
		a[x[i]][y[i]] = num ;
	}
	
	if(k<7){
		printf("No way\n") ;
		return 0 ;
	}
	if(k==7&&n>10080){
		printf("No way\n") ;
		return 0 ;
	}
	if(check()==false){
		printf("No way\n") ;
		return 0 ;
	}
	
	for(int i = 0 ; i < 31 ; i++)
		if(a[x[i]][y[i]]==0)
			sx[tot] = x[i],sy[tot++] = y[i] ;  
	dfs(0) ;

	cout<<sum<<endl ;
	printf("No way\n") ;
	return 0;
}


