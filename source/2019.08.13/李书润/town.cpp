#include<bits/stdc++.h>
using namespace std;
int target[600001],pre[600001],last[600001],tot;
typedef pair<int,int> pii;
void add(int x,int y)
{
	tot++;
	target[tot]=y;
	pre[tot]=last[x];
	last[x]=tot;
}
pii dfs(int x,int f)
{
	int ans=0,ans2=x;
	for(int i=last[x];i;i=pre[i])
	{
		if(target[i]==f)continue;
		pii t=dfs(target[i],x);
		if(t.first+1>ans)ans=t.first+1,ans2=t.second;
	}
	return make_pair(ans,ans2);
}
int getmax(int x)
{
	return dfs(dfs(x,0).second,0).first;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		printf("%d\n",getmax(x));
	}
	return 0;
}
