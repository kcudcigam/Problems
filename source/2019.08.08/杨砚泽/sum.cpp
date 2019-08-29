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
int a[100051];
long long s[100051];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    int n;
    read(n);
    s[0]=0;
    for (int i=1;i<=n;i++)
      {
      	read(a[i]);
      	s[i]=s[i-1]+a[i];
	  }
	long long maxn=LONG_LONG_MIN;
	for (int i=1;i<=n;i++)
	  for (int j=i+1;j<=n;j++)
	   {
	   	   for (int k=i+1;k<=j-1;k++)
	   	   {
	   	   	if (s[j]-s[i]-a[k]>maxn) maxn=s[j]-s[i]-a[k];
			  }
	   }
	cout<<maxn<<endl;
	return 0;
}

