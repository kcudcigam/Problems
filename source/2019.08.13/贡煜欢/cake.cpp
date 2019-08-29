#include<bits/stdc++.h>
#define mo 1000000007; 
long long f[1005][1005];
using namespace std;
int main()
{ 
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    long long n,m,i,j,k;
    cin>>n>>m;
	f[1][1]=1;
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	  {
	  	   for (k=1;k<i;k++)
	  	   {
	  	     f[i][j]+=f[k][j]*f[i-k][j];
	  	     f[i][j]%=mo;
	  	   }
	  	   	for (k=1;k<j;k++)
	  	   {
	  	     f[i][j]+=f[i][k]*f[i][j-k];
	  	     f[i][j]%=mo;
	  	   }
	      }
	  cout<<f[n][m]<<endl;
	  return 0;
} 
