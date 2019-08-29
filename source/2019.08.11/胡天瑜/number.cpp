#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int t;
long long n;
int v[12];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t>0)
	{
		--t;
		scanf("%lld",&n);
		memset(v,0,sizeof(v));
		for(;n;n=n/10)
		{
			if(v[n%10]==0) v[n%10]=1;
		}
		int temp=0;
		for(int i=0;i<=9;++i)
		{
			if(v[i]) ++temp;
		}
		if(temp<=2) printf("1\n");
		else printf("2\n");
	}
	return 0;
}


