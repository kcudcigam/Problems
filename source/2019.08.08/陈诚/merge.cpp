#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 500005;
template <typename T> void read(T &x)
{
    int f=1;x=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for(; isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
inline void wrote(int x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10) {putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
inline void writeln(int x)
{
	wrote(x);
	puts("");
}
int n,q,f[N],op,x,y,a[N];
int roots(int x)
{
	return f[x]==x?x:f[x]=roots(f[x]);
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n); read(q);
	for(int i=1; i<=n; ++i)
	{
		f[i]=i;
	}
	for(int i=1; i<=q; ++i)
	{
		read(op);
		if(op==1)
		{
			read(x); read(y);
			if(roots(x)!=roots(y))
			{
				f[roots(y)]=roots(x);
			}
		}
		if(op==2)
		{
			read(x); read(y);
			for(int j=1; j<=n; ++j)
				if(roots(j)==roots(x)) a[j]+=y;
		}
	}
	for(int i=1; i<n; ++i)
	{
		wrote(a[i]);
		putchar(' ');
	}
	writeln(a[n]);
	return 0;
}

