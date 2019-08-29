#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1000000007;

ll dp[305][305];
ll n,m;

ll work(ll x,ll y)
{
	if(dp[x][y]) return dp[x][y];
	for(ll i=1;i<x;i++)
	{
		dp[x][y]=(dp[x][y]+work(i,y)*work(x-i,y))%mod;
	}
	for(ll i=1;i<y;i++)
	{
		dp[x][y]=(dp[x][y]+work(x,i)*work(x,y-i))%mod;
	}
	return dp[x][y];
}

int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	dp[1][1]=1;
	
	cout<<work(n,m)<<endl;
	return 0;
 } 
