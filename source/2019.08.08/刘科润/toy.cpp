#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{   int f=1;
  char c=getchar();
  x=0;
  while (!isdigit(c))
  {  if (c=='-') f=-1;
	c=getchar();}
while (isdigit(c))
{ x=(x<<3)+(x<<1)+(c^48);
  c=getchar();}
x*=f;
}
int n,m,ans,f[1005][505][2],a[1005];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	f[1][1][1]=a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i/2;j++)
		{
			f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=f[i-1][j-1][0]+a[i];
		}
	}
	for(int j=0;j<=n;j++)
	{
		if((f[n][j][0]!=0&&f[n][j][0]<=m)||(f[n][j][1]<=m&&f[n][j][1]!=0))
		{
			ans=j;
		}
	}
	cout<<ans<<endl;
	return 0;
}

