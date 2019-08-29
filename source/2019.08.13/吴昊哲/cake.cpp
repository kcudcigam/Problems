#include<bits/stdc++.h>
using namespace std;
int n,m,mod=1000000007;
int cf(int a)
{
	int ans=1;
	for(int i=1;i<=m;i++)
	{
		ans=ans*2;
	}
	return ans;
}
int main()
{
	int ans;
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
	cin>>n>>m;
    if(n==1)cout<<1<<endl;
    if(n==2)ans=cf(m)%mod;
	cout<<ans<<endl;
	return 0;
}


