#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=505;
const int MAXM=10005;

int ans,cnt=1,tail,head[MAXN];
ll y;

struct Edge
{
	int x,y,nex;
}e[MAXM];

void add(int x,int yy)
{
	e[++tail].x=x;e[tail].y=yy;
	e[tail].nex=head[x];head[x]=tail;
}


int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	cin>>y;
	y-=1ll;
	for(int i=2;i<=64;i++)
	{
		if(y==0) {ans=i-1;break;}
		if(y>=(1ll<<(i-2))) //可以包含此点的所有可能 
		{
			y-=(1ll<<(i-2)); //cnt计数 
			for(int j=1;j<i;j++) add(j,i);
		}
		else 
		{
			add(1,i);
			y-=1ll;
			ans=i;int tem=2;
			while(y)
			{
				if(y&1ll) add(tem,i);
				y>>=1ll;
				tem++;
			}
			break;
		}
	}
	ans++;
	for(int i=1;i<ans;i++) add(i,ans);
	printf("%d %d\n",ans,tail);
	for(int i=1;i<=tail;i++)
	{
		printf("%d %d\n",e[i].x,e[i].y);
	}
	
	return 0;
}
