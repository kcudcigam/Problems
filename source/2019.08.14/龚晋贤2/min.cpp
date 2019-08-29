#include<bits/stdc++.h>
using namespace std;
long long n,i,k[5],a[300000],f[300000],g[1005][1005],j;
long long  ks(long long n)
{
	long long s=0;
	s=k[1]*n*n*n+k[2]*n*n+k[3]*n+k[4];
	return s;
}
int main(){
  freopen("min.in","r",stdin);
  freopen("min.out","w",stdout);
  cin>>n;
  for (i=1;i<=4;i++)
  cin>>k[i];
  for (i=1;i<=n;i++)
  cin>>a[i];
  for (i=1;i<=n;i++)
  {
  	g[i][i]=a[i];
  	for (j=i+1;j<=n;j++)
  	g[i][j]=min(g[i][j-1],a[j]);
  }
  f[1]=ks(a[1]);
  for (i=2;i<=n;i++)
  {
  	f[i]=-INT_MAX;
	f[i]*=INT_MAX; 
  	for (j=1;j<=i-1;j++)
  	f[i]=max(f[i],f[j]+ks(g[j+1][i]));
  }
  cout<<f[n]<<endl;
  return 0;
}


