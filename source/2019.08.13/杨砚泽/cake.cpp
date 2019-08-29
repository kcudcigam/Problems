#include<bits/stdc++.h>
using namespace std;
const int P=1000000007;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x*=f;
}
int n,m;
long long f[351][351];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	memset(f,0,sizeof(f));
     f[1][1]=1;     
    int n,m;
    read(n);read(m);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
      	for (int k=1;k<i;k++)
      	  {
      	  	f[i][j]=f[i][j]+(f[i-k][j]*f[k][j])%P;
            f[i][j]=f[i][j]%P;
			}
		for (int k=1;k<j;k++)
		  {
		  	f[i][j]=f[i][j]+(f[i][j-k]*f[i][k])%P;
		  	f[i][j]=f[i][j]%P;
		  }
	  }
	cout<<f[n][m]<<endl;
	return 0;
}


