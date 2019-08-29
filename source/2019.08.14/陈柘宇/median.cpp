#include<bits/stdc++.h>
#define MAXN 1000000
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
int a[MAXN+1];
int b[MAXN+1];
int n,m;
int chk(int a[],int b[],int cn,int cm,int mu)
{
	int lin2 = mu-(cn-1);
	if(lin2 < 0)return 1;
	if(lin2 == 0){
		if(b[lin2+1] < a[cn])return 1;
		return 0;
	}
	if(lin2 < cm){
		if(b[lin2] > a[cn])return -1;
		if(b[lin2+1] < a[cn])return 1;
		return 0;
	} 
	if(lin2 == cm){
		if(b[lin2] > a[cn])return -1;
		return 0;
	}
	return -1;
}
int erfen(int a[],int b[],int cn,int cm)
{
	if(chk(a,b,cn,cm,(cn+cm)>>1) == 0)return a[cn];
	if(chk(a,b,cn,cm,(cn+cm)>>1) == -1)return -1;
	if(chk(a,b,1,cm,(cn+cm)>>1) == 1)return -1;
	int l = 1,r = cn;
	while(l<r-1)
	{
		int zh = (l+r)>>1;
		if(chk(a,b,zh,cm,(cn+cm)>>1) > 0)r = zh;
		else l = zh;
	}
	return chk(a,b,l,cm,(cn+cm)>>1) == 0 ? a[l] : -1;
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	Read(n); Read(m);
	for(int i = 1;i<=n;i++)Read(a[i]);
	for(int i = 1;i<=n;i++)Read(b[i]);
	for(int i = 1;i<=m;i++)
	{
		int bx;
		Read(bx);
		if(bx == 1){
			int bn,bm,by;
			Read(bn); Read(bm); Read(by);
			if(bn == 0)a[bm] = by;
			else b[bm] = by;
		}
		else{
			int l1,l2,r1,r2;
			Read(l1); Read(r1); Read(l2); Read(r2);
			int lin1 = erfen(a+(l1-1),b+(l2-1),r1-l1+1,r2-l2+1);
			int lin2 = erfen(b+(l2-1),a+(l1-1),r2-l2+1,r1-l1+1);
			Write(max(lin1,lin2)); putchar('\n');
		}
	}
	return 0;
}
