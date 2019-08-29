#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
template <typename T> inline void rd(T &x)
{
	x=0; char ch=0; int f=1;
	for(;!isdigit(ch); ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch); ch=getchar())
		x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48);return;}
	wrote(x/10);
	putchar(x%10+48);
}
int n,m,a[N],b[N],op,x,y,z,la,lb,ra,rb;
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	rd(n); rd(m);
	for(int i=1; i<=n; ++i)	rd(a[i]);
	for(int i=1; i<=n; ++i)	rd(b[i]);
	for(int i=1; i<=m; ++i)
	{
		rd(op);
		if(op==1)
		{
			rd(x); rd(y); rd(z);
			if(x==0) a[y]=z;
			if(x==1) b[y]=z;
		}
		if(op==2)
		{
			rd(la); rd(ra); rd(lb); rd(rb);
			int p[2*N],tot=0;
			for(int i=la; i<=ra; ++i) p[++tot]=a[i];
			for(int i=lb; i<=rb; ++i) p[++tot]=b[i];
			sort(p+1,p+tot+1);
			wrote(p[tot/2+1]); puts("");
		}
	}
	return 0;
}

