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
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
    int n,m;
    read(n);read(m);
	if (n==0||m==0)cout<<"infinity"<<endl;
	else if (n==m) cout<<1<<endl;
	else cout<<"infinity"<<endl;
	return 0;
}


