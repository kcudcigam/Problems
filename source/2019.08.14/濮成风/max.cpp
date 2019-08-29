#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;
const ll inf=1E9;
ll n,m,q,p[55],ans,minn[55];
int L[55],R[55],X[55],val[55];
vector<int>wait[55];
inline ll max(ll x,ll y)
{
	return x>y?x:y;
}
inline ll min(ll x,ll y)
{
	return x<y?x:y;
}
inline ll qpow(ll x,ll y)
{
	ll ans=1,base=x;
	while(y)
	{
		if(y&1)
			ans=ans*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return ans;
}
inline int ask(int l,int r)
{
	int g=0;
	for(int i=l;i<=r;++i)
		g=max(g,minn[i]);
	return g;
}
inline void check(ll P)
{
	for(int i=1;i<=n;++i)
	{
		if(wait[i].size()==0)
			minn[i]=0;
		else
		{
			minn[i]=inf;
			for(int j=0;j<wait[i].size();++j)
				minn[i]=min(minn[i],wait[i][j]);
		}
	}
	ll sum=0;
	for(int i=1;i<=q;++i)
		sum=(sum+ask(L[i],R[i]))%mod;
	ans=(ans+sum*P)%mod;
}
void dfs(int s,ll P)
{
	if(s==m+1)
	{
		check(P);
		return;
	}
	wait[X[s]].push_back(val[s]);
	dfs(s+1,P*p[s]%mod);
	wait[X[s]].pop_back();
	dfs(s+1,P*(1-p[s]+mod)%mod);
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=m;++i)
		cin>>X[i]>>val[i]>>p[i];
	for(int i=1;i<=q;++i)
		cin>>L[i]>>R[i];
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}

