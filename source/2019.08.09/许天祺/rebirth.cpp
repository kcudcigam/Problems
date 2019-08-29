#include<bits/stdc++.h>
#define int long long
using namespace std;
int num,n,m;
int dis[1005],vis[1005];
int head[1005],tot;
struct node{
	int to,num,nxt,h;
}edge[2005];
void add(int a,int b,int c){
	edge[++tot].to=b;
	edge[tot].num=c;
	edge[tot].nxt=head[a];
	head[a]=tot;
}
void spfa(int k){
	queue<int> q;
	while(!q.empty()) q.pop();
	for(int i=1;i<=1000;i++)
		dis[i]=INT_MAX;
	q.push(k);
	dis[k]=0;
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		vis[a]=0;
		for(int i=head[a];i;i=edge[i].nxt)
		{
			int x=edge[i].to;
			if (edge[i].h==0&&dis[a]+edge[i].num<dis[x])
			{
				dis[x]=dis[a]+edge[i].num;
				if (vis[x]==0) 
				{
					q.push(x);
					vis[x]=1;
				}
			}
		}
	}
}
signed main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>num>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=head[i];j;j=edge[j].nxt)
		{
			edge[j].h=1;
			spfa(i);
			ans=max(ans,dis[1]);
			edge[j].h=0;
//			cout<<dis[1]<<" ";
		}
		if (ans==INT_MAX) cout<<-1<<" ";
		else cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
} 
/*
1
4 6
1 2 4
2 3 3
1 3 3
1 3 5
4 4 1
1 4 1
*/
