#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar();F*=R;
}
#define mod 1000000007
long long f[310][310];
long long make_dp(int i,int j)
{
	if(f[i][j]) return f[i][j];
	for(int k=1;k<=i-1;k++)
		(f[i][j]+=make_dp(k,j)*make_dp(i-k,j)%mod)%=mod;
	for(int k=1;k<=j-1;k++)
		 (f[i][j]+=make_dp(i,k)*make_dp(i,j-k)%mod)%=mod;
	return f[i][j];
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	read(n),read(m);
	f[1][1]=1;
	cout<<make_dp(n,m)<<endl;
	return 0;
}


