#include<bits/stdc++.h>
#define LL long long
#define MAXN 200000
#define MAXM 500000
#define INF 1ll<<61
using namespace std;
template<typename T>void Read(T &cn)
{
	char c; int sig = 1;
	while(!isdigit(c = getchar()))if(c == '-')sig = -1; cn = c-48;
	while(isdigit(c = getchar()))cn = cn*10+c-48; cn*=sig;
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
	LL w;
};
struct qwr{int a,b,ne; };
struct qwer{
	int a,b;
	inline friend bool operator <(qwer a,qwer b)
	{
		return a.b > b.b;
	}
	void mk(int cn,int cm) {a = cn; b = cm; }
};
qwe a[MAXM*2+1];
int alen;
int head[MAXN+1];

qwr t[MAXN*2+1];
int tlen;
int head2[MAXN+1];
int n,m;
LL lu[MAXN+1];
LL lu2[MAXN+1];
int lai[MAXN+1];
qwer dui[MAXM+1];
int dlen;
int lie[MAXN+1],dfn[MAXN+1],lef[MAXN+1],shi;
void lian(int cn,int cm,int cx)
{
	a[++alen].a = cn;
	a[alen].b = cm;
	a[alen].w = cx;
	a[alen].ne = head[cn];
	head[cn] = alen;
}
void lian2(int cn,int cm)
{
	t[++tlen].a = cn;
	t[tlen].b = cm;
	t[tlen].ne = head2[cn];
	head2[cn] = tlen;
}
void Dij(int cn,LL Lu[])
{
	dui[dlen = 1].mk(1,0);
	for(int i = 1;i<=n;i++)Lu[i] = INF;
	Lu[1] = 0;
	lai[1] = 0;
	while(dlen)
	{
		while(dlen && dui[1].b != Lu[dui[1].a])
		{
			pop_heap(dui+1,dui+dlen+1);
			dlen--;
		}
		if(!dlen)break;
		int dang = dui[1].a;
		pop_heap(dui+1,dui+dlen+1);
		dlen--;
		for(int i = head[dang];i;i = a[i].ne)
		{
			int y = a[i].b;
			if(Lu[y] > Lu[dang] + a[i].w){
				lai[y] = i;
				Lu[y] = Lu[dang] + a[i].w;
				dui[++dlen].mk(y,Lu[y]);
				push_heap(dui+1,dui+dlen+1);
			}
		}
	}
}
void sou(int cn)
{
	lie[dfn[cn] = ++shi] = cn;
	for(int i = head2[cn];i;i = t[i].ne)
	{
		int y = t[i].b;
		sou(y);
	}
	lef[cn] = shi;
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	Read(n);
	Read(n); Read(m);
	alen = 0; memset(head,0,sizeof(head));
	if(n == m+1){
		Write(0); putchar(' ');
		for(int i = 2;i<=n;i++)Write(-1),putchar(' '); puts("");
	}
	for(int i = 1;i<=m;i++)
	{
		int bx,by,bz;
		Read(bx); Read(by); Read(bz);
		lian(bx,by,bz);
		lian(by,bx,bz);
	}
	Dij(1,lu);
	tlen = 0;
	memset(head2,0,sizeof(head2));
	for(int i = 2;i<=n;i++)lian2(a[lai[i]].a,i);
	shi = 0;
	sou(1);
//	for(int i = 1;i<=shi;i++)printf("lie[%d] = %d\n",i,lie[i]);
//	for(int i = 1;i<=n;i++)printf("dfn[%d] = %d lef[%d] = %d\n",i,dfn[i],i,lef[i]);
//	for(int i = 1;i<=n;i++)printf("dfn[%d] = %d\n",i,lai[i]);
	Write(0); putchar(' ');
	for(int i = 2;i<=n;i++)
	{
		LL ans = INF;
		int yuan = 0;
		for(int j = head[i];j;j = a[j].ne)
		{
			int y = a[j].b;
			if(((j-1)^1)+1 == lai[i] || y == i)continue;
			if(lu[y] + a[j].w < ans)ans = lu[y] + a[j].w,yuan = a[j].w;
		}
		if(ans - yuan <= lu[i]){
			Write(ans); putchar(' ');
			continue;
		}
		ans = INF;
		for(int j = dfn[i];j<=lef[i];j++)
		{
			int y = lie[j];
			for(int k = head[y];k;k = a[k].ne)
			{
				int xy = a[k].b;
				if(((k-1)^1)+1 == lai[i])continue;
				if(dfn[xy] < dfn[i] || dfn[xy] > lef[i])ans = min(ans,lu[y] - lu[i] + lu[xy] + a[k].w);
			}
		}
		Write(ans < INF ? ans : -1); putchar(' ');
	}
	puts("");
	return 0;
}
