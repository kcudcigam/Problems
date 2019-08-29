#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 100005;
const int P = 1e9+7;
inline int rd()
{
	int x=0; bool s=0; char ch=0;
	while(!isdigit(ch)) {s|=(ch=='-'); ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch-48); ch=getchar();}
	return s?-x:x;
}
inline void wrote(int x)
{
	if(x<0){putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
inline void writeln(int x)
{
	wrote(x);
	puts("");
}
int af[2*N],bf[2*N],ax[N],bx[N],ay[N],by[N],p[2*N],ans;
int aroots(int x)
{
	return af[x]==x?x:af[x]=aroots(af[x]);
}
int broots(int x)
{
	return bf[x]==x?x:bf[x]=broots(bf[x]);
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int n=rd();
	n=rd();
	int am=rd(),bm=rd();
	for(int i=1; i<=n; ++i)
	{
		p[i]=i;
		af[i]=i;
		bf[i]=i;
	}
	for(int i=1; i<=am; ++i)
	{
		int x=rd(),y=rd();
		af[aroots(x)]=aroots(y);
		ax[i]=x; ay[i]=y;
	}
	for(int i=1; i<=bm; ++i)
	{
		int x=rd(),y=rd();
		bf[broots(x)]=broots(y);
		bx[i]=x; by[i]=y;
	}
	
	while(next_permutation(p+1,p+n+1))
	{
		bool f=0;
		for(int i=1; i<=am; ++i)
		{
			if(aroots(p[ax[i]])!=aroots(p[ay[i]]))
			{
				ans=(ans+1)%P;f=1;break;
			}
		}
		if(f==1) continue;
		for(int i=1; i<=bm; ++i)
		{
			if(broots(p[bx[i]])!=broots(p[by[i]]))
			{
				ans=(ans+1)%P;break;
			}
		}
	}
	writeln(ans%P);
	return 0;
}

