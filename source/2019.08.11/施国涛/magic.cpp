#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
#define rmod 998244353
	int lx[1000001],ni=0;
long long qp(long long a,long long b,long long mod)
{
	//a^b%mod a^(b.2)^2
	a%=mod;
	long long ans=1;
	while(b>1)
	{
		if(b&1)
		{
			ans=ans*a;
			ans%=mod;
		}			
		a=a*a;
		a%=mod; 
		b>>=1;
	//	cout<<ans<<" "<<a<<" "<<b<<endl;
	}
//	cout<<ans<<" "<<a<<endl;
	return (ans*a)%mod;
}
int main()
{
		freopen("magic.in","r",stdin);
		freopen("magic.out","w",stdout);	
	long long n,len=0,add=0;//n is all len is lenth(str) 26^(n-len)*(n-len+1)
	read(n); 
	long long tot=qp(26,n,rmod),hf=0,cf=0;
	char a=getchar(),last;

	while(a<'a'&&a>'z')
	{
		a=getchar();
	}
	last=a;
	lx[0]=1;
	while(a<='z'&&a>='a')
	{
		len++;
		a=getchar();		
		if(a==last)
		{
			lx[ni]++;
		}
		else
		{
			lx[ni+1]=1;
	//		cout<<lx[ni]<<" ";
			ni++;
			last=a;
		}
	}
	for(int i=0;i<ni;i++)
	{
		if(lx[i]-1)
		{
				if(len*2>n)
		{
			cf+=n*(2*lx[i]-n)/2; 
		}
		else
		{
			cf+=(lx[i]+1)*lx[i];
		}	
		}
	}
		if(len*2>n)
		{
			cf-=(3*len-n+1)*(n-len)/2;
		}
		else
		{
			cf-=len*(len+1)/2;
		}	
	
	if(n==len)
	{
		cout<<tot-1<<endl;
		return 0;
	}
	hf=(qp(26,(n-len),rmod)*((len+1%rmod))%rmod);  //aabc  all=6
													//aaabc  cf lenth(lenth-1)/2
												// n(2*len-n)/2 lenth>n*2
													// ( len+1)len/2             lenth<=n*2
													// len+len-1+ ...+(2*len-n+1)
												//	3*len-n+1 * n-len/2
//	cout<<tot<<" "<<hf<<" "<<len<<" "<<cf<<endl;
	cout<<((tot-hf-cf+rmod)%rmod)<<endl;
} 
