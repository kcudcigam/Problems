#include<bits/stdc++.h>
#define LL long long
using namespace std;
void zuo(LL f[],int b[])
{
	for(int i = 0; i <= m + a[1]; ++i) f[i] = 0;
	f[0] = 1;
	for(int i = 1;i<=n;i++)
	{
		int zhong = m+a[i]-1;
		for(int j = 0;j<a[i];j++)
		{
			int wei = 0;
			for(int &k = wei;k*a[i]+j<=zhong;k++)he[k] = f[k*a[i]+j];
			wei--;
			for(int k = 1;k<=wei;k++)he[k] = (he[k] + he[k-1])%MOD;
			for(int k = 0;k<=wei;k++)
			{
				int lin = k-b[i]-1;
				f[k*a[i]+j] = (he[k] - (lin >= 0 ? he[lin] : 0) + MOD)%MOD;
			}
		}
	}
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	Read(n); Read(m);
	for(int i = 1;i<=n;i++)Read(a[n-i+1]),Read(B[n-i+1]),Read(C[n-i+1]);
	zuo(f,B); zuo(g,C);
	LL ans = 0;
	for(int i = m;i<=m+a[1];i++)ans = (ans + f[i] * g[i-m]%MOD)%MOD;
	Write(ans); putchar('\n');
	return 0;
}
