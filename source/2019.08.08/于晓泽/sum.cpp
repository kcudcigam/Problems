#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100000+5;
int n; long long a[N],p[N],q[N],pre[N],suf[N],ans=-2147483647;
int main()
 {	
 freopen("sum.in","r",stdin);
 freopen("sum.out","w",stdout); 
 scanf("%d",&n);	
 for(int i=1;i<=n;i++)	
  { scanf("%lld",&a[i]); p[i]=p[i-1]+a[i];
  } 	
 	
 for(int i=n;i>0;i--) q[i]=q[i+1]+a[i];		
 	
 long long hehe=0; pre[0]=-2147483647;
 for(int i=1;i<=n;i++)	
  { pre[i]=max(pre[i-1],p[i]-hehe);
    hehe=min(hehe,p[i]);
  }		
 hehe=0; suf[n+1]=-2147483647;
 for(int i=n;i>0;i--)
  { suf[i]=max(suf[i+1],q[i]-hehe);
   hehe=min(hehe,q[i]);
  }	
 for(int i=1;i<n;i++)	ans=max(ans,pre[i]+suf[i+1]);	
 printf("%lld",ans);
return 0; 	
 } 
