#include<bits/stdc++.h>
using namespace std;

int vis[500005],num,n,m;
long long ans;

struct node
{
	int f,t,w;
	bool p;
}; node mp[500005];
bool cmp(const node &a,const node&b)
{
	return a.f<b.f;
}
void put(int a,int b,int c)
{
	num++;
	mp[num].f=a;
	mp[num].t=b;
	mp[num].w=c;
}

void dfs(int dep,long long cost)
{
	if(dep==1&&ans==-1) ans=cost;
	else if(dep==1) ans=min(ans,cost);
	if(ans!=-1&&cost>=ans) return ;
	for(int i=1;i<=num;i++)
	{
		if(mp[i].f==dep&&!mp[i].p&&!vis[mp[i].t])
		{
			vis[mp[i].t]=true;
			dfs(mp[i].t,cost+mp[i].w);
			vis[mp[i].t]=false;
		}
	} 
	return ;
}

int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>num>>n>>m;
	int x,y,z,ok;num=0;
	long long tot;
	for(int i=1;i<=m;i++)
	   cin>>x>>y>>z,put(x,y,z),put(y,x,z);  
	sort(mp+1,mp+num+1,cmp);
	cout<<0<<" ";int flag=1;
	while(mp[flag].f==1) flag++;
	for(int i=2;i<=n;i++)
	{
		vis[i]=true;tot=-1;ok=0;
		while(mp[flag].f==i) 
		{
			ans=-1;
			mp[flag].p=true;
			dfs(i,0);
			if(ans==-1) ok=-1;
			tot=max(tot,ans);
			mp[flag].p=false;
			flag++;
		}
		vis[i]=false;
		if(ok==-1) cout<<ok<<" ";
		else cout<<tot<<" ";
	}
	return 0;
}

