#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100005;

int T;
int n,t[MAXN],x[MAXN],y[MAXN];

int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T>0)
	{
		--T;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&t[i],&x[i],&y[i]);
		}
		int prex=0,prey=0,pret=0;
		int flag=1;
		for(int i=1;i<=n;++i)
		{
			int dist=abs(x[i]-prex)+abs(y[i]-prey);
			prex=x[i];prey=y[i];
			if((t[i]-pret)<dist) {printf("NO\n");flag=0;break;}
			if((t[i]-pret)%2==1)
			{
				if(dist%2==0) {printf("NO\n");flag=0;break;}
			}
			if((t[i]-pret)%2==0)
			{
				if(dist%2==1) {printf("NO\n");flag=0;break;}
			}
			pret=t[i];
		}
		if(flag==1) printf("YES\n");
	}
	return 0;
}
