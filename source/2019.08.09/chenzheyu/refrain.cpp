#include<bits/stdc++.h>
#define MAXN 300000
#define MOD 1000000007
#define LL long long
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
int n,m1,m2;
int a[MAXN+1],b[MAXN+1];
int vis[MAXN+1];
int ge[MAXN+1];
int gl[MAXN+1];
int gl2[MAXN+1];
int zhan[MAXN+1];
int zlen;
LL ans,ans2;
LL jie[MAXN+1];
void duru(int a[],int m)
{
	for(int i = 1;i<=m;i++)
	{
		int bx,by;
		Read(bx); Read(by);
		a[bx] = by;
		a[by] = bx;
	}
}
void sou(int cn)
{
	//printf("in sou : cn = %d\n",cn);
	if(!cn)return;
	if(vis[cn])return;
	vis[cn] = 1;
	zhan[++zlen] = cn;
	sou(a[cn]); sou(b[cn]);
}
void yuchu(int cn)
{
	jie[0] = 1;
	for(int i = 1;i<=cn;i++)jie[i] = jie[i-1]*i%MOD;
}
LL ksm(LL cn,LL cm)
{
	LL ans = 1;
	while(cm)ans = ans * (1 + (cn-1)*(cm&1))%MOD,cn = cn*cn%MOD,cm>>=1;
	return ans;
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	Read(n);
	Read(n); Read(m1); Read(m2);
	yuchu(n);
	memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
	duru(a,m1); duru(b,m2);
	memset(vis,0,sizeof(vis));
//	printf("prepared\n");
	for(int i = 1;i<=n;i++)
	{
//		printf("i = %d\n",i);
		if(vis[i])continue;
		zlen = 0;
		sou(i);
		int tp = 0;
		for(int j = 1;j<=zlen;j++)if(!a[zhan[j]] || !b[zhan[j]])tp = zhan[j];
		if(zlen == 1) {gl[1]++; continue; }
		if(tp){
			if(a[tp])gl[zlen]++;
			else gl2[zlen]++;
		}
		else{
			ge[zlen]++;
		}
	}
//	printf("sou over\n");
	for(int i = 3;i<=n;i+=2)gl[i] += gl2[i],gl2[i] = 0;
	ans = 1;
	for(int i = 1;i<=n;i++)
	{
//		if(ge[i])printf("ge[%d] = %d\n",i,ge[i]);
		ans = ans * ksm(i,ge[i])%MOD * jie[ge[i]]%MOD;
	}
	for(int i = 1;i<=n;i+=2)ans = ans * jie[gl[i]]%MOD;
	for(int i = 2;i<=n;i+=2)ans = ans * ksm(2,gl[i])%MOD * jie[gl[i]]%MOD;
	for(int i = 2;i<=n;i+=2)ans = ans * ksm(2,gl2[i])%MOD * jie[gl2[i]]%MOD;
	Write((jie[n] - ans + MOD)%MOD); puts("");
	return 0;
}
