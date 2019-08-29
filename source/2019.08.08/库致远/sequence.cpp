#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
      for (; isdigit(c);c=getchar()) x=x*10+c-'0';
                         x*=f;
}
int n,m,l,r,s,e;
long long a[500005],kzy;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
  read(n);read(m);
  for (int i=1;i<=m;i++)
  {
  	read(l);read(r);read(s);read(e);
  	long long k=(e-s)/(r-l+1);
  	for (int j=l;j<=r;j++){
  		a[j]=a[j]+s;
  		s=s+k;
	  }
  }
  for (int i=1;i<=n;i++){
  	kzy=a[i]^kzy;
  }
  cout<<kzy<<endl; 
return 0;
}
