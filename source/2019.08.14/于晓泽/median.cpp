#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000+5;
inline int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int n,m,a[N],b[N],t[2*N];
int main()
 {		
 freopen("median.in","r",stdin);
 freopen("median.out","w",stdout);	
 scanf("%d%d",&n,&m);	

 for(int i=1;i<=n;i++) scanf("%d",&a[i]);
 for(int i=1;i<=n;i++) scanf("%d",&b[i]);

 int op,x,y,z,l1,r1,l2,r2;
 while(m--)
  {scanf("%d",&op);
   if(op==1) {scanf("%d%d%d",&x,&y,&z); if(x==0) a[y]=z; else if(x==1) b[y]=z;}
   else      {scanf("%d%d%d%d",&l1,&r1,&l2,&r2); 
               int len=(r1-l1+1+r2-l2+1)/2+1; int tot=0;
              for(int i=l1;i<=r1;i++) t[++tot]=a[i];
              for(int i=l2;i<=r2;i++) t[++tot]=b[i];
              sort(t+1,t+tot+1);
              printf("%d\n",t[len]);
             }
  }
return 0; 	
 }  
