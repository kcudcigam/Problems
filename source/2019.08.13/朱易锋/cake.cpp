#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
    R int f=1,num=0;
    R char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
const ll mod=1000000007;
ll ans=0;
ll f[307][307];
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	f[1][1]=1;f[1][2]=f[2][1]=1;
	f[2][2]=2;
	R int n=read(),m=read();
	for(R int i=1;i<=n;i++)
	{
		for(R int j=1;j<=m;j++)
		{
			if(f[i][j])continue;
			for(R int k=1;k<=i-1;k++)
			{
				f[i][j]+=(f[k][j]*f[i-k][j]);
				f[i][j]%=mod;
			}
			for(R int k=1;k<=j-1;k++)
			{
				f[i][j]+=(f[i][k]*f[i][j-k]);f[i][j]%=mod;
			}
		}
	}
	printf("%lld",f[n][m]);
	return 0;
} 
