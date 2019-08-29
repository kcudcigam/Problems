#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=5E5+5;
int n,m;
ll a[maxn],d[maxn],ans;
inline ll read()
{
	char ch=getchar();
	while(ch<'0'||'9'<ch)
		ch=getchar();
	ll sum=ch-'0';
	ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);
	n=read(),m=read();
	while(m--)
	{
		ll l=read(),r=read(),s=read(),e=read();
		a[l]+=s;
		a[r+1]-=s;
		if(l!=r)
		{
			ll x=(e-s)/(r-l);
			d[l+1]+=x;
			d[r+1]-=x;
			a[r+1]-=(r-l)*x;
		}
	}
	for(int i=1;i<=n;++i)
		a[i]+=a[i-1];
	for(int i=1;i<=n;++i)
		d[i]+=d[i-1];
	for(int i=1;i<=n;++i)
		d[i]+=d[i-1];
	for(int i=1;i<=n;++i)
		a[i]+=d[i];
	for(int i=1;i<=n;++i)
		ans^=a[i];
	cout<<ans<<endl;
	return 0;
}

