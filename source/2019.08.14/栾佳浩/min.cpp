#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long f[maxn];
int n,a,b,c,d;
int aa[maxn];
int main()
{
	freopen("min.in","r",stdin); 
	freopen("min.out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&aa[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int minn=aa[i];
		f[i]=f[i-1]+1ll*minn*minn*minn*a+1ll*b*minn*minn+1ll*c*minn+d;
		//cout<<minn<<endl;
		for(int j=i-1;j>=0;j--)
		{
			f[i]=max(f[i],f[j]+1ll*minn*minn*minn*a+1ll*b*minn*minn+1ll*c*minn+d);
			minn=min(minn,aa[j]);
		}
	}
	cout<<f[n];
}
