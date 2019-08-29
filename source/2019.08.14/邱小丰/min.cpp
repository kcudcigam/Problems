#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=200050;
int n,a[maxn],A,B,C,D;
ll ans,f[maxn];
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		f[i]=A;
		f[i]=f[i]*a[i]+B;
		f[i]=f[i]*a[i]+C;
		f[i]=f[i]*a[i]+D;
	}
	for(int i=1;i<=n;i++)
		if(f[i]>=0) ans+=f[i];
	cout<<ans<<endl;
	return 0;	
}
