#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=200005;
const int maxm=500005;
int edge;
int fst[maxn];
int nxt[maxm<<1];
int v[maxm<<1];
int k[maxm<<1];
typedef long long ll;
void add(int x,int y,int val)
{
	edge++;
	nxt[edge]=fst[x];
	fst[x]=edge;
	v[edge]=y;
	k[edge]=val;
}
ll dis1[maxn];
ll dis2[maxn];
ll inf;
struct node
{
	ll dis;
	int num;
	bool operator <(const node &b)const
	{
		return dis>b.dis;
	}
};
priority_queue<node> q;
int num;
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%d",&num);
	memset(dis1,0x3f,sizeof dis1);
	memset(dis2,0x3f,sizeof dis2);
	inf=dis1[0];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		add(x,y,val);
		add(y,x,val);
	}
	dis1[1]=dis2[1]=0;
	node beg;
	beg.num=1;
	beg.dis=0;
	q.push(beg);
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(dis2[now.num]<now.dis)continue;
		for(int i=fst[now.num];i;i=nxt[i])
		{
			ll new_dis=1ll*k[i]+now.dis;
			if(dis1[v[i]]>new_dis)
			{
				swap(dis1[v[i]],new_dis);
				node rnow;
				rnow.num=v[i];
				rnow.dis=dis1[v[i]];
				q.push(rnow);
			}
			if(dis2[v[i]]>new_dis)
			{
				swap(dis2[v[i]],new_dis);
				node rnow;
				rnow.num=v[i];
				rnow.dis=dis2[v[i]];
				q.push(rnow);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis2[i]==inf)printf("-1 ");
		else printf("%lld ",dis2[i]);
	}
}
