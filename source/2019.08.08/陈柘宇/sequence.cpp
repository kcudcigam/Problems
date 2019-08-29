#include<bits/stdc++.h>
#define LL long long
#define MAXN 500000
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
struct qwe{
	LL num,a,b;
	inline friend bool operator <(qwe a,qwe b)
	{
		return a.num < b.num;
	}
	void mk(int cn,LL cm,LL cx) {num = cn; a = cm; b = cx; }
};
qwe a[MAXN*2+1];
int n,m;
LL ans,xiz,dang;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	Read(n); Read(m);
	for(int i = 1;i<=m;i++)
	{
		LL bx,by,bn,bm;
		Read(bx); Read(by); Read(bn); Read(bm);
		LL jie = by == bx ? 0 : (bm-bn)/(by-bx);
		a[i*2-1].mk(bx,bn,jie);
		a[i*2].mk(by+1,0-bm-jie,0-jie);
	}
	xiz = ans = dang = 0;
	int wei = 0;
	sort(a+1,a+m*2+1);
	for(int i = 1;i<=n;i++)
	{
		while(wei < m*2 && a[wei+1].num <= i)
		{
			wei++;
			dang += a[wei].a;
			xiz += a[wei].b;
		}
		ans = ans ^ dang;
		dang = dang + xiz;
	}
	Write(ans); puts("");
	return 0;
}

