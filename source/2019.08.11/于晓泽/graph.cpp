#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=300000+5;
int n,m;
struct edge{int x,y, len;}q[N];
bool cmp(edge g,edge h) {return g.len<h.len;}
bool cmp2(edge g,edge h)  {return g.x<h.x;}

int fa[N],siz[N];
int find(int x) {if(fa[x]==x) return x; return fa[x]=find(fa[x]);}

int num=1,last[N],nxt[2*N],ver[2*N],len[2*N];
inline void add(int x,int y,int z) 
 {nxt[++num]=last[x]; last[x]=num; ver[num]=y; len[num]=z;}
 
int f[N][20],g[N][20],deep[N]; bool vis[N];  //2^18
void dfs(int x)
 {if(vis[x]) return;
  vis[x]=1;
  for(int j=1;(1<<j)<=n && (1<<j)<=deep[x];j++)	
 	{ f[x][j]=f[f[x][j-1]][j-1];
 	  g[x][j]=max(g[x][j-1],g[f[x][j-1]][j-1]);
 	 // printf("%d ",g[x][j]);
	}
   //printf("\n");	
 	
  for(int i=last[x];i;i=nxt[i])
   {int y=ver[i];
    if(vis[y]) continue;
    f[y][0]=x; g[y][0]=len[i]; deep[y]=deep[x]+1; 
    dfs(y);
   }
 } 
inline int ask(int x,int y) 
 {if(deep[x]<deep[y]) swap(x,y);
  int res=0;
  for(int j=19;j>=0;j--)
   if(deep[f[x][j]]>=deep[y]) { res=max(res,g[x][j]); x=f[x][j]; }
  
  if(x==y)  return res;
  
  for(int j=19;j>=0;j--)
   if(f[x][j]!=f[y][j]) {res=max(res,g[x][j]); x=f[x][j];res=max(res,g[y][j]); x=f[y][j];}
  
  return max(res,max(g[x][0],g[y][0])); 
 }
int main()
 {
 freopen("graph.in","r",stdin);
 freopen("graph.out","w",stdout);	
 int Q; scanf("%d%d%d",&n,&m,&Q);
 
 for(int i=1;i<=m;i++) 
  {scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].len); 
   if(q[i].x>q[i].y) swap(q[i].x,q[i].y); 
  }
  
 for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
 
 sort(q+1,q+m+1,cmp2); 
 for(int i=2;i<=m;i++)
    if(q[i].x==q[i-1].x && q[i].y==q[i-1].y) 
     q[i].len=min(q[i].len,q[i-1].len),q[i-1].len=2147483647;
  
 
 sort(q+1,q+m+1,cmp); int lin=0;
 
 for(int i=1;i<=m;i++)
 { int r1=find(q[i].x),r2=find(q[i].y);
   if(r1==r2) continue;
   if(siz[r1]>siz[r2]) swap(r1,r2);
   fa[r1]=r2; siz[r2]+=siz[r1]; 	lin++;
   
   add(q[i].x,q[i].y,q[i].len); add(q[i].y,q[i].x,q[i].len);
   if(lin==n-1) break;
 }

 for(int i=1;i<=n;i++) if(!vis[i]) {deep[i]=1; dfs(i); } 
 
 int x,y;
 while(Q--) 
 { scanf("%d%d",&x,&y);
  if(find(x)!=find(y)) printf("-1\n");
  else                 printf("%d\n",ask(x,y));
 }
  
return 0; 	
 } 
