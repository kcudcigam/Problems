#include<cstdio>
int q;
long long n,p,add[10000010],ans;
void makeAddition()
{
	add[1]=2;
	add[2]=6;
	int now=8;
	for(int i=3;i<=10000005;i+=2)
	{
		add[i]=add[i-2]+now;
		now+=8;
	}
	now=14;
	for(int i=4;i<=10000005;i+=2)
	{
		add[i]=add[i-2]+now;
		now+=8;
	}
	return ;
}
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	scanf("%d",&q);
	makeAddition();
	while(q--)
	{
		scanf("%lld%lld",&n,&p);
		ans=0;
		for(long long i=1;i<n;i++) ans=((ans*(i+1))%p+add[i])%p;
		printf("%lld\n",ans);
	}
	return 0;
}
