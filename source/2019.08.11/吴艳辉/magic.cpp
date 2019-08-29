#include<bits/stdc++.h>
using namespace std;
long long si,n,ans,sum;
char s[1000000];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int i,j;
	scanf("%lld",&n);
	ans=int(pow(26,n))%998244353;
	scanf("%s",s);
	si=strlen(s);
	if(n==si)
	{
		printf("%lld",ans-1);	
		return 0;
	}
	if(n-si==1)
	{
		sum=(ans-25*n%998244353-1)%998244353;
		printf("%lld",sum);
		return 0;
	}
	if(n-si>=1)
	{
		sum=(ans-25*25*(n-si+1)%998244353-1)%998244353;
		printf("%lld",sum);
		return 0;
	}
}
