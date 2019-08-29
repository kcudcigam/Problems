#include<bits/stdc++.h>
using namespace std;
int cnt[10],a[21];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		int tot=0;
		for(int i=1;i<=20;i++)
		{
			if(n!=0)tot++,cnt[n%10]++,a[i]=n%10;
			n/=10;
		}
		int ans=0,ans2=0,flag=1;
		for(int i=3;i<=tot;i++)if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
		for(int i=0;i<=9;i++)
		{
			if(cnt[i])ans++;
			if(cnt[i]>1)ans2=1;
		}
		if(flag)
		{
			int s=0;
			tot--;
			while(tot)tot/=2,s++;
			printf("%d\n",s);
		}
		else
		{
			if(ans2||ans<=2)printf("%d\n",(ans-1)/2+1);
			else printf("%d\n",ans/2);
		}
	}
	return 0;
}
