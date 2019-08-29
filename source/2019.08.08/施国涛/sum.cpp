#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int x[100001],from[100001];
long long maxs=-0x7f7f7f7f;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x[i]);
		from[i]=from[i-1]+x[i];	
	}	
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			for(int k=j+1;k<=n;++k)
			{
				for(int l=k;l<=n;++l)
				{
					maxs=max(maxs,(from[j]-from[i-1]+from[l]-from[k-1]));
				}
			}
		}
	}
	cout<<maxs;
}


