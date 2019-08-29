#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=2*1e5+5; const long long inf=1ll<<50;
int n,m;

int num=1,last[N],nxt[2*N],ver[2*N]; long long len[2*N];
inline void add(int x,int y,int z)
 {nxt[++num]=last[x]; last[x]=num; ver[num]=y; len[num]=z;}
 
bool v[N]; long long dis[N],ans[N]; 
inline void hehe(int del)
 {for(int i=0;i<=n;i++) dis[i]=inf,v[i]=0;	
  dis[1]=0; 
 	
 for(int i=1;i<=n;i++)	
 {int x=0; 
  for(int j=1;j<=n;j++)
   if(!v[j] && dis[j]<dis[x]) x=j;
  v[x]=1;
  for(int j=last[x];j;j=nxt[j])
   { int y=ver[j];
     if(v[y] || j==del || j==(del^1)) continue;
     if(dis[x]+len[j]<dis[y])
      {dis[y]=dis[x]+len[j];
	  }
	//printf("%d\n",del);
   } 
 }
 for(int i=1;i<=n;i++) ans[i]=max(ans[i],dis[i]);
 }
int main()
 {
 freopen("rebirth.in","r",stdin);
 freopen("rebirth.out","w",stdout);		
 int sp,x,y,z; scanf("%d%d%d",&sp,&n,&m);	
 	
 for(int i=1;i<=m;i++) {scanf("%d%d%d",&x,&y,&z); if(x==y) continue; add(x,y,z); add(y,x,z);}	
 	
 for(int i=2;i<=num;i=i+2) hehe(i);
 for(int i=1;i<=n;i++) if(ans[i]==inf)printf("-1 "); 
                       else           printf("%lld ",ans[i]);
 	
return 0;
 }
