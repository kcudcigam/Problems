#include<cstdio>
long long y,yTwoBit,minusOfY,bit=1,powTwo[70],pathCount;
long long lowbit(long long x){return x&(-x);}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	powTwo[0]=1;
	for(int i=1;i<63;i++) powTwo[i]=powTwo[i-1]<<1ll;
	scanf("%lld",&y);
	yTwoBit=y;
	while(yTwoBit!=lowbit(yTwoBit))
	{
		yTwoBit+=lowbit(yTwoBit);
		pathCount--;
	}
	minusOfY=yTwoBit-y;
	while(yTwoBit)
	{
		bit++;
		yTwoBit>>=1;
	}
	pathCount+=(bit*(bit-1))>>1ll;
	printf("%lld %lld\n",bit,pathCount);
	for(int i=1;i<bit;i++)
	{
		for(int j=i+1;j<=bit;j++)
		{
			if(i>1&&j==bit&&lowbit(minusOfY)==powTwo[i-2]) minusOfY-=lowbit(minusOfY);
			else printf("%d %d\n",i,j);
		}
	}
	return 0;
}
