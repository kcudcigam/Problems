#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ll y;
	scanf("%lld",&y);
	ll now=1,pw=0,t=0;
	while(y>now)
	{
		if(y&now)t++;
		now*=2;
		pw++;
	}
	if(y&now)
	{
		printf("%lld %lld\n",pw+2,(pw+1)*(pw+2)/2);
		for(int i=1;i<=pw+2;i++)
			for(int j=i+1;j<=pw+2;j++)
				printf("%d %d\n",i,j);
		return 0;
	}
	printf("%lld %lld\n",pw+2,pw*(pw+1)/2+t);
	for(int i=1;i<=pw+1;i++)
		for(int j=i+1;j<=pw+1;j++)
			printf("%d %d\n",i,j);
	for(int i=0;i<=pw;i++)
		if(y&(1ll<<i))printf("%d %d\n",i+2,pw+2);
	return 0;
}
