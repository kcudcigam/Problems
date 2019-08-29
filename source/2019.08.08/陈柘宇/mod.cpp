#include<bits/stdc++.h>
#define LL long long
#define MAXN 10000000
using namespace std;
template<typename T>void Read(T &cn)
{
	char c;int sig = 1;
	while(!isdigit(c = getchar()))if(c == '-')sig = -1; cn = c-48;
	while(isdigit(c = getchar()))cn = cn*10+c-48;cn*=sig;
}
template<typename T>void Write(T cn)
{
	if(cn<0){putchar('-');cn = 0-cn;}
	int wei = 0;T cm = 0; int cx = cn%10;cn/=10;
	while(cn)wei++,cm = cm*10+cn%10,cn/=10;
	while(wei--)putchar(cm%10+48),cm/=10;
	putchar(cx+48);
}
LL f[MAXN+1];
int q,n,MOD;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	Read(q);
	while(q--)
	{
		f[1] = 0;
		Read(n); Read(MOD);
		for(int i = 2;i<=n;i++)f[i] = (f[i-1] * i + (1ll*(i-1)*i - ((i&1) ? 0 : (i-2))))%MOD;
		Write(f[n]); puts("");
	}
	return 0;
}

