#include<bits/stdc++.h>
#define LL long long
#define MAXN 200000
#define MOD 1000000007
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
struct qwe{
	int x,y,p;
	int gai;
	void getit() {Read(x); Read(y); Read(p); }
	inline friend bool operator <(qwe a,qwe b)
	{
		return a.x == b.x ? a.y < b.y : a.x < b.x; 
	}
};
int n,m,q;
qwe a[MAXN+1];
int xian[MAXN+1];
qwe b[MAXN+1];
int wei[MAXN+1];
bool Cmp(qwe cn,qwe cm) {return cn.y > cm.y; }
LL ksm(LL cn,LL cm) {LL ans = 1; while(cm)ans = ans * (1+(cn-1)*(cm&1))%MOD,cn = cn*cn%MOD,cm>>=1; return ans; }
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	Read(n); Read(m); Read(q);
	for(int i = 1;i<=m;i++)a[i].getit();
	sort(a+1,a+m+1);
	for(int i = 1;i<=n;i++)xian[i] = 1,wei[i] = 0;
	for(int i = 1;i<=m;i++)
	{
		a[i].gai = 1ll*xian[a[i].x]*a[i].p%MOD;
		xian[a[i].x] = (xian[a[i].x] - a[i].gai + MOD)%MOD;
		wei[a[i].x] = i;
	}
	wei[0] = 0;
	for(int i = 1;i<=n;i++)wei[i] = max(wei[i-1],wei[i]);
	LL ans = 0;
	for(int i = 1;i<=q;i++)
	{
		int bx,by; Read(bx); Read(by);
		int blen = 0;
		for(int j = wei[bx-1]+1;j<=wei[by];j++) b[++blen] = a[j];
		sort(b+1,b+blen+1,Cmp);
		for(int j = bx;j<=by;j++)xian[j] = 1; LL zong = 1;
		for(int j = 1;j<=blen;j++)
		{
			zong = zong * ksm(xian[b[j].x],MOD-2)%MOD;
			LL gl = 1ll*zong*b[j].gai%MOD;
			ans = (ans + 1ll*b[j].y * gl%MOD)%MOD;
			xian[b[j].x] = (xian[b[j].x] - b[j].gai + MOD)%MOD;
			zong = zong * xian[b[j].x]%MOD;
		}
	}
	Write(ans); putchar('\n');
	return 0;
}
