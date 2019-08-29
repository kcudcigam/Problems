#include<cstdio>
#include<cctype>
int n,m,l,r;
long long s,e,d,a1[500010],a2[500010],ans;
void qread(int& x)
{
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return ;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld%lld",&l,&r,&s,&e);
		d=(e-s)/(r-l);
		a1[l]+=s;
		a2[r+1]-=s;
		a2[l+1]+=d;
		a2[r+1]-=d;
	}
	for(int i=1;i<=n;i++)
	{
		a2[i]+=a2[i-1];
		a1[i]+=a2[i];
	}
	for(int i=1;i<=n;i++)
	{
		a1[i]+=a1[i-1];
		ans^=a1[i];
	}
	printf("%lld\n",ans);
	return 0;
}
