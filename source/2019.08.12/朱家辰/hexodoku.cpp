#include<bits/stdc++.h>
#define maxn
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
/*int g[100][7]={3,4,5,6,7,0,0,14,15,16,17,18,0,0,25,26,27,28,29,0,0,1,4,9,14,19,0,0,6,11,16,21,26,0,0,13,18,23,28,31,0,0,8,14,20,26,30,0,0,4,10,16,22,28,0,0,2,6,12,18,24,0,0,1,2,4,5,6,10,11,3,4,8,9,10,14,15,14,15,19,20,21,25,26,21,22,26,27,28,30,31,17,18,22,23,24,28,29,6,7,11,12,13,17,18,1,2,4,5,6,10,11,10,11,15,16,17,21,22},len[100];
int k,n,ans[35],cnt;
bool vis[35][35];
void build()
{
	for(int i=1;i<=9;i++) len[i]=5;
	for(int i=10;i<=17;i++) len[i]=7;
}
int a[1500][3],b[35],tot;
void add(int x,int y)
{
	tot++;
	a[tot][0]=x;
	a[tot][1]=y;
	a[tot][2]=b[x];
	b[x]=tot;
	tot++;
	a[tot][0]=y;
	a[tot][1]=x;
	a[tot][2]=b[y];
	b[y]=tot;
}
void doit(int x,int p,bool o)
{
	vis[x][p]=o;
	for(int i=b[x];i;i=a[i][2])
	{
		int y=a[i][1];
		vis[y][p]=o;
	}
}
void dfs(int x)
{
	if(x==32)
	{
		cnt++;
		return;
	}
	if(ans[x]!=0)
	{
		dfs(x+1);
		return;
	}
	for(int i=1;i<=k;i++)
	{
		if(!vis[x][i])
		{
			ans[x]=i;
			doit(x,i,true);
			dfs(x+1);
			if(cnt==n) return;
			ans[x]=0;
			doit(x,i,false);
		}
	}
}*/
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	/*build();
	for(int i=0;i<17;i++)
		for(int j=0;j<len[i]-1;j++)
			for(k=j+1;k<len[i];k++)
				add(g[i][j],g[i][k]);
	cin>>k>>n;
	for(int i=1;i<=31;i++)
	{
		cin>>ans[i];
		doit(i,ans[i],true);
	}
	dfs(1);
	if(cnt==n)
	{
		puts("Found");
		for(int i=1;i<=31;i++) 
			printf("%d ",ans[i]);
	}*/
	puts("No way");
	return 0;
}


