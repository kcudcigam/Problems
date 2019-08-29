#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans,Hash[300001],f[300001];
vector <int> a[300001];
int dfs(int wz,int dep)
{
	int t=0;
	Hash[wz]=1;
	for (int i=0;i<a[wz].size();i++)
	{
		if(!Hash[a[wz][i]])
		{
			Hash[a[wz][i]]=1;
			t=dfs(a[wz][i],dep+1);
			Hash[a[wz][i]]=0;
		}
	}
	if(t==0)
	return dep;
	else return t;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	if(n<=2000)
	{	
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			cout<<dfs(x,1)+dfs(y,1)-1<<endl;
			a[x].push_back(y);
			a[y].push_back(x);
			memset(Hash,0,sizeof(Hash));
		}
		return 0;
	}
	else
	{
		f[1]=0;
		f[2]=1;
		f[3]=2;
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			if(y<=3)
			cout<<f[y]<<endl;
			else {
				cout<<f[min(x+1,i)]+1<<endl;
				f[y]=f[min(x+1,i)]+1;
			}
		}
	}
	return 0;
}
