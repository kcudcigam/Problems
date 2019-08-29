#include<bits/stdc++.h>
using namespace std;

const int maxn=300000+5,INF=0x7fffffff;
int ans[maxn],add[maxn],sum,f,t,res;

struct node
{
	int x,y,w;
	bool vis;
};node mp[maxn];
bool cmp(const node &a,const node &b)
{
	return a.x<b.x;
}

void build(int a,int b,int c)
{
	sum++;
	mp[sum].x=a;
	mp[sum].y=b;
	mp[sum].w=c;
	add[a]++;
}

void dfs(int d,int minx)
{
	if(d==t) res=min(res,minx);
	else for(int i=add[d-1];i<=add[d];i++)
	{
		if(!mp[i].vis)
		{
			mp[i].vis=true;
			dfs(mp[i].y,max(minx,mp[i].w));
			mp[i].vis=false;
		}
	}
	return ;
}

int main()
{
    freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    int n,m,q,a,b,c;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++) 
    {
    	scanf("%d%d%d",&a,&b,&c);
    	build(a,b,c);
    	build(b,a,c);
	}
	sort(mp+1,mp+sum+1,cmp);
	for(int i=1;i<=n;i++) add[i]+=add[i-1];
	while(q--)
	{
		for(int i=1;i<=n;i++) mp[i].vis=false;
		scanf("%d%d",&f,&t);
		res=INF;
		dfs(f,-1);
		if(res==INF) printf("-1\n");
		else printf("%d\n",res);
	}
	return 0;
}
