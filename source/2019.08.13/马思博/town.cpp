#include<bits/stdc++.h>
using namespace std;

int fa[300005],n,ans;
int vis[300005];
int tow[5005][5005];

int find(int x)
{
	if(fa[x]=x) return x;
	else return fa[x]=find(fa[x]);
}
void put(int a,int b)
{
	fa[find(b)]=find(a);
}

void renew(int x,int num)
{
	int m=find(x);
	for(int i=1;i<=n;i++)
	   if(fa[i]==m) 
	{
	   vis[i]=max(vis[i],tow[i][x]+num); 
	   ans=max(vis[i],ans);
	}
}
void reset(int a,int b)
{
	int n=find(a),m=find(b);
	for(int i=1;i<=n;i++)if(fa[i]==n)
	for(int j=1;j<=n;j++)if(fa[j]==m)
	tow[i][j]=tow[j][i]=tow[i][a]+tow[j][b]+1;
}

int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int a,b;cin>>n;n--;
	while(n--)
	{
		cin>>a>>b;ans=0;
		if(!vis[a]&&!vis[b]) 
		{
			put(a,b);
			cout<<1<<endl;
			vis[a]=vis[b]=1;
			tow[a][b]=tow[b][a]=1;
			continue;
		}
		if(vis[a]>0||vis[b]>0)
		{
			renew(a,vis[b]+1);
			renew(b,vis[a]+1);
			reset(a,b);
			put(a,b);
			cout<<ans<<endl;
			continue;
		}	
	}
	return 0;
}
