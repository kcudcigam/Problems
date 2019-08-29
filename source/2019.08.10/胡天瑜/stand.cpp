#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=255;

long long n;
int m;
long long g[6];
int l[MAXN],r[MAXN],exist[MAXN];
long long ans=0;
struct Stander
{
	long long val;
	int pos;
}standnum[MAXN];

long long maxx(long long a,long long b)
{
	if(a>b) return a;
	else return b;
}

bool cmp(Stander a,Stander b) {return a.val>b.val;}

long long calc(long long x)
{
	return x*g[1]+x*x*g[2]+x*x*x*g[3]+x*x*x*x*g[4]+x*x*x*x*x*g[5];
}

void cc()
{
	for(int i=1;i<=n;++i)
	{
		if(exist[i]==1) continue;
		for(int j=l[i];j<=r[i];++j)
		{
			++standnum[j].val;
		}
	}
}

int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%lld%d",&n,&m);
	for(int i=1;i<=5;++i)
	{
		scanf("%lld",&g[i]);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&l[i],&r[i]);
	}
	int ifsubtask1=1;
	for(int i=1;i<=n;++i)
	{
		if(l[i]!=1) {ifsubtask1=0;break;}
	}
	if(ifsubtask1)
	{
		ans=ans+n*g[1]+n*n*g[2]+n*n*n*g[3]+n*n*n*n*g[4];
		ans=ans+n*n*n*n*n*g[5];
		printf("%lld\n",ans);
	}
	else
	{
		long long cur=0;
		int standing=0;
		for(int i=1;i<=m&&standing<=n;++i)
		{
			for(int i=1;i<=m;++i) standnum[i].pos=i;
			for(int i=1;i<=m;++i) standnum[i].val=0;
			cc();
			sort(standnum+1,standnum+m+1,cmp);
			cur=standnum[1].val;
			standing+=cur;
			int p=standnum[1].pos;
			for(int i=1;i<=n;++i)
			{
				if(l[i]<=p&&r[i]>=p) exist[i]=1;
			}
			ans+=calc(cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
6 5
0 1 0 0 0
1 2
2 3
1 4
4 5
2 5
3 4
*/
