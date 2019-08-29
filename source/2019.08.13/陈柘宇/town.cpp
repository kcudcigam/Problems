#include<bits/stdc++.h>
#define MAXN 300000
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
struct qwe{
	int a,b,ne;
};
qwe a[MAXN*2+1];
int alen;
int head[MAXN+1];
int n;
int ba[MAXN+1];
int fa[MAXN+1],l[MAXN+1],r[MAXN+1];
int shen[MAXN+1],lie[MAXN*4+1],dfn[MAXN+1],shi;
int ST[MAXN*4+1][22];
int get_fa(int cn) {return ba[cn] == cn ? cn : ba[cn] = get_fa(ba[cn]); }
int erwei(int cn) {int guo = -1; while(cn)cn>>=1,guo++; return guo; }
void lian(int cn,int cm)
{
	a[++alen].a = cn;
	a[alen].b = cm;
	a[alen].ne = head[cn];
	head[cn] = alen;
}
void sou(int cn)
{
	lie[dfn[cn] = ++shi] = cn;
	for(int i = head[cn];i;i = a[i].ne)
	{
		int y = a[i].b;
		if(y == fa[cn])continue;
		shen[y] = shen[cn]+1;
		fa[y] = cn;
		sou(y);
		lie[++shi] = cn;
	}
}
void ST_mk(int cn)
{
	for(int i = 1;i<=cn;i++)ST[i][0] = lie[i];
	int lin = erwei(cn);
	for(int i = 1;i<=lin;i++)
	{
		int lin2 = cn - (1<<i)+1;
		for(int j = 1;j<=lin2;j++)
		{
			int lin3 = ST[j][i-1],lin4 = ST[j+(1<<(i-1))][i-1];
			if(shen[lin3] < shen[lin4])ST[j][i] = lin3; else ST[j][i] = lin4;
		}
	}
}
int qiu(int cn,int cm)
{
	if(cn > cm)swap(cn,cm);
	int lin = erwei(cm-cn+1);
	int lin1 = ST[cn][lin],lin2 = ST[cm-(1<<lin)+1][lin];
	return min(shen[lin1],shen[lin2]);
}
void zheng(int cn,int cm,LL &ans,LL &zuo,LL &you)
{
	int lin = qiu(dfn[cn],dfn[cm]);
	int lin2 = shen[cn] + shen[cm] - lin*2;
	if(lin2 > ans)ans = lin2,zuo = cn,you = cm;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	Read(n);
	alen = 0; memset(head,0,sizeof(head));
	for(int i = 1;i<=n-1;i++)
	{
		int bx,by; Read(bx); Read(by);
		lian(bx,by); lian(by,bx);
	}
	fa[1] = 0; shen[1] = 1; shi = 0;
	sou(1);
	ST_mk(shi);
	for(int i = 1;i<=n;i++)ba[i] = l[i] = r[i] = i;
	for(int i = 1;i<=n-1;i++)
	{
		int bx = a[i*2-1].a,by = a[i*2-1].b;
		int lin1 = get_fa(bx),lin2 = get_fa(by);
		ba[lin2] = lin1;
		LL ans = 0,zuo = lin1,you = lin1;
		zheng(l[lin1],r[lin1],ans,zuo,you);
		zheng(l[lin1],l[lin2],ans,zuo,you);
		zheng(l[lin1],r[lin2],ans,zuo,you);
		zheng(r[lin1],l[lin2],ans,zuo,you);
		zheng(r[lin1],r[lin2],ans,zuo,you);
		zheng(l[lin2],r[lin2],ans,zuo,you);
		l[lin1] = zuo,r[lin1] = you;
		Write(ans); putchar('\n');
	}
	return 0;
}
