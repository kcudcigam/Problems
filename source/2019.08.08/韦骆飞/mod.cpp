#include <bits/stdc++.h>
using namespace std;
long long q[10000005],n,a,b,f[10000005];
int main ()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>n;
	for (int j=1;j<=10000000;j++) 
	  if (j%2==1)
	  q[j]=(long long)j*(j-1);
	  else q[j]=(long long)q[j-1]+j;
	for (int i=1;i<=n;i++) 
	  {
	  	cin>>a>>b;
	  	f[1]=0;
	  	if (a==1)
	  	{cout<<0<<endl;continue;}
	  	for (int j=2;j<=a;j++)
	  	{
	  		f[j]=((f[j-1]*j)%b+q[j]%b)%b;
		  }
		cout<<f[a]<<endl;
	  }
    return 0;
}

