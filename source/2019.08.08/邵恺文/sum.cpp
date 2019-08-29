#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
long long sum=-INT_MAX*2;
int a[maxn+5];
long long s[maxn+5],m[maxn+5],f[maxn+5],g[maxn+5];
pair<int,long long> ta[maxn+5],tb[maxn+5];
template<typename T>void read(T &x){
   int f=1;x=0;char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
   for(;isdigit(c);c=getchar())x=x*10+c-'0';
   x*=f;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	read(n);
	s[0]=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	m[n+1]=0;
	for(int i=n;i>=1;i--){
		m[i]=m[i+1]+a[i];
	}
	f[1]=a[1];g[n]=a[n];
	int nowmax=f[1],tota=1;
	ta[tota].first=1;ta[tota].second=f[1];
	for(int i=2;i<=n;i++)
	   for(int j=1;j<=i;j++){
	   	  f[i]=max(f[i],max(f[j],s[i]-s[j-1]));
	   	  if(f[i]>nowmax){
	   	  	  nowmax=f[i];
			  tota++;
			  ta[tota].first=i;
			  ta[tota].second=nowmax; 
		  }
	   }
	nowmax=g[n];int totb=1;  
	tb[totb].first=n;tb[totb].second=g[n]; 	
	for(int i=n-1;i>=1;i--)
	   for(int j=n;j>=i;j--){
	   	  g[i]=max(g[i],max(g[j],m[i]-m[j+1]));
	   	  if(g[i]>nowmax){
	   	  	  nowmax=g[i];
			  totb++;
			  tb[totb].first=i;
			  tb[totb].second=nowmax; 
		  }
	   }
	   	
	for(int i=1;i<=tota;i++)
	   for(int j=1;j<=totb;j++)
	     if(ta[i].first<tb[j].first-1)sum=max(sum,ta[i].second+tb[j].second);
	     else continue;
	cout<<sum<<endl;
	return 0;
}


