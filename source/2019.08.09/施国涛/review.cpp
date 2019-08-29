#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL cnt,v=2,now=1;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	LL y,tmp,ans=0;
	cin>>y;
	tmp=y;
	while(tmp)
	{
		if(tmp&1)
		{
			cnt+=v;
		}
		tmp>>=1;
		v++;	
	}
	v=2;
	cnt+=2;
	tmp=y;
	while(tmp)
	{
		if(tmp&1)
		{
			for(LL i=now+1;i<=now+v;i++)
			{
				ans+=now+v-i;
			}
			ans+=2;	
			now+=v; 		
		}
		tmp>>=1;
		v++;		
	}
	v=2;
	now=1;
	cout<<cnt<<" "<<ans<<endl;
	while(y)
	{
		if(y&1)
		{
			for(LL i=now+1;i<=now+v;i++)
			{
				for(LL j=i+1;j<=now+v;j++)
				{
					printf("%lld %lld\n",i,j);
				}
			}
			printf("%lld %lld\n",now+v,cnt);
			printf("%d %lld\n",1,now+1);		
			now+=v; 		
		}
		y>>=1;
		v++;		
	}
}


