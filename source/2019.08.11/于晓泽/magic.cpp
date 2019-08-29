#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=1e18+5,mod=998244353;
long long n,m,ans; char s[10000+5],t[10];

inline bool check()
 {
  for(int k=1;k<=m;k++)	
   { bool biao=1;
     for(int i=1;i<=k;i++) {if(s[i]!=t[i]) {biao=0;break;}}
	 for(int i=n-(m-k)+1;i<=n;i++) {if(s[k+i-n+(m-k)]!=t[i]) {biao=0;break;}}
	 if(biao==1) return 0;
   }
  return 1; 
 }
void dfs(int x)
 {if(x>n) { if(check()) ans++;
        
		    return;
          }
  for(int i='a';i<='z';i++)
   t[x]=i;        
 }
int main()
 {
 freopen("magic.in","r",stdin);
 freopen("magic.out","w",stdout);		
 scanf("%lld%s",&n,s+1);	
 m=strlen(s+1);	
 dfs(1);
 printf("%lld\n",ans);	
 	
return 0;
 }
