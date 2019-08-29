#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300000+15;
struct edge{int x,y;}a[N];
struct hehe{int x,y,d;}b[N];
int n;

int num,last[N],nxt[2*N],ver[2*N];
inline void add(int x,int y) 
 {nxt[++num]=last[x]; last[x]=num; ver[num]=y;
  nxt[++num]=last[y]; last[y]=num; ver[num]=x;
 }

int deep[N],f[N][23];
void dfs(int x)
 {
  for(int j=1;j<=21 && (1<<j)<deep[x];j++)
   f[x][j]=f[f[x][j-1]][j-1];
   
  for(int i=last[x];i;i=nxt[i])
   { int y=ver[i];
    if(y==f[x][0]) continue;
    f[y][0]=x; deep[y]=deep[x]+1;
    dfs(y);
   } 	
 } 

inline int lca(int x,int y)
 { if(deep[x]<deep[y]) swap(x,y);
 
   for(int j=21;j>=0;j--)
    if(deep[f[x][j]]>=deep[y]) x=f[x][j];
   
   if(x==y) return x;
   
   for(int j=21;j>=0;j--)
    if(f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];

   return f[x][0];	 
 } 
inline int dis(int x,int y)
 { int t=lca(x,y);
   return deep[x]+deep[y]-2*deep[t];
 } 
int fa[N]; 
int find(int x){if(x==fa[x]) return x; return fa[x]=find(fa[x]);}
int main()
 {
 freopen("town.in","r",stdin);
 freopen("town.out","w",stdout);	
 scanf("%d",&n);	
 for(int i=1;i<n;i++) {scanf("%d%d",&a[i].x,&a[i].y); add(a[i].x,a[i].y);}
 for(int i=1;i<=n;i++)	{fa[i]=i; b[i].x=i; b[i].y=i; b[i].d=0;}
 deep[1]=1; dfs(1);	
 	
 for(int i=1;i<n;i++)	
  {int x=a[i].x,y=a[i].y;
   if(f[x][0]!=y)	 swap(x,y);
   x=find(x); y=find(y);
   
   int x1=b[x].x,x2=b[y].x,y1=b[x].y,y2=b[y].y;
   
   int xx=x1,yy=y1,cmp=b[x].d;
   
   if(b[y].d>cmp) xx=x2,yy=y2,cmp=b[y].d;
   if(dis(x1,x2)>cmp) xx=x1,yy=x2,cmp=dis(x1,x2);
   if(dis(x1,y2)>cmp) xx=x1,yy=y2,cmp=dis(x1,y2);
   if(dis(x2,y1)>cmp) xx=x2,yy=y1,cmp=dis(x2,y1);
   if(dis(y1,y2)>cmp) xx=y1,yy=y2,cmp=dis(y1,y2);
   
   b[y].x=xx,b[y].y=yy,b[y].d=cmp; 
   fa[x]=find(y);
   printf("%d\n",cmp);
  }		
return 0;
 }
