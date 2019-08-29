#include<bits/stdc++.h>
using namespace std;
int n,m,h[500005],ans[500005];
int head[500005],tot;
struct node{
	int to,nxt;
}edge[500005];
void add(int x,int y){
	edge[++tot].to=y;
	edge[tot].nxt=head[x];
	head[x]=tot;
}
void dfs(int x,int y){
	if (h[x]==1) return;
	h[x]=1;
	ans[x]+=y;
	for(int i=head[x];i;i=edge[i].nxt)
		dfs(edge[i].to,y);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		cin>>opt>>x>>y;
		if (opt==1)
		{
			add(x,y);
			add(y,x);
		}
		if (opt==2)
		{
			memset(h,0,sizeof(h));
			dfs(x,y);
		}
	}
	for(int i=1;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<ans[n]<<endl;
	return 0;
}

