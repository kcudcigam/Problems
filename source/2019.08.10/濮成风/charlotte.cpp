#include<bits/stdc++.h>
using namespace std;
const int maxn=1E5+5;
int T;
int n;
struct node
{
	int t,x,y;
}a[maxn];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y);
	a[0].t=0,a[0].x=0,a[0].y=0;
	for(int i=1;i<=n;++i)
	{
		int t=a[i].t-a[i-1].t;
		int dis=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
		if(t<dis||dis%2!=t%2)
		{
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}

