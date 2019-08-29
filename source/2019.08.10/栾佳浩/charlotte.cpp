#include<bits/stdc++.h>
using namespace std;
int t;
int tt[100005];
int x[100005];
int y[100005];
int n;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&tt[i],&x[i],&y[i]);
			int mahatton=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
			if(tt[i]-tt[i-1]<mahatton||((mahatton&1)^((tt[i]-tt[i-1])&1)))flag=0;
		}
		if(flag)puts("Yes");
		else puts("No");
	}
} 
