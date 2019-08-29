#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &x)
{
	x=0; int f=1,t;
	while(t=getchar(),(t<'0'||t>'9')&&t!='-');
	if(t!='-') x=t-'0';
	else f=-1;
	while(t=getchar(),'0'<=t&&t<='9') x=x*10+t-'0';
	x=x*f;
}
LL Y;
int n,m,t=61;
int cnt(LL v)
{
	int res=0;
	while(v)
	{
		if(v&1) res++;
		v>>=1;
	}
	return res;
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	read(Y);
	while((1ll<<t)>Y) t--;
	if((1ll<<t)==Y)
	{
		printf("%d %d\n",t+2,(t+2)*(t+1)/2);
		for(int i=1;i<=t+1;i++)
			for(int j=i+1;j<=t+2;j++)
				printf("%d %d\n",i,j);
	}
	else
	{
		n=t+3; m=(t+2)*(t+1)/2+cnt(Y);
		printf("%d %d\n",n,m);
		for(int i=1;i<=t+1;i++)
			for(int j=i+1;j<=t+2;j++)
				printf("%d %d\n",i,j);
		for(int i=0;i<=60;i++) if((Y>>i)&1)
			printf("%d %d\n",i+2,n);
	}
	return 0;
}
