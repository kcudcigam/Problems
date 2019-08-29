#include<bits/stdc++.h>
using namespace std;
struct node
{
	int p,v;
};
int i,n,m,j,a,b,k,Max1,Max2,x,ans;
vector <int> u[300010];
int h[300010];
int vis[300010];
int Max[1000];
queue <node> q;
node l,t;
bool f;
int Query(int dep)
{
	vis[dep]=1;Max1=0;
	for (int i=0;i<u[dep].size();i++)
	{
		if (vis[u[dep][i]]==0)
		{
			k=Query(u[dep][i])+1;
			Max1=max(Max1,k);
		}
	}
	return Max1;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i=1;i<n;i++)
	{
		cin >> a >> b;
		u[a].push_back(b);u[b].push_back(a);
		memset(vis,0,sizeof(vis));
		vis[a]=1;Max1=0;Max2=0;Max[0]=0;Max[1]=0;Max[2]=0;
		for (int i=0;i<u[a].size();i++)
		{
			k=Query(u[a][i])+1;
//			Max[0]++;Max[Max[0]]=k;
//			cout << u[a][i] << ' ' << k << endl;
			Max[3]=k;
			sort(Max+1,Max+4);
			Max[1]=Max[3];
		}
//		sort(Max+1,Max+Max[0]+1);
//		if (Max[0]==1)
//		cout << Max[Max[0]] << endl;
//		else
//		cout << Max[Max[0]]+Max[Max[0]-1] << endl;
		cout << Max[1]+Max[2] << endl;
	}
	return 0;
}

