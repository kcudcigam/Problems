#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
struct node{
	long long sum,l;
};
node a[1000055];
int main()
{ 
   freopen("town.in","r",stdin);
   freopen("town.out","w",stdout);
   long  long n,i;
   read(n);
   for (i=1;i<=n;i++)
     a[i].l=1; 
   for (i=1;i<=n;i++)
   {
   	  long long x,y;
   	  read(x);
	  read(y);
	  if (y==x+1) {
	  	 a[y].sum=a[x].sum+1;
	  } 
	  else {
	  	 a[y].sum=max(y-1-x,x-a[y].l)+1;
	  	 a[y].l=x;
	  }
	  cout<<a[y].sum<<endl;
   }
   return 0; 	
} 
