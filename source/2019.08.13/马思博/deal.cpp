#include<bits/stdc++.h>
using namespace std;

int a[10000][5];
int f[1005][20005];
int g[10005];
const int mo=1e9+7;

int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
       cin>>a[i][1]>>a[i][2]>>a[i][3];
    for(int i=n;i>=1;i--)
       for(int j=1;j<=a[i][2];j++)
	      f[i][j*a[i][1]]++; 
    for(int i=n-1;i>=1;i--)
      for(int j=1;j<=a[i][2];j++)
    	for(int k=1;k<x;k++)
    	   for(int l=1;l<=n-i;l++)
    	   if(f[i+l][k]!=0&&(j*a[i][1]+k)<x+a[i][1])
		     f[i][j*a[i][1]+k]+=f[i+l][k];	   
    for(int j=1;j<=a[1][3];j++)
	      g[j*a[1][1]]++; 
	g[0]=1;
	for(int i=2;i<=n;i++)
       for(int j=1;j<=a[i][3];j++)
    {
    	for(int k=0;k<2*x;k++)
    	   if(g[k]!=0)
		     g[j*a[i][1]+k]+=g[k];	   
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=x;j<x+a[i][1];j++)
//		   cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
//    for(int i=1;i<=x;i++) cout<<g[i]<<" ";
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=x;j<x+a[i][1];j++)
		   cnt+=f[i][j]*g[j-x];
		ans=(ans+cnt)%mo;
    }
    cout<<ans;
	return 0;
}
