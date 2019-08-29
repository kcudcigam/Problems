#include<bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000
#define LL long long
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
LL f[MAXN+1][MAXN+1];
int n,m;
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	Read(n); Read(m);
	f[1][1] = 1;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(i == j && i == 1)continue;
			f[i][j] = 0;
			for(int k = 1;k<i;k++)
			{
				f[i][j] = (f[i][j] + f[k][j] * f[i-k][j]%MOD)%MOD;
			}
			for(int k = 1;k<j;k++)
			{
				f[i][j] = (f[i][j] + f[i][k] * f[i][j-k]%MOD)%MOD;
			}
		}
	}
	Write(f[n][m]); putchar('\n');
	return 0;
}
