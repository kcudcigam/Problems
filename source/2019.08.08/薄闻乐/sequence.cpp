#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int n,m;
long long ans,l,r,s,t,e,a[100005],f[100005];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	int x;
	if(n*m<=100000000)
	{
	for (int i=1;i<=m;i++)
	{
		read(l);
		read(r);
		read(s);
		read(e);
		x=(e-s)/(r-l);
		f[0]=0;
		f[1]=s;
		for (int j=2;j<=r-l+1;j++)
		f[j]=f[j-1]+x;
		for(int j=1;j<=r-l+1;j++)
		{
			a[j+l-1]+=f[j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		ans=(ans^a[i]);
	}
	cout<<ans;
	return 0;
	}
	for (int i=1;i<=m;i++)
	{
		read(l);
		read(r);
		read(s);
		read(e);
		if(s==e)
		{
			a[l]+=s;
			continue;
		}
		x=(r-s)/(r-l);
		f[0]=0;
		f[1]=s;
		for (int j=2;j<=r-l+1;j++)
		{
			f[j]=f[j-1]+x;
			t=(t^f[j]);
		}
		t=(t^f[1]);
		a[l]+=t;
	}
	for (int i=1;i<=n;i++)
	{
		ans=(ans^a[i]);
	}
	cout<<ans;
	return 0;
}
