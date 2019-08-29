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
int hash1[15];
inline int check(long long k)
{
	memset(hash1,0,sizeof(hash1));
	long long l=k;
	int po=0;
	while (l>0)
	{
		long long o=l%10;
		l=l/10;
		if (hash1[o]==0)
		{
			hash1[o]=1;
			po++;
		}
	}
    return po;
}
int f[36000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	int P;
	read(P);
    long long n,m;
    for (int i=1;i<=10000;i++)
      if (check(i)<=2) f[i]=1;
    for (int i=1;i<=10000;i++)
      for (int j=i;j<=10000;j++)
        f[i+j]=min(f[i+j],f[i]+f[j]);
	for (int u=1;u<=P;u++)
    {
      read(n);
      if (n<=3000) cout<<f[n]<<endl;
      else {
      	int k=check(n);
      	if (k%2==0) cout<<k/2<<endl;
      	else cout<<k/2+1<<endl;
	  }
	}
	return 0;
}


