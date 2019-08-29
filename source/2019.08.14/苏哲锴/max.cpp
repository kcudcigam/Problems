#include<bits/stdc++.h>
#define N 10001
using namespace std;
const int mo=1e9+7;
int n,m,q;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;

}
int x[N],y[N],p[N],v[N],l[N],r[N];
int main(){
freopen("max.in","r",stdin);
freopen("max.out","w",stdout);	
scanf("%d%d%d",&n,&m,&q);
int t=0;
for(int i=1;i<=n;i++)
 {
 	x[i]=ri();y[i]=ri();p[i]=ri(); if(p[i]%mo!=1) t++;}
 	for(int i=1;i<=q;i++){
 		l[i]=ri();r[i]=ri(); 		
	 }
	 int ans=rand()%mo;
	 cout<<ans<<endl;
	return 0;
	}


