#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
    R int f=1,num=0;
    R char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
I int dist(R int x1,R int y1,R int x2,R int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	R int T=0;scanf("%d",&T);
	while(T--)
	{
		R int n=0;scanf("%d",&n);
		R int lastx=0,lasty=0,lastt=0;;
		R bool flag=0;
		for(R int i=1;i<=n;i++)
		{
			R int t=0,x=0,y=0;
			scanf("%d%d%d",&t,&x,&y);
			if(flag)continue;
			R int dis=dist(lastx,lasty,x,y);
			R int tim=t-lastt;
			if(tim-dis>=0&&(tim-dis)%2==0)flag=0;
			else
			{
				flag=1;
			}
			lastx=x,lasty=y,lastt=t;
		}
		if(flag)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
