#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000+5
int T,n;
struct Node
{
	int t;
	int x;
	int y;
}q[MAXN];
bool check(int x,int y)
{
	int dist=abs(q[x].x-q[y].x)+abs(q[x].y-q[y].y),t=q[x].t-q[y].t;
	if(q[x].x==q[y].x&&q[x].y==q[y].y)
		if(t&1)
			return false;
	if(t<dist)
		return false;
	if(t-dist==1)
		return false;
	return true;
}
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&q[i].t,&q[i].x,&q[i].y);
	for(int i=1;i<=n;i++)
		if(!check(i,i-1))
		{
			printf("No\n");
			return;
		}
	printf("Yes\n");
	return;
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--)
		work();
	return 0;
}
