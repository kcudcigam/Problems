#include<bits/stdc++.h>
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
typedef bitset<250> BT;
struct qwe{
	int l,r,sl,sr;
};
struct qwer{
	int a,b; 
	void mk(int cn,int cm) {a = cn; b = cm; } 
	inline friend bool operator <(qwer a,qwer b) {return a.a == b.a ? a.b < b.b : a.a < b.a; }
};
int n,m,xian;
qwe a[MAXN+1];
qwer b[MAXN*2+1];
int he[MAXN*5+1];
LL ans,zo;
int yong[MAXN+1];
int a1,a2,a3,a4,a5;
LL f[100000+1];
map<LL,LL> M;
int zhan[7000000+1],zlen;
LL g[500+1][500+1];
LL suan(LL cn) {return a1*cn + a2*cn*cn + a3*cn*cn*cn + a4*cn*cn*cn*cn + a5*cn*cn*cn*cn*cn; }
LL sou1(int cn)
{
	if(f[cn] != -1)return f[cn];
	for(int i = 1;i<=n;i++)yong[i] = 1;
	for(int i = 1;i<=n;i++)if(cn & (1<<(i-1)))yong[i] = 0;
	for(int i = 0;i<=xian;i++)he[i] = 0;
	for(int i = 1;i<=n;i++)if(!yong[i])he[a[i].sl]++,he[a[i].sr+1]--;
	for(int i = 1;i<=xian;i++)he[i] += he[i-1];
	int da = 0; he[da] = 0;
	for(int i = 1;i<=xian;i++)if(he[i] > he[da])da = i;
	int lin2 = he[da],kai = zlen+1;
	for(int i = 1;i<=xian;i++)if(he[i] == he[da])zhan[++zlen] = i;
	int jie = zlen;
	for(int i = kai;i<=jie;i++)
	{
		int lin = cn;
		for(int j = 1;j<=n;j++)if((cn & (1<<(j-1))) && a[j].sl <= zhan[i] && zhan[i] <= a[j].sr)lin = lin ^ (1<<(j-1));
		f[cn] = max(f[cn],sou1(lin));
	}
	f[cn] = f[cn] + suan(lin2);
	zlen = kai-1;
//	printf("in sou1 : cn = %d f[cn] = %lld\n",cn,f[cn]);
	return f[cn];
}
void zuo1()
{
	for(int i = 0;i<=(1<<n)-1;i++)f[i] = -1;
	f[0] = 0;
	Write(sou1((1<<n)-1)); puts("");
}
LL sou2(LL cn)
{
	if(M.find(cn) != M.end())return M[cn];
	for(int i = 1;i<=n;i++)yong[i] = 1;
	for(int i = 1;i<=n;i++)if(cn & (1ll<<(i-1)))yong[i] = 0;
	for(int i = 0;i<=xian;i++)he[i] = 0;
	for(int i = 1;i<=n;i++)if(!yong[i])he[a[i].sl]++,he[a[i].sr+1]--;
	for(int i = 1;i<=xian;i++)he[i] += he[i-1];
	int da = 0; he[da] = 0;
	for(int i = 1;i<=xian;i++)if(he[i] > he[da])da = i;
	int lin2 = he[da],kai = zlen+1;
	for(int i = 1;i<=xian;i++)if(he[i] == he[da])zhan[++zlen] = i;
	int jie = zlen;
	LL ans = 0;
	for(int i = kai;i<=jie;i++)
	{
		LL lin = cn;
		for(int j = 1;j<=n;j++)if((cn & (1ll<<(j-1))) && a[j].sl <= zhan[i] && zhan[i] <= a[j].sr)lin = lin ^ (1ll<<(j-1));
		ans = max(ans,sou2(lin));
	}
	zlen = kai-1;
	return M[cn] = ans + suan(lin2);
}
void zuo2()
{
	M[0] = 0;
	Write(sou2((1ll<<n)-1)); puts("");
}
void zuo3()
{
	for(int i = 1;i<=n;i++)for(int j = 1;j<=i-1;j++)g[i][j] = 0;
	for(int i = 1;i<=xian;i++)
	{
		int lin = xian-i+1;
		for(int j = 1;j<=lin;j++)
		{
			int bx = j,by = j+i-1;
			g[bx][by] = 0;
			zlen = 0;
			for(int k = 1;k<=n;k++)if(bx <= a[k].sl && a[k].sr <= by)zhan[++zlen] = k;
			if(!zlen) continue; 
			for(int k = bx;k <= by;k++)
			{
				int geshu = 0;
				for(int ij = 1;ij<=zlen;ij++)
				{
					if(a[zhan[ij]].sl <= k && k <= a[zhan[ij]].sr)geshu++;
				}
				g[bx][by] = max(g[bx][by],g[bx][k-1] + g[k+1][by] + suan(geshu));
			}
		}
	}
	Write(g[1][xian]); putchar('\n');
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	Read(n); Read(m);
	Read(a1); Read(a2); Read(a3); Read(a4); Read(a5);
	for(int i = 1;i<=n;i++)Read(a[i].l),Read(a[i].r),a[i].sl = a[i].sr = 0,b[i*2-1].mk(a[i].l,i),b[i*2].mk(a[i].r,i);
	sort(b+1,b+n*2+1);
	xian = 0; b[0].a = -1;
	for(int i = 1;i<=n*2;i++)
	{
		xian += (b[i].a != b[i-1].a);
		if(a[b[i].b].sl == 0)a[b[i].b].sl = xian;
		else a[b[i].b].sr = xian;
	}
//	if(n<=15) {zuo1(); return 0; }
//	if(m<=10) {zuo2(); return 0; }
	zuo3();
	return 0;
}
