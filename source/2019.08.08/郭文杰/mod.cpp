#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll q,n,p,s[]={0,0,2,12,58,310,1886,13244,106002,954090,9540982,104950912};

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

inline ll fact(ll x)
{
	ll ans=x;
	for(int i=2;i<x;++i)
		x*=i;
	return x;
}

ll comp(int *f,int *r,int n)
{
	ll ans=0;
	for(int i=1;i<=n;++i)
		if(f[i]!=r[i])
			++ans,f[i]=r[i];
	return ans%p;
}

int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	for(int i=1;i<=q;++i)
	{
		ll ans=0;
		read(n),read(p);
		if(n<=11)
			printf("%lld",s[n]%p);
	}
	return 0;
}

