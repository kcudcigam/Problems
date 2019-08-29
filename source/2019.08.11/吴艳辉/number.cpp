#include<bits/stdc++.h>
using namespace std;
long long ans,t,n[105],b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n[i]);
	}
	for(i=1;i<=t;i++)
	{
		ans=0;
		for(int j=n[i];j>0;j/=10)
		{
			if(b[j%10]==0)
			{
				ans++;
				b[j%10]=1;
			}
		}
		for(int k=0;k<=9;k++)
		{
			b[k]=0;
		}
		if(ans%2==0)
		{
			printf("%lld\n",ans/2);
		}
		else
		{
			printf("%lld\n",ans/2+1);
		}
	}
	return 0;
}
