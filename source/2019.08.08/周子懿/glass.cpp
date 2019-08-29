#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+1;
int k,m[N];
ll n,s,len;
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
void init(){read(n);read(k);}
void dfs(int dep,ll t)
{
	s=1;
	if(t==1)
	{
		len=dep;
		m[dep]=0;
		return;
	}else if(t==0)
	{len=dep;return;}
	while(s<=t){s*=2;m[dep]++;}
	m[dep]--;dfs(dep+1,t-s/2);
}
ll km(int r)
{
	if(r==0)return 1;
	ll ans;
	ans=km(r/2);
	if(r&1)ans=ans*ans*2;
	else ans=ans*ans;
	return ans;
}

int main()
{
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	init();
	dfs(1,n);
	if(len<=k)cout<<0<<endl;
	else
	{
		ll sum=0;
		for(int i=1;i<=k;i++)
		{
			sum+=km(m[i]);
		}
		sum+=km(m[k]);
		cout<<sum-n<<endl;
	}
	return 0;
}


