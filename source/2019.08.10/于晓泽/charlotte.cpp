#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=1e5+15;
int n;
struct point{int x,y,t;}a[N];
inline bool hehe()
 {
  for(int i=1;i<=n;i++)	
   if( (  ((a[i].t-a[i-1].t)&1 ) ^ 
          ( (abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)) &1) 
	   )
	 ) return 0;
   else if((abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y))>(a[i].t-a[i-1].t)) return 0;
  return 1; 
 }
int main()
 {
 freopen("charlotte.in","r",stdin);
 freopen("charlotte.out","w",stdout);	
 int T; scanf("%d",&T);	a[0].x=a[0].y=a[0].t=0;
 	
 while(T--)	
  { scanf("%d",&n); 
   for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y);
   
   if(hehe()) printf("Yes\n");
   else       printf("No\n"); 
  }		
 	
return 0; 	
 } 
