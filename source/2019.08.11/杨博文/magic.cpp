#include<bits/stdc++.h>
using namespace std;
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;bool f=0;char c;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	}
}yin;
const long long mod=998244353;
unsigned long long ksm(long long a,long long n)
{
	if(!n)return 1ull;
	unsigned long long ans=ksm(a,n>>1ll);
	ans*=ans;
	ans%=mod;
	if(n&1ll)ans*=a,ans%=mod;
	return ans;	
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	yin>>n;
	char s[n+100];
	unsigned long long ans=ksm(26,n);
	scanf("%s",s+1);
	unsigned int x=strlen(s+1);
	for(unsigned int i=1;i<=x;++i)
	{
		unsigned int j=i;
		while(s[j]==s[i])++j;
		j--;
		ans+=(j-i+1);
	}
	cout<<(ans-(x+1)*ksm(26,n-x)%mod+mod)%mod<<endl;
	return 0;
} 
