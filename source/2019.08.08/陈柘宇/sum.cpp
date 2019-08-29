#include<bits/stdc++.h>
#define MAXN 200000
#define LL long long
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
int n;
LL INF = 1;
LL a[MAXN+1];
LL f[MAXN+1],g[MAXN+1],fd[MAXN+1],gd[MAXN+1];
LL ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	INF = INF<<60;
	Read(n);
	for(int i = 1;i<=n;i++)Read(a[i]);
	f[0] = 0;
	for(int i = 1;i<=n;i++)f[i] = max(f[i-1] + a[i],a[i]);
	g[n+1] = 0;
	for(int i = n;i>=1;i--)g[i] = max(g[i+1] + a[i],a[i]);
	fd[0] = gd[n+1] = ans = -(INF);
	for(int i = 1;i<=n;i++)fd[i] = max(fd[i-1],f[i]);
	for(int i = n;i>=1;i--)gd[i] = max(gd[i+1],g[i]);
	for(int i = 1;i<n;i++)ans = max(ans,fd[i] + gd[i+1]);
	Write(ans); putchar('\n');
	return 0;
}
