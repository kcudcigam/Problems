#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL f[20]={0,1,2,8,64,1024,32768,2097152,268435456,68719476736,3518437208832,36028797018963968};
LL Y,now,d;
int pos,v,dv,e,ae;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&Y);
	if(Y<=50)
	{
		printf("%lld %lld\n",Y+1,Y);
		for(int i=1;i<=Y;i++)
			printf("%d %lld\n",i,Y+1);
		return 0;
	}
	pos=lower_bound(f+1,f+12,Y)-f;
	now=f[pos],d=f[pos-1];
	v=pow(2,pos)-1,e=(pow(2,2*pos-1)-2)/3+pow(2,pos-1);
	while(now>Y)
		dv++,now-=d,v--,e=e-pow(2,pos-2)-1;
	ae=Y-now;e+=2*ae;v+=ae;
	printf("%d %d\n",v+1,e);
	int num=1,step=1;
	for(int i=1;i<=pos-1;i++)
	{
		int cnt=1;
		int s=pow(2,i),e=pow(2,i+1)-1;
		if(i==pos-1)
			e=v-ae;
		while(cnt<=step)
		{
			for(int j=s;j<=e;j++)
				printf("%d %d\n",num,j);
			num++,cnt++;
		}
		step*=2;
	}
	for(int i=v-ae+1;i<=v;i++)
	{
		printf("1 %d\n",i);
		printf("%d %d\n",i,v+1);
	}
	for(int s=pow(2,pos-1);s<=pow(2,pos)-1-dv;s++)
		printf("%d %d\n",s,v+1);
	return 0;
}
