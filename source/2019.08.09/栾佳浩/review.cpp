#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) (x&(-x))
ll ans;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&ans);
	if(ans==1ll)
	{
		puts("2 1");
		puts("1 2");
		return 0;
	}
	int hig=0;
	for(int i=60;i>=1;i--)
	{
		if(ans&(1ll<<(i-1)))
		{	
			hig=i;
			break;
		}
	}
	printf("%d ",2*hig);
	int n=2*hig;
	ll ans2=ans;
	int cnt=0;
	while(ans2)
	{
		 cnt++;
		 ans2-=lowbit(ans2);
	}
	printf("%d\n",cnt-1+3*(hig-1)+1);
	for(int i=hig-2;i>=0;i--)
	{
		if(ans&(1ll<<i))printf("%d %d\n",i+1,n);
	}
	for(int i=1;i<=hig-2;i++)
	{
	 	printf("%d %d\n",i,i+1);
	}
	for(int i=1;i<=hig-2;i++)
	{
		printf("%d %d\n%d %d\n",i,i+hig-1,i+hig-1,i+1);
	}
	printf("%d %d\n%d %d\n%d %d\n%d %d\n",hig-1,hig-1+hig-1,hig-1,hig-1+hig,hig-1+hig-1,n,hig-1+hig,n);
} 
