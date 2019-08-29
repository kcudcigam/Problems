#include<bits/stdc++.h>
using namespace std;
unsigned long long y;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&y);
	printf("%lld ",y+1);
	cout<<y*2-1<<endl;
	for(unsigned long long i=2;i<=y;i++)
	printf("1 %lld\n%lld %lld\n",i,i,y+1);
	printf("1 %lld",y+1);
	return 0;
}


