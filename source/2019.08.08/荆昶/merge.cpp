#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,m;
int s[500001],ft[500001];
int fd(int x)
{
	if(x==ft[x]) return x;
	ft[x]=fd(ft[x]);
	return ft[x];
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++) ft[i]=i;
	while(m--)
	{
		int o,a,b;
		read(o);read(a);read(b);
		if(o==1)
		{
			ft[b]=fd(a);
		}
		else
		{
			int x=fd(a);
			for(int i=1;i<=n;i++)
			if(fd(i)==x) s[i]+=b;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",s[i]);
	return 0;
}

