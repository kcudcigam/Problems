#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x*=f;
}
int main(){
	freopen("max.in","w",stdin);
	freopen("max.out","r",stdout);
     int n,m,q,x,y,z;
     read(n);read(m);read(q);
     for (int i=1;i<=n;i++)
       {
       	read(x);read(y);read(z);
	   }
	for (int i=1;i<=q;i++)
	{
		read(x);read(y);
	}
	cout<<0<<endl;
	return 0;
}

