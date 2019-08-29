#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m,i,j,t1,t2,x,y,f[1002][1005],g[1002][1005],a[2005],b[2005],k,z,s,c[2005];
int main(){
  freopen("deal.in","r",stdin);
  freopen("deal.out","w",stdout);
  cin>>n>>m;
  for (i=1;i<=n;i++)
  {
    cin>>c[i]>>a[i]>>b[i];
  }
  f[n+1][0]=1;
  for (i=n;i>=1;i--)
  {
  	for (j=0;j<=2*m;j++)
  	{
  		f[i][j]=(f[i][j]+f[i+1][j])%1000000007;
  	    for (k=1;k<=a[i];k++)
  	    if (j+k*c[i]-m<c[i]) f[i][j+k*c[i]]=(f[i][j+k*c[i]]+f[i+1][j])%1000000007;
	  }
  }
  g[n+1][0]=1;
  for (i=n;i>=1;i--)
  {
  	for (j=0;j<=m-1;j++)
  	{
  		g[i][j]=(g[i][j]+g[i+1][j])%1000000007;
  	    for (k=1;k<=b[i];k++)
  	    if (j+k*c[i]<m) g[i][j+k*c[i]]=(g[i][j+k*c[i]]+g[i+1][j])%1000000007;
	  }
  }
  for (i=m;i<=2*m;i++)
  {
  	ans=(ans+(f[1][i]*g[1][i-m])%1000000007)%1000000007; 
  }
  cout<<ans<<endl;
  return 0;
}


