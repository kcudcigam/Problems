#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL mod=998244353;
inline LL ksm(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%mod) b&1?res=res*a%mod:0;
	return res;
}
LL n,len; char s[1000005];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	scanf("%s",s+1); len=strlen(s+1);
	printf("%lld\n",((ksm(26,n)-(len+1)*ksm(26,n-len))%mod+mod)%mod);
	return 0;
}
