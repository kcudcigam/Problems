#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar();F*=R;
}
#define mod 998244353
long long Qsum(long long ai,long long ki)
{
	if(ki==0) return 1;
	if(ki==1) return ai%mod;
	long long hi=Qsum(ai,ki/2); hi=hi*hi%mod;
	if(ki&1) hi=hi*ai%mod; return hi;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	string ax;
	read(n); cin>>ax;
	long long Sum=Qsum(26,n);
	if(n==ax.size()){cout<<(Sum-1+mod)%mod<<endl;return 0;}
	long long sm=Qsum(26,n-ax.size()-1),Sm=Qsum(26,n-ax.size());
	sm=(Sm-sm+mod)%mod;
	long long ansi=(Sum-(sm*ax.size()%mod+Sm)%mod+mod)%mod;
	cout<<ansi<<endl;
	return 0;
}

