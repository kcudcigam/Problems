#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int nowx=0,nowy=0,nowt=0,x,y,t;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&t,&x,&y);
			int len=abs(x-nowx)+abs(y-nowy);
			if(t-nowt<len)flag=0;
			if((t-nowt>len)&&((t-nowt-len)&1))flag=0;
			nowx=x,nowy=y,nowt=t;
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
