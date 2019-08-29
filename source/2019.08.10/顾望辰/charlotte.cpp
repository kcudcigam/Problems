#include<cstdio>
#include<cmath>
int T,n,dis,rmt;
bool spiderPoker;
struct redAlert
{
	int t,x,y;
}now,p;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		now=(redAlert){0,0,0};
		spiderPoker=true;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p.t,&p.x,&p.y);
			dis=abs(p.x-now.x)+abs(p.y-now.y);
			rmt=p.t-now.t;
			if(rmt<dis||(rmt&1)!=(dis&1))
			{
				spiderPoker=false;
				break;
			}
		}
		if(spiderPoker) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
