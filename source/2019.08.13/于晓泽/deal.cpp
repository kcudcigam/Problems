#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100+15,M=100*2+15,mod=1000000007;
int n,x;
struct point{int a,b,c;}p[N];
int f[M],g[M];
int main()
 {
 freopen("deal.in","r",stdin);
 freopen("deal.out","w",stdout);	
 scanf("%d%d",&n,&x);	
 for(int i=1;i<=n;i++) scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);	
 	
 for(int i=1;i<=n/2;i++) swap(p[i],p[n-i+1]);	
 	
 f[0]=g[0]=1;
 for(int i=1;i<=n;i++)	
  for(int j=200;j>0;j--)	
 	{ 
	  if(p[i].a<=j-x) continue;
	  for(int k=1;k<=p[i].b;k++) 
 	      if(j-p[i].a*k>=0)  f[j]=(f[j]+f[j-p[i].a*k])%mod;
 	      else break;`
	}
 	
 for(int i=1;i<=n;i++)	
  for(int j=100;j>0;j--)	
 	{ for(int k=1;k<=p[i].c;k++) 
 	      if(j-p[i].a*k>=0)  g[j]=(g[j]+g[j-p[i].a*k])%mod;
 	      else break;
	}	
 long long ans=0;
 for(int i=x;i<=200;i++) ans=(ans+f[i]*g[i-x]%mod)%mod;	
 printf("%lld\n",ans);
return 0;
 }
