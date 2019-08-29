#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2*1e5+5;
int n,last[N],nxt[N]; long long A,B,C,D;
long long a[N],b[N],f[1005][1005]; int tot;
inline void del(int x)
 { nxt[last[x]]=nxt[x];
   last[nxt[x]]=last[x];
 }
int main()
 {
 freopen("min.in","r",stdin);
 freopen("min.out","w",stdout);	
 scanf("%d%lld%lld%lld%lld",&n,&A,&B,&C,&D);	
 for(int i=1;i<=n;i++)	
  {scanf("%lld",&b[i]); 
   a[i]=A*b[i]*b[i]*b[i]+
           B*b[i]*b[i]+C*b[i]+D;
   last[i]=i-1;
   nxt[i]=i+1;        
  }nxt[0]=1; last[n+1]=n;
 	
 while(1)
 {int i=0; bool biao=1;
  while(i<n)
   {i=nxt[i]; //printf("1:%d\n",i);
    if(a[i]<0 && a[last[i]]<0) 
      { if(b[last[i]]<b[i])       {b[i]=b[last[i]]; a[i]=a[last[i]];}
	    del(last[i]); biao=0;
	  }
	else if(a[last[i]]>0 && a[i]<0 && b[last[i]]<b[i])  
	                          {b[i]=b[last[i]]; a[i]=a[last[i]]; del(last[i]); biao=0; }
	else if(a[i]>0 && a[last[i]]<0 && b[i]<b[last[i]])       {del(last[i]); biao=0;}                      
   }
   
   
    i=0;
   while(i<n)
   { i=nxt[i];
    if(a[i]>0 && a[last[i]]>0) 
                          {b[i]=min(b[i],b[last[i]]); 
						   a[i]=a[i]+a[last[i]]; 
						   del(last[i]);
						   biao=0;
						  }
   }
  i=0; 
  while(i<n)
   { i=nxt[i];
    int x=last[i]; int y=last[x];
    if(x==0 || y==0) continue;
    
    int cmp=min(b[i],min(b[x],b[y]));
    if(a[i]+a[x]+a[y]<=a[cmp])  { b[y]=cmp; a[y]=a[cmp]; del(i); del(x); biao=0;}
   } 
  if(biao) break;                         
 }
 int i=0;  long long ans=0;
  while(i<n)
   {i=nxt[i]; ans=ans+a[i];
   }
 printf("%lld\n",ans);  
return 0; 	
 } 
