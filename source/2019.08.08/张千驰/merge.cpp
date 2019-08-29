#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int n,q,f[500010],lemon[500010],o,a,b;

inline int findf(int x)
{
	return f[x]==x?x:f[x]=findf(f[x]);
}

inline void merge(int x,int y)
{
	f[findf(x)]=findf(y);
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	memset(lemon,0,sizeof(lemon));
	read(n);
	read(q); 
	for (register int i=1;i<=n;++i)
		f[i]=i;
	for (register int i=1;i<=q;++i)
	{
		read(o);
		read(a);
		read(b);
		if (o==1)
			merge(a,b);
		if (o==2)
			for (register int j=1;j<=n;++j)
			{
				int fa=findf(a);
				if (findf(j)==fa)
					lemon[j]+=b;
			}
	}
	for (register int i=1;i<=n;++i)
		printf("%d ",lemon[i]);
	
	return 0;
} 
