#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &FF)
{
	FF=0;int r=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') r=-1;else FF=ch^48;ch=getchar();
	while(isdigit(ch)) FF=(FF<<1)+(FF<<3)+(ch^48),ch=getchar(); FF*=r;
}
long long f[100010],fi[100010],ai[100010],sum[100010],ans=LONG_LONG_MIN;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++)
		read(ai[i]),ai[i]+=ai[i-1],sum[i]=f[i]=ai[i];
	ai[0]=0;
	for(int i=1;i<=n;i++)
		ai[i]=min(ai[i],ai[i-1]),f[i]-=ai[i-1];
	for(int i=2;i<=n;i++)
		f[i]=max(f[i],f[i-1]);
	for(int i=1;i<=n;i++)
		fi[i]=ai[i]=sum[n]-sum[i-1];
	ai[n+1]=0;
	for(int i=n;i>=1;i--)
		ai[i]=min(ai[i],ai[i+1]),fi[i]-=ai[i+1];
	for(int i=1;i<=n-2;i++)
		ans=max(ans,f[i]+fi[i+2]);
	cout<<ans<<endl;
	return 0;
}

