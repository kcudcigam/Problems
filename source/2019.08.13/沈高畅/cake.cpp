#include<bits/stdc++.h>
#define int long long
using namespace std;
int opt[806][806];
const int Mod=1000000007;
void dfs(int x,int y)
{
	if(opt[x][y]) return;
	int ans=0;
	for(int i=1;i<x;i++)
		{
			int p=x-i;
			dfs(i,y);
			dfs(p,y);
			ans+=opt[i][y]*opt[p][y];
			ans%=Mod;
		}
	for(int i=1;i<y;i++)
		{
			int p=y-i;
			dfs(x,p);
			dfs(x,i);
			ans+=opt[x][p]*opt[x][i];
			ans%=Mod;
		}
	opt[x][y]=ans;
	return;
}
signed main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	opt[1][1]=1;
	int n,m;
	cin>>n>>m;
	dfs(n,m);
	cout<<opt[n][m]<<endl;
	return 0;
}


