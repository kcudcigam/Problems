#include<bits/stdc++.h>
using namespace std;
long long Y,u,v;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long i;
	scanf("%lld",&Y);
	if(Y==4)
	{
		printf("4 6\n1 2\n2 4\n1 3\n3 4\n2 3\n1 4");
		return 0;
	}
	else
	{
		printf("%lld %lld\n",Y+1,Y*2-1);
		for(i=1;i<Y;i++)
		{
			printf("1 %lld\n",i+1);
			printf("%lld %lld\n",i+1,Y+1);
		}
		printf("1 %lld",Y+1);
		return 0;
	}
}

