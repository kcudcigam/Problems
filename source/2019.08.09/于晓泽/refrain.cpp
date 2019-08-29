#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2*1e5+5; const long long mod=1e9+7;
int n,m1,m2,du[N];

int num,last[N],nxt[2*N],ver[2*N],c[2*N];
inline void add(int x,int y,int z)
 { nxt[++num]=last[x]; last[x]=num; ver[num]=y; c[num]=z; du[x]++;
   nxt[++num]=last[y]; last[y]=num; ver[num]=x; c[num]=z; du[y]++;
 }
int chji[N],chou[3][N],cy[N]; 
bool vis[N];
void dfs(int x,int cnt,int cor)
 {if(vis[x]) return;
  vis[x]=1;
  if(du[x]==1 && cor!=0) {cnt++; 
                          if(cnt&1) chji[cnt]++; 
						  else chou[cor][cnt]++;
						 }
  
  for(int i=last[x];i;i=nxt[i])
   {int y=ver[i];
    if(vis[y]) continue;
    if(cor==0) cor=c[i];
    dfs(y,cnt+1,cor);
   }
 }
void dfs2(int x,int pre,int cnt)
 { if(vis[x]) return;
   vis[x]=1;
   
   for(int i=last[x];i;i=nxt[i])
    {int y=ver[i];
     if(vis[y] && y!=pre && pre && cnt>1) cy[cnt]++;
     if(vis[y]) continue;
     
     dfs2(y,x,cnt+1);
	}
 } 
inline long long ksm(long long a,long long p) 
 { long long re=1;
   while(p)
    {if(p&1) re=re*a%mod;
     a=a*a%mod;
     p>>=1;
	}
   return re;	
 }
long long jc[N];
int main()
 {
 freopen("refrain.in","r",stdin);
 freopen("refrain.out","w",stdout);		
 int sp,x,y; 
 scanf("%d%d%d%d",&sp,&n,&m1,&m2);		
 	
 while(m1--) {scanf("%d%d",&x,&y); add(x,y,1); }	
 while(m2--) {scanf("%d%d",&x,&y); add(x,y,2); }		
 	
 for(int i=1;i<=n;i++) 	
 	 if(du[i]==0)      chji[1]++,vis[i]=1;
	 else if(du[i]==1) dfs(i,0,0);
	 
 for(int i=1;i<=n;i++) 	 
 if(du[i]==2) dfs2(i,0,1);
 jc[0]=1;
 for(long long i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
 long long ans=jc[n],cnt=1;
 for(long long i=1;i<=n;i++) 
 {if(chji[i])    cnt=cnt*jc[chji[i]]   %mod;     
  if(chou[1][i]) cnt=cnt*jc[chou[1][i]]%mod*ksm(2,chou[1][i])%mod;
  if(chou[2][i]) cnt=cnt*jc[chou[2][i]]%mod*ksm(2,chou[2][i])%mod;
  if( cy[i])     cnt=cnt*jc[cy[i]]     %mod*ksm(i,cy[i])   %mod;
 }
 printf("%lld",(ans-cnt+mod)%mod); 
return 0;
 }
