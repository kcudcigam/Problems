#include<bits/stdc++.h>
using namespace std;
template <typename T> void R(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int a[10001];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,l,r,s,e;
	R(n);R(m);
	for(int i=1;i<=m;i++)
	{
		R(l);R(r);R(s);R(e);
		int S=s,T=(e-s)/(r-l);
		for(int j=l;j<=r;j++)
		{
			a[j]+=S;
			S+=T;
		}
	}
	int ans=a[1];
	for(int i=2;i<=n;i++)
	{
		ans=ans^a[i];
	}
	cout<<ans<<endl;
	return 0;
}

