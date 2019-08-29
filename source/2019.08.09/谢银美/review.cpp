#include<iostream>
#include<cstdio>
using namespace std;
long long n,Ans,tot;
long long x;
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%lld",&n);
	while (n/2){
		n/=2;
		tot ++;
	}
	tot+=2;
	for (long long i = 1; i <= tot-1; ++ i)
		Ans += i;
	printf("%lld %lld\n",tot,Ans);
	for (long long k = 1; k <= tot; ++ k)
		for (long long i = 1; i+k <= tot; ++ i){
			printf("%lld %lld\n",i,i+k);
		}
	return 0;
}
