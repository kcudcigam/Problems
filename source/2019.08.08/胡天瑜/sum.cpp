#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100010;

int n;
int a[MAXN];
struct QAQ
{
	long long val;
	int pos;
}answer[MAXN];
long long answer2[MAXN];
long long ans1=-(1<<30);
long long ans2=-(1<<30);
int startpos;
int startpos2;

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	long long tempans=0;startpos=1;
	for(int i=1;i<=n;++i)
	{
		tempans+=a[i];
		answer[i].val=tempans;
		answer[i].pos=startpos;
		if(tempans<0) {tempans=0;startpos=i+1;}
	}
	int l,r;
	for(int i=1;i<=n;++i)
	{
		if(ans1<answer[i].val)
		{
			l=answer[i].pos;r=i;
			ans1=answer[i].val;
		}
	}
	for(int i=l;i<=r;++i) a[i]=-a[i];
	tempans=0;
	for(int i=1;i<=n;++i)
	{
		tempans+=a[i];
		answer2[i]=tempans;
		if(tempans<0) tempans=0;
	}
	for(int i=1;i<=n;++i)
	{
		if(ans2<answer2[i]) ans2=answer2[i];
	}
	if(ans2<0&&l<r) ans2=0;
	printf("%lld\n",ans1+ans2);
	return 0;
}

