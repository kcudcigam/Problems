#include<bits/stdc++.h> 
#define gc() getchar()
#define il inline
#define ll long long
using namespace std;
template<typename T>il void read(T&x)
{
	int f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=gc())if(c=='-')f=-f;
	for(;isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
int n=1,m;
ll y,an;
il void solve()
{
	an=y;
	while(an!=1)
	n+=2,m+=((an&1)?4:3),an>>=1,n+=(an==3?1:0);
	printf("%d %d\n",n,m);
	an=y;
	int now=1;
	while(an!=1)
	{
		if(an==3)
		{
			printf("%d %d\n",now,now+1);
			printf("%d %d\n",now,now+2);
			printf("%d %d\n",now,n);
			printf("%d %d\n",now+1,n);
			printf("%d %d\n",now+2,n);
			break;
		}
		printf("%d %d\n",now,now+1);
		printf("%d %d\n",now,now+2);
		if(an&1)
		printf("%d %d\n",now,n);
		printf("%d %d\n",now+1,now+2);	
		an>>=1;
		now+=2;
	}
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	read(y);
	if(y==1)
	{
		puts("2 1");
		puts("1 2");
	}
	else
	if(y==2)
	{
		puts("3 3");
		puts("1 2");
		puts("2 3");
		puts("1 3");
	}
	else
	if(y==3)
	{
		puts("4 5");
		puts("1 2");
		puts("1 3");
		puts("1 4");
		puts("2 4");
		puts("3 4");
	}
	else solve();
	return 0;
}
