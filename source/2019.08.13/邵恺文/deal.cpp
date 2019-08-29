#include<bits/stdc++.h>
using namespace std;
template <typename _T> inline _T read(_T &x){
	char ch=getchar();int minus=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();
	if(ch=='-'){
		minus=1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(minus)return -x;
	return x;
}
long long ans=0;
int n,X,tem;
const int p=1000000007;
const int maxn=10000+5;
int a[maxn],b[maxn],c[maxn];
void dfs1(int r,int k){
	if(r<0||k<1)return;
	if(r==0)ans=(ans+1)%p;
	for(int i=1;i<=k;i++)
	   for(int j=0;j<=c[i];j++)
	   	  dfs1(r-a[i]*j,k-1);
}
void dfs(int m,int k){
	if(m>(X+a[k])||k<1)return;
	if(m==X){
	   ans=(ans+1)%p;
	   return;
	}
	if(m>X){
		if(k<=1)return;
	    dfs1(m-X,k-1);	
	} 
	for(int i=1;i<=k;i++)
	   for(int j=0;j<=b[i];j++)
	   	  dfs(m+a[i]*j,k-1);	
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);read(X);
	for(int i=1;i<=n;i++){
		read(a[i]);read(b[i]);read(c[i]);
	} 
    dfs(0,n);
    cout<<ans<<endl;
	return 0;
}


