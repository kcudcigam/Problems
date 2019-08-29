#include <bits/stdc++.h>

using namespace std;

int n,m,l[500005],r[500005],s[500005],e[500005];
long long a[500005];
bool f;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;++i)
	{
		read(l[i]),read(r[i]),read(s[i]),read(e[i]);
		if(s[i]!=e[i])
			f=1;
	}
	if(f)
		for(int i=1;i<=m;++i)
		{
			int ad=(e[i]-s[i])/(r[i]-l[i]);
			for(;l[i]<=r[i];++l[i],s[i]+=ad)
				a[l[i]]+=s[i];
			for(int j=2;j<=n;++j)
				a[1]^=a[j];
		}
	else
	{
		long long sum;
		for(int i=1;i<=m;++i)
			a[l[i]]+=s[i],a[r[i]+1]-=e[i];
		sum=a[1];
		for(int i=2;i<=n;++i)
			sum+=a[i],a[1]^=sum;
	}
	printf("%lld",a[1]);
	return 0;
}
