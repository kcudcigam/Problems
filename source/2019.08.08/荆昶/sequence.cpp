#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,m,a[500001];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		int l,r,s,e,ad;
		read(l);
		read(r);
		read(s);
		read(e);
		ad=(e-s)/(r-l);
		int h=s;
		for(int j=l;j<=r;j++)
		{
			a[j]+=h;
			h+=ad;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans^=a[i];
	cout<<ans;
	return 0;
}

