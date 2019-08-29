#include<bits/stdc++.h>
using namespace std;
int t[10],n,f[300000+5],a[20000+5];
int T;
long long m;
void pre(int p)
{
	int x=p;
	memset(t,0,sizeof(t));
	while(x)
	{
		t[x%10]++;
		x/=10;
	}
	int res=0;
	for(int i=0;i<=9;i++)
		if(t[i])
			res++;
	if(res<=2)
	{
		a[++n]=p;
		f[p]=1;
	}
}
void work()
{
	scanf("%lld",&m);
	if(m<=300000)
	{
		if(f[m]==1)
		{
			printf("1\n");
			return;
		}
		for(int i=1;a[i]<m;i++)
		{
			int pos=lower_bound(a+1,a+n+1,m-a[i])-a;
			if(a[pos]==m-a[i])
			{
				printf("2\n");
				return;
			}
		}
	}
	printf("3\n");
	return;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	f[0]=1;
	for(int i=1;i<=300000;i++)
		pre(i);
	scanf("%d",&T);
	while(T--)
		work();
	return 0;
}
