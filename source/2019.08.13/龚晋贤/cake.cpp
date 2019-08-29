#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,a[500][500];
int main(){
  freopen("cake.in","r",stdin);
  freopen("cake.out","w",stdout);
  cin>>n>>m;
  a[1][1]=1;
  for (i=2;i<=m;i++)
  {
  	a[1][i]=0;
    for(j=1;j<=i-1;j++)
	a[1][i]=(a[1][i]+(a[1][j]*a[1][i-j])%1000000007)%1000000007;	
  } 
  for (i=2;i<=n;i++)
  {
  	a[i][1]=0;
  	for (j=1;j<=i-1;j++)
  	a[i][1]=(a[i][1]+(a[j][1]*a[i-j][1])%1000000007)%1000000007;
  	for (j=2;j<=m;j++)
  	{
  		for (k=1;k<=i-1;k++)
  		a[i][j]=(a[i][j]+(a[k][j]*a[i-k][j])%1000000007)%1000000007;
  		for (k=1;k<=j-1;k++)
  		a[i][j]=(a[i][j]+(a[i][k]*a[i][j-k])%1000000007)%1000000007;
	  }
  }
  cout<<a[n][m]<<endl;
  return 0;
}


