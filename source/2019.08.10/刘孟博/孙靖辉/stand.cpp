#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define re register int 
int n,m,flag;
int a1,b,c,d,e;
int dp[100];//到第i家店最多聚集了多少使者 
struct node {
	int l,r;
}a[100];
inline ll calc(int x)
{
	return a1*x+b*x*x+c*x*x*x+d*x*x*x*x+e*x*x*x*x*x;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d",&a1,&b,&c,&d,&e);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	ll ans=calc(n);
	printf("%lld\n",ans);
	return 0;
}
