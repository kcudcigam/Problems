#include<bits/stdc++.h>
using namespace std;

int read()
{
	int n=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n*f;
}

long long maxn=1000000007;
long long f[305][305];

long long dfs(int x,int y)
{
//	if (x<=0||y<=0) return 0;
	if (f[x][y]!=0) return f[x][y];
	for (int i=1;i<x;i++)
	{
		f[x][y]=(f[x][y]+dfs(i,y)%maxn*dfs(x-i,y)%maxn)%maxn;
	}
	for (int i=1;i<y;i++)
	{
		f[x][y]=(f[x][y]+dfs(x,i)%maxn*dfs(x,y-i)%maxn)%maxn;
	}
	return f[x][y]%maxn;
}

int main()
{
	freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
	int n,m;
	cin>>n>>m;
	f[1][1]=1;
	cout<<dfs(n,m)<<endl;
	return 0;
}



