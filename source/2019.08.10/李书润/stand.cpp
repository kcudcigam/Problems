#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll g[6];
struct inter
{
	int l,r;
}s[251];
bool cmp(inter x,inter y)
{
	return x.r<y.r;
}
ll calc(ll x)
{
	return g[1]*x+g[2]*x*x+g[3]*x*x*x+g[4]*x*x*x*x+g[5]*x*x*x*x*x;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m;
	bool flag=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=5;i++)scanf("%lld",&g[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i].l,&s[i].r);
		if(s[i].l!=1||s[i].r!=m)flag=0;
	}
	if(flag)
	{
		printf("%lld",calc(n));
		return 0;
	}
	sort(s+1,s+n+1,cmp);
	
	return 0;
}
