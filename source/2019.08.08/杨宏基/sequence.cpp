#include<cstdio>
#include<iostream>
using namespace std;
long long a[1000010];
int n,m;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	if(!(n<=2000&&m<=2000))
	{
		while(m--)
		{
			long long l,r,s,e;
			cin>>l>>r>>s>>e;
			for(int i=l;i<=r;i++)
				a[i]+=(s+(e-s)/(r-l)*(i-l));
		}
		long long s=a[1];
		for(int i=2;i<=n;i++)
			s^=a[i];
		cout<<s;
	}
	else
	{
		while(m--)
		{
			long long l,r,s,e;
			cin>>l>>r>>s>>e;
			a[l]+=s;
			a[l+1]-=s;
			if(r!=l)
			{
				a[l+1]+=(e-s)/(r-l);
				a[r+1]-=(e-s)/(r-l);
			}
			if(s==e)
				a[r+1]-=s;
		}
		for(int i=1;i<=n;i++)
			a[i]+=a[i-1];
		for(int i=1;i<=n;i++)
			a[i]+=a[i-1];
		long long s=a[1];
		for(int i=2;i<=n;i++)
			s^=a[i];
		cout<<s;
	}
}
