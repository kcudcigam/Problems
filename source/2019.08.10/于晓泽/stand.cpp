#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=250+5,M=500+5;
int n,m; long long a,b,c,d,e;

int  t[M],sum[M];
struct hehe{int x,y;}q[N]; bool del[N];
bool cmp(hehe g,hehe h) {if(g.x!=h.x) return g.x<h.x; return g.y<h.y;}
bool cmp2(hehe g,hehe h) {if(g.x!=h.x) return g.x>h.x; return g.y>h.y;}
int main()
 {
 freopen("stand.in","r",stdin);
 freopen("stand.out","w",stdout);	
 scanf("%d%d",&n,&m);	
 scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
 if(a && !b && !c && !d && !e) {printf("%lld",1ll*a*n); return 0;}	
 	
 for(int i=1;i<=n;i++)	
  {scanf("%d%d",&q[i].x,&q[i].y);
   t[2*i-1]=q[i].x,t[2*i]=q[i].y;
  }		
 sort(t+1,t+2*n+1); int tot=unique(t+1,t+2*n+1)-t-1;	

 for(int i=1;i<=n;i++) 
   q[i].x=lower_bound(t+1,t+tot+1,q[i].x)-t,
   q[i].y=lower_bound(t+1,t+tot+1,q[i].y)-t;
 
 sort(q+1,q+n+1,cmp);
 
 long long ans1=0; int dec=0;
 for(int k=1;k<=n;k++)
   {if(dec==n) break;
   	for(int i=1;i<=n;i++)
   	 { if(del[i]) continue;
   	  for(int j=q[i].x;j<=q[i].y;j++)  sum[j]++;
	   
	 }
	long long x=0,pos=0; 
	for(int i=1;i<=tot;i++) 
	 {if(sum[i]>x) x=sum[i],pos=i; 
	  sum[i]=0;}
     
    for(int i=1;i<=n;i++)
	 if(q[i].x<=pos && pos<=q[i].y) del[i]=1,dec++; 
	 
    ans1=ans1+a*x+b*x*x+c*x*x*x+d*x*x*x*x+e*x*x*x*x*x;
   }	
  //printf("%lld",ans1);  
  long long ans2=0; long long cnt=1;
  int l=q[1].x,r=q[1].y;
  for(int i=2;i<=n;i++)
   {if(q[i].x>r) {ans2=ans2+a*cnt+b*cnt*cnt+c*cnt*cnt*cnt+d*cnt*cnt*cnt*cnt+e*cnt*cnt*cnt*cnt*cnt; 
                  cnt=1; l=q[i].x,r=q[i].y;
                  continue;
				 }
    l=q[i].x;  cnt++;
    if(q[i].y<r) r=q[i].y;  
   }
  ans2=ans2+a*cnt+b*cnt*cnt+c*cnt*cnt*cnt+d*cnt*cnt*cnt*cnt+e*cnt*cnt*cnt*cnt*cnt;  
    
  printf("%lld",max(ans1,ans2)); 
return 0;
 }
