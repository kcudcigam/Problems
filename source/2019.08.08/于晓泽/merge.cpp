#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500000+5;
template <typename T> void read(T &x)
{int f=1;x=0;char c=getchar();
 for (;!('0'<=c && c<='9');c=getchar()) if (c=='-') f=-f;
 for (; '0'<=c && c<='9';c=getchar()) x=x*10+c-'0';
 x*=f;
}
int n,q,f[N],siz[N],v[N],ans[N];
int find(int x) {if(x==f[x]) return x; return find(f[x]); }

int num,last[N],nxt[N],ver[N];
inline void add(int x,int y) {nxt[++num]=last[x]; last[x]=num; ver[num]=y;}

bool vis[N];
void dfs(int x,int val)
 {if(vis[x]) return ;
 
  vis[x]=1; ans[x]=val+v[x];
  
  for(int i=last[x];i;i=nxt[i]) dfs(ver[i],ans[x]);
 }
 
int main()
 {
 freopen("merge.in","r",stdin);
 freopen("merge.out","w",stdout); 	
 read(n); read(q);	int op,x,y;
 for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
 	
 while(q--)	
  {read(op); read(x); read(y);
   if(op==1)  { int r1=find(x),r2=find(y);
                if(r1==r2) continue;
                if(siz[r1]>siz[r2]) swap(r1,r2);
                
                f[r1]=r2; siz[r2]+=siz[r1]; v[r1]-=v[r2]; add(r2,r1);
              }
   else if(op==2)
              {int r=find(x); 
               v[r]+=y;
			  }          
  }	
 	
 for(int i=1;i<=n;i++) {dfs(find(i),0);	}
 for(int i=1;i<=n;i++) printf("%d ",ans[i]);	
return 0;
 }
