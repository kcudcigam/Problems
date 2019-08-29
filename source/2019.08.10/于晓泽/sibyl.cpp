#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=3*1e5+15;
int n,m; long long val[N];
int num,last[N],nxt[2*N],ver[2*N],du[N];
inline void add(int x,int y)
 {nxt[++num]=last[x]; last[x]=num; ver[num]=y; du[x]++;
  nxt[++num]=last[y]; last[y]=num; ver[num]=x; du[y]++;
 }
 int vis[N],f[N]; long long lazy[N];
 bool hehe[N];
int main()
 {
 freopen("sibyl.in","r",stdin);
 freopen("sibyl.out","w",stdout);	
 int q,u,v,op; scanf("%d%d%d",&n,&m,&q);	
 	
 while(m--) {scanf("%d%d",&u,&v); add(u,v);}	
 
 if(n<=3000 && m<=3000 && q<=3000)
   {while(q--)
    { scanf("%d%d",&op,&u);
     if(op==0)   
            {long long ans=val[u]; 
			 for(int i=last[u];i;i=nxt[i])
			  {int y=ver[i];
			   if(vis[y]==q) continue;
			   vis[y]=q;
			   ans+=val[y];
			  }
             printf("%lld\n",ans);	
			}
     else if(op==1) {scanf("%d",&v); val[u]=val[u]+1ll*v;}
	}
	return 0;
   }
 bool sp=1;
 for(int i=2;i<=n;i++) if(du[i]>=10) {sp=0; break;} 	
 
 if(sp) 	
   {for(int i=last[1];i;i=nxt[i]) hehe[ver[i]]=1;
    hehe[1]=1;  long long cmp=0;
    while(q--)
    { scanf("%d%d",&op,&u);
     if(op==0)   
             if(hehe[u]) printf("%lld\n",cmp+val[u]);
             else        printf("%lld\n",val[u]);
			
     else if(op==1) 
	       {scanf("%d",&v); if(u==1) {cmp+=1ll*v; continue;}
	       
		    for(int i=last[u];i;i=nxt[i])
			  {int y=ver[i];
			   if(vis[y]==q) continue;
			   vis[y]=q;
			   val[y]+=1ll*v;
			  }
			val[u]+=1ll*v;  
		   }
	}
	return 0;
   }
  
  for(int i=1;i<=n;i++)
   { if(du[i]==0) {f[i]=i; vis[i]=1; continue;}
     if(du[i]==1) continue;
    f[i]=i; vis[i]=1;
    for(int j=last[i];j;j=nxt[j])
     {int y=ver[j];
      if(vis[y]) continue;
      vis[y]=1;
      f[y]=i;
	 }
   }
  for(int i=1;i<=n;i++)
     if(vis[i]==0 && du[i]==1)
     { f[i]=i;
       for(int j=last[i];j;j=nxt[j])
       {int y=ver[j];
        if(vis[y]) continue;
        vis[y]=1;
        f[y]=i;
	   }
	 }
  memset(vis,0,sizeof(vis)); 	
  while(q--)
    { scanf("%d%d",&op,&u);
     if(op==0)   printf("%lld\n",val[u]+lazy[f[u]]);	
			
     else if(op==1) 
	   {scanf("%d",&v); 
	    if(f[u]==u) lazy[u]+=1ll*v;
		else    {for(int i=last[u];i;i=nxt[i])
				  {int y=ver[i];
				   if(vis[y]==q) continue;
				   vis[y]=q;
				   val[y]+=1ll*v;
				  }
				 val[u]+=1ll*v; 
			    }
	   }
	}
	
return 0;
 }
