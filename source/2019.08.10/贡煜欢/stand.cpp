#include<bits/stdc++.h>
using namespace std;
int p[6],l[10000008],r[10000008],g[3005],a[10000008];
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	bool f=0;
   	long long n,m,i,j,ans=0;
   	cin>>n>>m;
	for (i=1;i<=5;i++)
	  cin>>p[i];
   	for (i=1;i<=250;i++)
   	  g[i]=i*p[1]+i*i*p[2]+i*i*i*p[3]+i*i*i*i*p[4]+i*i*i*i*i*p[5];
    for (i=1;i<=n;i++)
    {
	  cin>>l[i]>>r[i];
	  if (l[i]>r[i]) swap(l[i],r[i]);
	}
	for (i=1;i<=n;i++)
	  if (l[i]!=1||r[i]!=m) f=1;
    if (f==0)
	{
		cout<<g[n]<<endl;
		return 0;
	}
	for (i=1;i<=n;i++)
	{
		for (j=l[i];j<=r[i];j++)
		  a[j]++;
	}
	int k=n;
    while (k>0)
    {
    	int j=0,maxi=-1;
    	for (i=1;i<=m;i++)
    	  if (a[i]>maxi) {
    	  	maxi=a[i];
    	  	j=i;
		  }
    	k=k-a[j];
    	ans=ans+g[a[j]];
    	for (i=1;i<=n;i++)
    	  if (l[i]<=j&&r[i]>=j) 
		    for (int o=l[i];o<=r[i];o++)
		      a[o]--;                  
	}
	cout<<ans<<endl;
	return 0;
}
