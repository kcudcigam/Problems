#include<bits/stdc++.h>
using namespace std;
long long n,a[5];
long long b[200005];
long long ans,mi=0xffffffff;
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n;
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(a[1]>=0&&a[2]>=0&&a[3]>=0&&a[4]>=0)
	{
		for(int i=1;i<=n;i++)
		{
			ans+=((a[1]*b[i]+a[2])*b[i]+a[3])*b[i]+a[4];
		}
	}
	if(a[1]==0&&a[2]==0&&a[3]<0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[3]*b[i]+a[4]<0)
			{
				mi=b[i];
				for(int j=i+1;j<=n;j++)
				{
					if(a[3]*b[j]+a[4]<=0)
					{
						mi=min(mi,b[j]);
						i++;
						if(j==n){
							ans+=mi*a[3]+a[4];
							mi=0xffffffff;
						}
					}
					else {
						ans+=mi*a[3]+a[4];
						mi=0xffffffff;
						break;
					}
				}
			}
			else{
				ans+=a[3]*b[i]+a[4];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
