#include<bits/stdc++.h>
#define MAXN 600000
#define LL long long
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
int fa[MAXN+1],da[MAXN+1];
int n,q;
LL zha[MAXN+1];
int he[MAXN+1],xu[MAXN+1];
int get_fa(int cn) {return fa[cn] == cn ? cn : get_fa(fa[cn]); }
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	Read(n); Read(q);
	for(int i = 1;i<=n;i++)zha[i] = 0,fa[i] = i,da[i] = 1;
	for(int i = 1;i<=q;i++)
	{
		int bx,by,bz;
		Read(bx); Read(by); Read(bz);
		if(bx == 1) {
			int lin1 = get_fa(bz),lin2 = get_fa(by);
			if(lin1 == lin2)continue;
			if(da[lin1] < da[lin2])swap(lin1,lin2);
			zha[lin2] -= zha[lin1];
			fa[lin2] = lin1;
			da[lin1] += da[lin2];
		}
		else{
			int lin1 = get_fa(by);
			zha[lin1] += bz;
		}
	}
	for(int i = 0;i<=n;i++)he[i] = 0;
	for(int i = 1;i<=n;i++)he[da[i]]++;
	for(int i = 1;i<=n;i++)he[i] = he[i-1] + he[i];
	for(int i = 1;i<=n;i++)xu[he[da[i]]--] = i;
	for(int i = n;i>=1;i--)if(fa[xu[i]] != xu[i])zha[xu[i]] += zha[fa[xu[i]]];
	for(int i = 1;i<=n;i++)Write(zha[i]),putchar(' '); puts("");
	return 0;
}

