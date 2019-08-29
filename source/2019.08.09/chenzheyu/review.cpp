#include<bits/stdc++.h>
#define LL long long
#define MAXN 10000
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
	int a,b;
	void mk(int cn,int cm) {a = cn; b = cm; }
};
qwe a[MAXN+1];
int alen;
LL n;
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	Read(n); alen = 0;
	for(int i = 63;i>=2;i--)for(int j = i+1;j<=64;j++)a[++alen].mk(i,j);
	for(int i = 0;i<=61;i++)if(n & (1ll<<i))a[++alen].mk(1,63-i);
	Write(64); putchar(' '); Write(alen); putchar('\n');
//	for(int i = 1;i<=alen;i++)Write(a[i].a),putchar(' '),Write(a[i].b),putchar('\n');
	return 0;
}
