#include<bits/stdc++.h>
#define MAXN 1010
#define LL long long
#define MOD 1000000007
#define MAXAI 20100
using namespace std;
template<typename T>void Read(T &cn)
{
	char c;int sig = 1;
	while(!isdigit(c = getchar()))if(c == '-')sig = -1;cn = c-48;
	while(isdigit(c = getchar()))cn = cn*10+c-48;cn*=sig;
}
template<typename T>void Write(T cn)
{
	if(cn < 0) {putchar('-'); cn = 0-cn; }
	int wei = 0; T cm = 0; int cx = cn%10; cn/=10;
	while(cn)wei++,cm = cm*10+cn%10,cn/=10;
	while(wei--)putchar(cm%10+48),cm/=10;
	putchar(cx+48);
}
int a[MAXN+1],B[MAXN+1],C[MAXN+1];
LL f[MAXAI*2+1],g[MAXAI*2+1];
int n,m;
int he[MAXAI*2+1];
void zuo(LL f[],int b[])
{
	for(int i = 0;i<=m+a[1];i++)f[i] = 0;
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
