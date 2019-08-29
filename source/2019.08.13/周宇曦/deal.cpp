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
long long f[1010][20010],fi[20010];
int ac[10010];
struct coin{
	int val,ai,bi;
}ci[1010];
struct ch{
	int val,gs;
}c1[16000];
int c2[16000];
int num1,num2;
void logg(int i)
{
	for(int i=1;i<=ci[i].ai;i++)
	{
		c1[++num1].val=ci[i].val;
		c1[num1].gs=i;
	}
	for(int i=1;i<=ci[i].bi;i++)
		c2[++num2]=ci[i].val;
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	int n,x,maxn=0;
	long long ans=0;
	read(n),read(x);
	for(int i=1;i<=n;i++)
		read(ci[i].val),read(ci[i].ai),read(ci[i].bi),maxn=max(maxn,ci[i].val);
	for(int i=1;i<=n;i++) logg(i);
	f[0][0]=1;
	for(int i=1;i<=num1;i++)
		for(int j=x;j>=0;j--)
			if(c1[i].val<=j)
				f[c1[i].gs][i]=(f[c1[i-1].gs][j-c1[i].val]+1)%mod;
	for(int i=n;i>=1;i--)
		for(int j=x;j>=0;j--)
			(f[i][j]+=f[i+1][j])%=mod;
	fi[0]=1;
	for(int i=1;i<=num2;i++)
		for(int j=maxn;j>=0;j--)
			if(c2[i]<=j)
				fi[i]=(fi[j-c2[i]]+1)%mod;
	for(int i=0;i<=maxn;i++)
		cout<<fi[i]<<" ";
	cout<<endl;
	int hi=0;
	for(int i=1;i<=maxn;i++)
	{
		if(i>ci[hi].val) ac[i]=++hi;
		else ac[i]=hi;
	}
	for(int i=0;i<=x;i++)
		for(int j=n;j>=1;j--)
			if(ci[j].val+i>=x)
				(ans=ans+f[ac[ci[j].val+i-x+1]][i]*fi[ci[j].val+i-x]%mod)%=mod;
	cout<<ans<<endl; 
	return 0;
}



