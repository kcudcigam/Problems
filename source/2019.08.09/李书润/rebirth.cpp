#include<bits/stdc++.h>
#pragma gcc optimize(2)
#pragma g++ optimize(2)
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
ll const inf=1e16;
ll f[200001],ans[200001];
int n,m,tot,target[1000001],st[1000001],en[1000001],pre[1000001],last[200001],w[1000001],tms[200001];
bool visited[200001],del[200001],inq[200001];
void add(int x,int y,int z)
{
	++tot;
	target[tot]=y;
	pre[tot]=last[x];
	last[x]=tot;
	w[tot]=z;
}
priority_queue<pli,vector<pli >,greater<pli > >q;
void dij()
{
	for(register int i=2;i<=n;++i)f[i]=inf,visited[i]=0;
	f[1]=0;visited[1]=0;
	q.push(mp(f[1],1));
	while(!q.empty())
	{
		//while(q.size()&&visited[q.top().second])q.pop();
		int now=q.top().second;
		visited[now]=1;
		inq[now]=0;
		q.pop();
		for(register int i=last[now];i;i=pre[i])
		{
			if(del[i]||visited[target[i]])continue;
			int tar=target[i];
			if(f[tar]>f[now]+w[i])
			{
				f[tar]=f[now]+w[i];
				if(!inq[tar])q.push(mp(f[tar],tar));
				inq[tar]=1;
			}
		}
	}
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num;
	scanf("%d",&num);
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(register int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		st[i]=x,en[i]=y;
		add(x,y,z),add(y,x,z);
	}
	for(register int i=1;i<=n;++i)ans[i]=0;
	for(register int i=1;i<=m;++i)
	{
		del[i*2-1]=1,del[i*2]=1;
		dij();
		del[i*2-1]=0,del[i*2]=0;
		ans[st[i]]=max(ans[st[i]],f[st[i]]);
		ans[en[i]]=max(ans[en[i]],f[en[i]]);
	}
	for(register int i=1;i<=n;++i)
		printf("%lld ",ans[i]==inf?(-1):(ans[i]));
	return 0;
}
