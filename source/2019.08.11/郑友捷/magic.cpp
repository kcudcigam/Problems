#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod=998244353;
inline long long power(long long x,long long y,long long p){
	long long ans=1%p;
	for(;y;y>>=1){
		if(y&1) ans=ans*x%p;
		x=x*x%p;
	}
	return ans;
} 
long long sum,n,ans,now;
char ch[10000010];
bool inv[10],flag;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
	scanf("%d",&n);
	scanf("%s",ch);
	now=strlen(ch);
	sum+=power(26,n,mod);	
	sum%=mod;
	if(n==now){
		sum--;
		printf("%lld\n",sum);
		return 0;
	}
	long long now1=(power(26,n-now,mod)*(now+1))%mod;
	sum-=now1;
	sum%=mod;
	sum+=power(26,n-now-1,mod)*(now)%mod;
	sum%=mod;
	printf("%lld\n",sum); 
}
