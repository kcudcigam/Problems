#include<bits/stdc++.h>
#define Mod 998244353
using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
string s;
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f!='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
ll ksm(ll d,ll p)
{
	if(p==1)return d;
	ll ans=ksm(d,p/2);	
	if(p%2==0)
	{
		ans=(ans%Mod)*(ans%Mod)%Mod;
	}else{
		ans=(ans%Mod)*(ans%Mod)*d%Mod;
	}
	return ans;
}
void init()
{
	read(n);
	cin>>s;
}
void work()
{
	ll len=s.length();
	ll m=n-len;
	if(m<0)cout<<ksm(26,n)<<endl;
	else if(m==0){
		cout<<((ksm(26,n)+Mod)-1)%Mod<<endl;
	}else if(m<=len)
	{
		cout<<(ksm(26,n)+Mod-((ksm(25,m)%Mod)*((len-m)%Mod)%Mod+(ksm(26,m+1)+Mod-ksm(25,m+1))%Mod)%Mod)%Mod<<endl;
	}else if(m>len)
	{
		cout<<(ksm(26,n)+Mod-((ksm(26,m+1)+Mod-ksm(25,m+1))%Mod+Mod-(ksm(25,len+1)*ksm(26,m-len)%Mod+Mod-ksm(25,m+1))%Mod)%Mod)%Mod<<endl;
	}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	init();
	work();
	return 0;
}


