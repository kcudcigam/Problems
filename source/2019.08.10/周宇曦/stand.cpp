#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar(); F*=R;
}
long long f[1010][1010];
struct sz{int li,ri;}ai[310];
int gx[6],ls[1010],num,n,m,ans;
bool vis[1010][1010];
long long sum(long long x){return gx[1]*x+gx[2]*x*x+gx[3]*x*x*x+gx[4]*x*x*x*x+gx[5]*x*x*x*x*x;}
long long Dp(int ll,int rr)
{
	if(ll>rr) return 0;
	if(vis[ll][rr]) return f[ll][rr];
	vis[ll][rr]=1;
	int qi[rr-ll+1]={0};
	for(int i=1;i<=n;i++)
		if(ai[i].li>=ll&&ai[i].ri<=rr)
		{
			qi[ai[i].li-ll]++;
			if(ai[i].ri<rr) qi[ai[i].ri-ll+1]--;
		}
	long long ans=0,pi=0;
	for(int i=0;i<rr-ll+1;i++)
	{
		pi+=qi[i];
		if(pi) ans=max(ans,Dp(ll,ll+i-1)+Dp(ll+i+1,rr)+sum(pi));
	}
	return f[ll][rr]=ans;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=5;i++) read(gx[i]);
	for(int i=1;i<=n;i++)
	{
		read(ai[i].li),read(ai[i].ri);
		ls[++num]=ai[i].li,ls[++num]=ai[i].ri;
	}
	sort(ls+1,ls+num+1);
	num=unique(ls+1,ls+num+1)-(ls+1);
	for(int i=1;i<=n;i++)
	{
		ai[i].li=lower_bound(ls+1,ls+num+1,ai[i].li)-ls;
		ai[i].ri=lower_bound(ls+1,ls+num+1,ai[i].ri)-ls;
	}
	cout<<Dp(1,num)<<endl;
	return 0;
}

