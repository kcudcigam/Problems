#include<bits/stdc++.h>
using namespace std;
int a[100000];
int s[10000][10000];
int n,max1=-999999,max2=-999999,ri=100000,rj=100000;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=j;k<=i;k++)
			{
	       	    s[j][i]+=a[k];
			}
			if(s[j][i]>=max1)
			{
				if(ri<j||rj>i)
				{
					max2=max1;
				}
				max1=s[j][i];
				ri=i;rj=j;
			}	
		}
	}
	cout<<max1+max2<<endl;
	return 0;
}

