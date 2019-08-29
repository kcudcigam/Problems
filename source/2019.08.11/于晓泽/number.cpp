#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=300000+5;
int a[700005],tot,ans; bool v[300005]; int t;
void pre(int x,int y,int z)
 {
  if(z>N) return;
  if(z!=0)a[++tot]=z;
  
  if(!(x==0 && z==0))pre(x,y,z*10+x);
  pre(x,y,z*10+y);	
 }
void dfs(long long x,int dep)
 { 
   if(v[x]) return;
   v[x]=1;
   if(dep>=ans) return;
   if(a[lower_bound(a+1,a+tot+1,x)-a]==x) {ans=dep; return;}
   
   if(dep>2) return ;
   //printf("%lld\n",x);
   
   for(int i=(lower_bound(a+1,a+tot+1,x)-a-1);i>0;i--)
     dfs(x-a[i],dep+1);
   
 } 
int main()
 {
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);	
 scanf("%d",&t);	
 int n;
 for(int i=0;i<=9;i++)	
  for(int j=i+1;j<=9;j++) pre(i,j,0);
 sort(a+1,a+tot+1); 
  //printf("%lld",tot);
  //for(int i=1;i<=tot;i++) printf("%lld ",a[i]);
 	
 while(t--)
  { scanf("%d",&n); ans=2147483647; memset(v,0,sizeof(v));
    dfs(n,1);
  	printf("%d\n",ans);
  }	
 	
 	
 	
 	
return 0;
 }
