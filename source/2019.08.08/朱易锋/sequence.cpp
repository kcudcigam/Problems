#include<bits/stdc++.h>
#define I inline
#define R register
#define V void
#define ll long long
using namespace std;
template <typename T> void read(T &x)
{
	ll f=1;x=0;R char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=500000+7;
ll a[N],d1[N],d2[N],n;
I V addv(R ll l,R ll r,R ll a1,R ll d)
{
	d2[l]+=a1;
	d2[l+1]=d2[l+1]-a1+d;
	d2[r+1]=d2[r+1]-a1-(r-l+1)*d;
	d2[r+2]=d2[r+2]+(a1+(r-l)*d);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	R ll n=0,m=0;
	read(n);read(m);
	for(R ll i=1;i<=m;i++)
	{
		R ll l=0,r=0,a1=0,d=0;
		read(l);read(r);read(a1);read(d);
		d=(d-a1)/(r-l);
		addv(l,r,a1,d);
	}
	for(R ll i=1;i<=n;i++)d1[i]=d1[i-1]+d2[i];
	for(R ll i=1;i<=n;i++)a[i]=a[i-1]+d1[i];
	R ll ans=0;
	for(R int i=1;i<=n;i++)ans^=a[i];
	printf("%lld\n",ans);
	return 0;
}
