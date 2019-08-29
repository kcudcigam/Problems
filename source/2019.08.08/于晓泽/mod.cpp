#include<cstdio>
#include<algorithm>
using namespace std;
int n,q; long long p;
template <typename T> void read(T &x)
{int f=1;x=0;char c=getchar();
 for (;!('0'<=c && c<='9');c=getchar()) if (c=='-') f=-f;
 for (; '0'<=c && c<='9';c=getchar()) x=x*10+c-'0';
 x*=f;
}
int main()
 {
 freopen("mod.in","r",stdin);
 freopen("mod.out","w",stdout); 		
 read(q);	
 	
 while(q--)	
  {read(n); read(p); long long f=0;
   if(n==1) {printf("0\n"); continue;}
   
   for(long long i=2;i<=n;i++)
    { f=i*(f+i-1);
     if(!(i&1)) f=f+2-i+p;
     f%=p;
	}
   printf("%lld\n",f);	
  }	
return 0;
 }
