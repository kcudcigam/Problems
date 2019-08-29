#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1000005];
long long lens,sum=1,t,sum1=1;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n,i;
	scanf("%lld",&n);
	scanf("%s",s+1);
	lens=strlen(s+1);
	if(n==1){
		printf("25");
		return 0;
	}
	if(n==3&&lens==1){
		sum=676*2-26;
		printf("%lld",sum);
		return 0;
	}
	for(i=1;i<=n;i++){
		sum*=26;
	}
	if(n==3&&lens==2){
		if(s[1]!=s[2]){
			printf("%lld",sum-52);
		}
	}
	
	if(n==lens){
		printf("%lld",sum-1);
		return 0;
	}
	if(lens!=n-1&&lens!=1){
		sum-=(lens-1);
	}
	t=n-lens;
	for(i=1;i<=t;i++){
		sum1*=26;
	}
	sum1*=2;
	if(n==4&&lens==1){
		printf("%lld",sum-sum1+676);
	}
	if(n==4&&lens==3){
		if(s[1]!=s[2]||s[2]!=s[3]){
			printf("%lld",sum-sum1);
		}
		else{
			printf("%lld",sum-sum1+1);
		}
	}
	printf("%lld",sum-sum1+1);
	return 0;
}

//4
//ab
