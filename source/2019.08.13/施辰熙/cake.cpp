#include<bits/stdc++.h>
using namespace std;
long long a,b,ans,f[310][310];
long long dfs(int a,int b)
{
	if (f[a][b])
	return f[a][b];
	for (int i=1;i<a;i++)
	{
		f[a][b]+=dfs(i,b)%1000000007*dfs(a-i,b)%1000000007;
	}
	for (int j=1;j<b;j++)
	{
		f[a][b]+=dfs(a,j)%1000000007*dfs(a,b-j)%1000000007;
	}
	f[a][b]%=1000000007;
	return f[a][b];
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> a >> b;
	ans=0;
	f[1][1]=1;
	cout << dfs(a,b) << endl;
	return 0;
}

