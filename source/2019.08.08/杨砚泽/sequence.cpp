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
long long f[500051],t[500051];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    long long n,m,l,r,s,e;
    read(n);read(m);
    memset(f,0,sizeof(f));
    memset(t,0,sizeof(t));
    for (int i=1;i<=m;i++)
      {
      	read(l);read(r);read(s);read(e);
      	long long p=(e-s)/(r-l);
      	f[l]=s;
        t[l]+=p;
        t[r+1]-=p;
     }
    f[1]=f[1]+t[l];    
    long long k=f[1];
    for (int i=2;i<=n;i++)
      {
      	f[i]=f[i]+t[i];
      	k=k^f[i];
	  }
	cout<<k<<endl;
	return 0;
}

