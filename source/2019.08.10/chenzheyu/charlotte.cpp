#include<bits/stdc++.h>
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
int t,n;
int ans;
int lstx,lsty,lstt;
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	Read(t);
	while(t--)
	{
		Read(n);
		ans = 1;
		lstx = lsty = lstt = 0;
		for(int i = 1;i<=n;i++)
		{
			int bx,by,bt;
			Read(bt); Read(bx); Read(by);
			int lin = -abs(lstx-bx) - abs(lsty-by)+(bt-lstt);
			ans = ans & (lin < 0 ? 0 : ((lin&1)^1));
			lstx = bx; lsty = by; lstt = bt;
		}
		puts(ans ? "Yes" : "No");
	}
	return 0;
}
