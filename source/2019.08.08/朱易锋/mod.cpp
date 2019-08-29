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
const int N=1e7+5;
ll f[N];
I V getans(ll n,ll p)
{
	f[1]=0;f[2]=2;
	for(R int i=3;i<=n;i++)
	{
		if(i%2)
		{
			R int a1=(f[i-1]+i-1)%p;
			f[i]=(a1*i)%p;
		}
		else
		{
			f[i]=((f[i-1]*i)%p+((i-1)*(i-1)+1)%p)%p;
		}
	}
	printf("%lld\n",f[n]);
}
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	ll n,p,T;
	read(T);
	while(T--)
	{
		read(n);read(p);
		getans(n,p);
	}
	return 0;
}

