#include<bits/stdc++.h>
using namespace std;
int n,m;
int cm(int dep,int x)
{
	if(dep==0)
	return x%1000000007;
	else return cm(dep-1,x*2%1000000007);
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	if(n==1||m==1)
	{
		if(n+m==2)
		cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	if(n==2)
	{
		cout<<cm(m,1)<<endl;
		return 0;
	}
	return 0;
}
