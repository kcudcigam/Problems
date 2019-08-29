#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x=x*f;
}
int NUM,n,p;
long long dp(int k)
{
	long long d=2;
	if (k==1) return 0;
	if (k==2) return 2;
	for (int i=2;i<=k-1;i++)
	  if (i%2==0) {
	  	long long q=((d+i)%p)*((i+1)%p);
	  	d=q%p;
	  }
	  else {
	  	long long h=(i-1)%p;
	  	long long q=((d+i)%p)*((i+1)%p);
	  	if (q<h) q=(q+p-h)%p;
	  	else q=q-h;
	  	d=q%p;
	  }
  return d;
}
int main(){
   freopen("mod.in","r",stdin);
   freopen("mod.out","w",stdout);
   read(NUM);
   for (int i=1;i<=NUM;i++)
   {
     read(n);read(p);
     if (p==1) cout<<0<<endl;
     else cout<<dp(n)<<endl;
   }
	return 0;
}

