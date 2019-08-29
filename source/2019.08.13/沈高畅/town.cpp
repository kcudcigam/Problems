#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) f=f*10+ch-48,ch=getchar();
	return f;
}
vector<int> vec[3005];
int father[3005];
int mxz[3005];
bool vis[3005];
inline int find_father(int x)
{
	if(father[x]!=x) return father[x]=find_father(father[x]);
	return father[x];
}
inline void unionn(int x,int y)
{
	int r1=find_father(x);
	int r2=find_father(y);
	father[r1]=r2;
}
inline int dfs(int now)
{
	if(vis[now]) return -1;
	vis[now]=1;
	int d=0;
	for(int i=0;i<vec[now].size();i++)
		{
			d=max(d,dfs(vec[now][i])+1); 
		}
	return d;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++) father[i]=i,mxz[i]=0;
	for(int i=1;i<=n-1;i++)
		{
			memset(vis,0,sizeof(vis));
			int a,b;
			a=read();
			b=read();
			int r1=find_father(a);
			int r2=find_father(b);
			int p=max(mxz[r1],mxz[r2]);
			int q=dfs(a)+dfs(b)+1;
			vec[a].push_back(b);
			vec[b].push_back(a);
			cout<<max(p,q)<<endl;
		}
	return 0;
}
/*
5
3 5
3 4
1 2
1 3
*/


