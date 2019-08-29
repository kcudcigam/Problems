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
int n,m;
struct point{int l,r; long long ls,ld,sum;}t[4*N];
void build(int i,int l,int r)
 {t[i].l=l; t[i].r=r;
  if(l==r) return;
  int mid=t[i].l+t[i].r>>1;
  build(2*i,l,mid); build(2*i+1,mid+1,r);
 }
inline void pass(int i,long long s,long long d)
 { t[i].ls+=s; t[i].ld+=d;
   t[i].sum+=(s+(t[i].r-t[i].l)*d+s)*(t[i].r-t[i].l+1)/2;
 } 
inline void pushdown(int i)
 {pass(2*i,t[i].ls,t[i].ld); pass(2*i+1,t[i].ls+(t[2*i].r-t[2*i].l+1)*t[i].ld,t[i].ld);
  t[i].ls=0; t[i].ld=0;
 } 
void add(int i,int l,int r,long long s,long long d)
 {if(l<=t[i].l && t[i].r<=r) {pass(i,s,d); return;}
  
  int mid=t[i].l+t[i].r>>1; pushdown(i);
  if(l<=mid) add(2*i,l,r,s,d);
  if(mid<r)  add(2*i+1,l,r,s,d);
  t[i].sum=t[2*i].sum+t[2*i+1].sum;
 } 
long long ans=0; 
void print(int i)
 {if(t[i].l==t[i].r) {/*printf("%lld ",t[i].sum); */ ans^=t[i].sum; return;}
  pushdown(i);
  print(2*i); print(2*i+1);  
 } 
int main()
 {
 freopen("sequence.in","r",stdin);
 freopen("sequence.out","w",stdout); 	
 read(n); read(m);	int l,r; long long s,e;
 	
 build(1,1,n);	
 while(m--)	
  {read(l); read(r); read(s); read(e); 
  
   long long d; if(l==r) d=0; else d=(e-s)/(r-l);
   add(1,l,r,s,d);
   //print(1); printf("\n");
  }		
 print(1);	printf("%lld",ans);
return 0;	
 }
