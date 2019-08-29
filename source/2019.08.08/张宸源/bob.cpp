#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
pair<int,pair<int,pair<int,int> > >t;
map<pair<int,pair<int,pair<int,int> > >,int> m;
int k,tot;
int f[1000000],xun[1000000],sum[20];
int v[5],v1[5];
int w[20];
int Sans;
void dfs(int x)
{
	t=mp(v[1],mp(v[2],mp(v[3],v[4])));
	if(m[t]!=0)
	{
		if(xun[m[t]]==1||m[t]==x)
		xun[x]=1,sum[++Sans]=x;
		return;
	}
	m[t]=x;
	f[x]++;
	int kill=0;
	for(int i=1;i<=4;i++)
	{
		if(v[i]!=0)
		v[i]--;
		if(v[i]!=0)
		{
			for(int j=1;j<=4;j++)
			if(v[j]==0)
			v[j]=w[v[i]];
		}
		else 
		{
			kill=1;
			break;
		}
	}
	if(kill)
	dfs(x);
}
int main(){
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	scanf("%d",&k);
	for(int i=1;i<k;i++)
	scanf("%d",&w[i]);
	for(v1[0]=0;v1[0]<=k;v1[0]++)
	for(v1[1]=0;v1[1]<=k;v1[1]++)
	for(v1[2]=0;v1[2]<=k;v1[2]++)
	for(v1[3]=0;v1[3]<=k;v1[3]++)
	{
		if(v1[0]==1||v1[1]==1||v1[2]==1||v1[3]==1)
		memcpy(v,v1,sizeof(v1)),dfs(++tot);
	}
	int ans=0;
	for(int i=1;i<=Sans;i++)
	ans+=f[sum[i]];
	printf("%d\n",ans);
	return 0;
}

