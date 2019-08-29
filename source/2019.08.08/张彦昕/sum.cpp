#include<bits/stdc++.h>
using namespace std;
int a[100010];
int sca[100010]={0};
void sc(int n)
{
	for (int i=1;i<=n;i++)
		sca[i]=sca[i-1]+a[i];
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>a[i]; 
	sc(n);
	long long max;
	int o=0;
	for (int i=1;i<=n-1;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int k=i;k<=j-1;k++)
			{
				for (int l=j;l<=n;l++)
				{
					int v=sca[k]-sca[i-1]+sca[l]-sca[j-1];
					if (o==0) 
					{
						o=1;
						max=v;
					}
					else if (v>max) max=v;
				}
			}
		}
	}
	cout<<max<<endl;
	return 0;
}




