#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct guy
{
	int l,r;
}stand[300];

int n,m,a[10];

inline long long cal(int x)
{
	long long ans=0;
	for (register int i=1;i<=5;++i)
		ans+=a[i]*pow(x,i);
	return ans;
}

int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (register int i=1;i<=5;++i)
		scanf("%d",&a[i]);
    printf("%lld\n",cal(n));
	return 0;
}



