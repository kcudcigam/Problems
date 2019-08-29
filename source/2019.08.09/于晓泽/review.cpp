#include<cstdio>
#include<algorithm>
using namespace std;
long long y; bool a[105];
int main()
 {
 freopen("review.in","r",stdin);
 freopen("review.out","w",stdout);	
 scanf("%lld",&y);	
 long long t=y-1,tot=0,cnt=0;	
 	
 while(t)	{tot++; if(t&1) {a[tot]=1; cnt++;} t>>=1;}
 	
 long long n=tot+2;	
 printf("%lld %lld\n",n,n*(n-1)/2-(n-2)+cnt);
 
 for(int i=1;i<n;i++)
 	for(int j=i+1;j<n;j++)
 	 printf("%d %d\n",i,j);
 
 printf("1 %d\n",n);
 for(int i=2;i<n;i++) if(a[i-1])printf("%d %d\n",i,n);
 	 
return 0;
 }
