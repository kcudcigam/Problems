#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=500005;
ll n,m,minu[MAXN],diff[MAXN];
//diff 一级差分
//minu 二级差分 

template <typename T> void read(T &x)
{
ll f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);ll l,r,s,e;
	for(ll i=1;i<=m;i++)
	{
		read(l);read(r);read(s);read(e);
		if(l==r)
		{
			diff[l]+=s;
			diff[l+1]-=s;
			continue;
		}
		ll a=(e-s)/(r-l);
		diff[l]+=s;
		diff[r+1]-=e;
		minu[l+1]+=a;
		minu[r+1]-=a;
	}
//	cout<<diff[1]<<" ";
	ll tem=diff[1],ttem=0,ans=diff[1];
	for(ll i=2;i<=n;i++)
	{
		ttem+=minu[i];
		tem+=ttem+diff[i];
	//	cout<<tem<<" ";
		ans^=tem;
	}
	cout<<ans<<endl;
	return 0;
 } 
