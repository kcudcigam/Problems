#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a[1005],x[1005],y[1005],f[1005][1005],j;
int main(){
  freopen("toy.in","r",stdin);
  freopen("toy.out","w",stdout);
  cin>>n>>m;
  for (i=1;i<=n;i++)
  cin>>a[i];
  for (i=1;i<=n;i++)
  {
  x[i]=INT_MAX;
  y[i]=INT_MAX;
  }
  for (i=1;i<=n;i++)
  for (j=1;j<=n;j++)
  f[i][j]=INT_MAX;
  f[1][1]=a[1]; 
  y[0]=0; y[1]=a[1]; x[0]=0;
  for (i=2;i<=n;i++)
  {
  	for (j=1;j<=n;j++)
  	{
  		f[i][j]=min(x[j],x[j-1]+a[i]);
	  }
	for (j=1;j<=n;j++)
	{
	x[j]=min(x[j],y[j]); 
	y[j]=min(y[j],f[i][j]);
    }
  }
  for (i=n;i>=0;i--)
  if (y[i]<=m) {
  cout<<i<<endl;
  break;
   }
  return 0;
}

