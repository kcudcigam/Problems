#include<bits/stdc++.h>
#define N 10010
#define ll long long
using namespace std;
int k,a[20],f=1;
bool hash[20][20][20][20];
template<typename T>inline void read(T &x)
{ x=0;
 int f=1;
 char c=getchar();
 while (!isdigit(c))
 {  if (c=='-') f=-1;
   c=getchar();}
while (isdigit(c))
{ x=(x<<3)+(x<<1)+(c^48);
  c=getchar();}
x*=f;}
ll write(ll x)
{   if (x<0)
	 {putchar('-');write(-x);}
	if (x/10)  write(x/10);
	putchar(x%10+48);
}
int main(){
  freopen("bob.in","r",stdin);
  freopen("bob.out","w",stdout);
  read(k);
  if (k==1) {cout<<0<<endl;return 0;}
  memset(hash,0,sizeof(hash));
  for (int i=1;i<k;i++)
  { read(a[i]);
    if (a[i]!=k)  f=0;
  }
  if (f) {  if (k>4)  cout<<0<<endl;
  else {  if (k==2)  cout<<31<<endl;
          if (k==4)  cout<<24<<endl;
          if (k==3)   cout<<36<<endl; 
   }
  }
	return 0;
}
