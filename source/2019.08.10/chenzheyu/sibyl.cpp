#include<bits/stdc++.h>
#define MAXN 600000
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
	int a,b;
	void getit() {Read(a); Read(b); }
};
int n,m,q;
int Blo;
qwe a[MAXN+1];
int du[MAXN+1];
int he1[MAXN+1],he2[MAXN+1];
int lie1[MAXN+1],lie2[MAXN+1];
int shi[MAXN+1];
int zhi[MAXN+1],zhi2[MAXN+1];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	Read(n); Read(m); Read(q);
	memset(du,0,sizeof(du));
	for(int i = 1;i<=m;i++)a[i].getit(),du[a[i].a]++,du[a[i].b]++;
	Blo = floor(sqrt(m));
	for(int i = 1;i<=n;i++)shi[i] = du[i] >= Blo;
	memset(he1,0,sizeof(he1));
	for(int i = 1;i<=m;i++) {if(shi[a[i].b])he1[a[i].a]++; if(shi[a[i].a])he1[a[i].b]++; }
	for(int i = 1;i<=n+1;i++)he1[i] += he1[i-1];
	for(int i = 1;i<=m;i++) 
	{
		if(shi[a[i].b])lie1[he1[a[i].a]--] = a[i].b; 
		if(shi[a[i].a])lie1[he1[a[i].b]--] = a[i].a; 
	}
	memset(he2,0,sizeof(he2));
	for(int i = 1;i<=m;i++) {if(!shi[a[i].b])he2[a[i].b]++; if(!shi[a[i].a])he2[a[i].a]++; }
	for(int i = 1;i<=n+1;i++)he2[i] += he2[i-1];
	for(int i = 1;i<=m;i++) 
	{
		if(!shi[a[i].a])lie2[he2[a[i].a]--] = a[i].b; 
		if(!shi[a[i].b])lie2[he2[a[i].b]--] = a[i].a; 
	}
	memset(zhi,0,sizeof(zhi)); memset(zhi2,0,sizeof(zhi2));
//	printf("process done\n");
	for(int i = 1;i<=q;i++)
	{
		int bx,by;
		Read(bx); Read(by);
		if(!bx){
			int ans = zhi[by] + zhi2[by];
			for(int j = he1[by]+1;j<=he1[by+1];j++)ans = ans + zhi2[lie1[j]];
			Write(ans); putchar('\n');
		}
		else{
			int bz;
			Read(bz);
			if(shi[by])zhi2[by] += bz;
			else{
				zhi[by] += bz;
				for(int j = he2[by]+1;j<=he2[by+1];j++)zhi[lie2[j]] += bz;
			}
		}
	}
	return 0;
}
