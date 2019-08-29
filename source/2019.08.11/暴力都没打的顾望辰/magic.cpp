/*O( slog(n) )
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int CYS=998244353;
long long qpow(long long x,long long p)
{
	long long ret=1;
	while(p)
	{
		if(p&1ll) ret=ret*x%CYS;
		x=x*x%CYS;
		p>>=1ll;
	}
	return ret;
}
long long getAdd(long long n,long long len)
{
	if(n==len+1) return 25*(len+1)%CYS;
	else return 625*(len+1)%CYS*qpow(26,n-len-2)%CYS;
}
void outAns(long long n,long long len)
{
	long long ans=0;
	if(n==1) ans=25;
	else ans=625*qpow(26,n-2);
	for(long long i=1;i<len;i++) ans=(ans+getAdd(n,i))%CYS;
	cout<<ans<<endl;
	return ;
}
int main()
{
	long long n;
	string s;
	cin>>n>>s;
	outAns(n,s.size());
	return 0;
}*/


//O( log(n)+slog(s) )
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long CYS=998244353;
long long qpow(long long x,long long p)
{
	long long ret=1;
	while(p)
	{
		if(p&1ll) ret=ret*x%CYS;
		x=x*x%CYS;
		p>>=1ll;
	}
	return ret;
}
long long getAdd(long long n,long long len)
{
	if(n==len+1) return 25*(len+1)%CYS;
	else return 625*(len+1)%CYS*qpow(26,n-len-2)%CYS;
}
long long inv(long long x)
{
	return qpow(x,CYS-2);
}
void outAns(long long n,long long len)
{
	long long ans=0,lastAdd=getAdd(n,1);
	if(n==1) ans=25;
	else ans=625*qpow(26,n-2);
	ans=(ans+lastAdd)%CYS;
	for(long long i=2;i<len;i++)
	{
		if(n==i+1) lastAdd=lastAdd*inv(25*i)%CYS*(i+1)%CYS;
		else lastAdd=lastAdd*inv(26*i)%CYS*(i+1)%CYS;
		ans=(ans+lastAdd)%CYS;
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	string s;
	cin>>n>>s;
	outAns(n,s.size());
	return 0;
}


/*O( log(n)+s ) 但常数较大 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long CYS=998244353;
long long inv[30000000];
long long qpow(long long x,long long p)
{
	long long ret=1;
	while(p)
	{
		if(p&1ll) ret=ret*x%CYS;
		x=x*x%CYS;
		p>>=1ll;
	}
	return ret;
}
long long getAdd(long long n,long long len)
{
	if(n==len+1) return 25*(len+1)%CYS;
	else return 625*(len+1)%CYS*qpow(26,n-len-2)%CYS;
}
void makeInv(long long range)
{
	inv[1]=1;
	for(register int i=2;i<range;++i) inv[i]=(CYS-CYS/i)*inv[CYS%i]%CYS;
	return ;
}
void outAns(long long n,long long len)
{
	makeInv(len*26+10);
	long long ans=0,lastAdd=getAdd(n,1);
	if(n==1) ans=25;
	else ans=625*qpow(26,n-2);
	ans=(ans+lastAdd)%CYS;
	for(long long i=2;i<len;i++)
	{
		if(n==i+1) lastAdd=lastAdd*inv[25*i]%CYS*(i+1)%CYS;
		else lastAdd=lastAdd*inv[26*i]%CYS*(i+1)%CYS;
		ans=(ans+lastAdd)%CYS;
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
	long long n;
	string s;
	cin>>n>>s;
	outAns(n,s.size());
	return 0;
}*/
