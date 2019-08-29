#include<bits/stdc++.h>
using namespace std;
long long n,t,k,v;
bool check(long long x)
{
	int Hash[11],ans=0,g;
	memset(Hash,0,sizeof(Hash));
	while(x!=0)
	{
		if(Hash[x%10]==0)
		ans++;
		Hash[x%10]=1;
		x/=10;
		if(ans>2)
		return 0;
	}
	return 1;
}
long long work(long long dep)
{
	for (int i=1;i<=dep/2;i++)
	{
		if(check(i))
		if(check(dep-i))
		return 2;
	}
	return 3;
}
long long pf(int x)
{
	int Hash[11],ans=0,g;
	memset(Hash,0,sizeof(Hash));
	while(x!=0)
	{
		if(Hash[x%10]==0)
		ans++;
		Hash[x%10]=1;
		x/=10;
	}
	return ans;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&t);
	for (int l=1;l<=t;l++)
	{
		scanf("%d",&n);
		v=check(n);
		if(v)
		{
			cout<<1<<endl;
			continue;
		}
		if(n<=300000)
		{
			cout<<work(n)<<endl;
		}
		else 
		{
			cout<<int(sqrt(2*pf(n)))<<endl;
		}
	}
	return 0;
}
