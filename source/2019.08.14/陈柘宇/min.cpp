#include<bits/stdc++.h>
#define MAXN 200000
#define LL long long
#define INF 1ll<<60
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
	int l,r;
	LL da,lda;
	LL xiao;
	void mk(int cn,int cm,LL cx,LL cy,LL cw) {l = cn; r = cm; da = cx; xiao = cy; lda = cw; }
};
int n;
LL A,B,C,D;
int a[MAXN+1];
qwe zhan[MAXN+1];
int zlen;
LL f[MAXN+1];
LL suan(LL cn) {return A*cn*cn*cn + B*cn*cn + C*cn + D; }
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	Read(n); Read(A); Read(B); Read(C); Read(D);
	for(int i = 1;i<=n;i++)Read(a[i]);
	zlen = 0;
	f[0] = 0;
	for(int i = 1;i<=n;i++)
	{
		zhan[++zlen].mk(i,i,f[i-1],a[i],-INF);
		if(zlen > 1)zhan[zlen].lda = max(zhan[zlen-1].lda,zhan[zlen-1].da + suan(zhan[zlen-1].xiao));
		while(zlen > 1 && zhan[zlen-1].xiao >= zhan[zlen].xiao)
		{
			zlen--;
			zhan[zlen].r = zhan[zlen+1].r;
			zhan[zlen].da = max(zhan[zlen].da,zhan[zlen+1].da);
			zhan[zlen].xiao = zhan[zlen+1].xiao;
		}
		f[i] = max(zhan[zlen].lda,zhan[zlen].da + suan(zhan[zlen].xiao));
	}
	Write(f[n]); putchar('\n');
	return 0;
}
