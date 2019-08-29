#include<bits/stdc++.h>
#define ll long long
#define V void
#define R register
#define I inline
using namespace std;
const ll N=1e8+7;
map<ll,int>num;
map<int,int>sta;int top=0;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ll Y=0;
	scanf("%lld",&Y);
	R int n=1,m=0;
	for(R int i=2;Y!=1;i++)
	{
		while(((ll)Y/i*i==Y)&&Y!=1)
		{
			num[i]++;Y/=i;
			n+=i,m+=(i+1);
			if(num[i]==1)sta[++top]=i;
		}
	}
	printf("%d %d\n",n,m);
	int ans=0;int last_pos=1;
	
	for(R int k=1;k<=top;k++)
	{
		R int i=sta[k];
		while(num[i])
		{
			for(R int j=1;j<=i-1;j++)
			{
				printf("%d %d\n",last_pos,last_pos+j);
				printf("%d %d\n",last_pos+j,last_pos+i);
			}
			printf("%d %d\n",last_pos,last_pos+i);
			last_pos=last_pos+i;
			num[i]--;
		}
	}
	return 0;
}
