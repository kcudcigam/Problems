#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100005;
long long a[maxn];
long long f1[maxn];
long long f2[maxn];
long long maxx1[maxn];
long long maxx2[maxn];
long long maxx;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout); 
	maxx=-2000000000000000ll;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	maxx1[0]=maxx;
	maxx2[n+1]=maxx;
	for(int i=1;i<=n;i++)
	{
		f1[i]=max(f1[i-1]+a[i],a[i]);
		maxx1[i]=max(maxx1[i-1],f1[i]);
	}
	for(int i=n;i>=1;i--)
	{
		f2[i]=max(f2[i+1]+a[i],a[i]);
		maxx2[i]=max(maxx2[i+1],f2[i]);
	}
	for(int i=2;i<=n;i++)
	{
		maxx=max(maxx,maxx1[i-1]+maxx2[i]);
	//	cout<<maxx1[i-1]<<" "<<maxx2[i]<<endl;
	}
	printf("%lld",maxx);
}
