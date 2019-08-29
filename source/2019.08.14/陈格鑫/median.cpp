#include <bits/stdc++.h>
using namespace std;

const int N = 500001;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit(c=getchar()) ) if( c=='-' ) f=-1;
	while( isdigit(c) ) num=(num<<1)+(num<<3)+(c&15), c=getchar();
	return num*f;
}
template <typename _Tp> void write (_Tp x)
{
	if( x>9 ) write<_Tp>(x/10);
	putchar(x%10+'0');
}

priority_queue <int> q;
int n, m;
int l1, r1, l2, r2;
int a[N], b[N];

int main ()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	int p0, x, y, z;
	int nw, asd, zxc, qwe;
	scanf("%d%d", &n,&m);
	for(register int i=1; i<=n; ++i) a[i]=read<int>();
	for(register int i=1; i<=n; ++i) b[i]=read<int>();
	for(register int i=1; i<=m; ++i)
	{
		p0=read<int>();
		if( p0&1 )//p0==1
		{
			x=read<int>(), y=read<int>(), z=read<int>();
			if( !x ) a[y]=z;
			else b[y]=z;
		}
		else//p0==2
		{
			l1=read<int>(), r1=read<int>(),
			l2=read<int>(), r2=read<int>();
			asd=r1-l1+1, zxc=r2-l2+1, qwe=(asd+zxc)>>1;
			if( a[r1]<=b[l2] )
			{
				if( asd<=qwe ) write(b[l2+qwe-asd]);
				else write(a[l1+qwe]);
			}
			else if( b[r2]<=a[l1] )
			{
				if( zxc<=qwe ) write(a[l1+qwe-asd]);
				else write(b[l2+qwe]);
			}
			else
			{
				nw=1;
				for(register int i=l1; i<=r1; ++i) q.push(a[i]);
				for(register int i=l2; i<=r2; ++i) q.push(b[i]);
				while( nw<=qwe ) ++nw, q.pop();
				write(q.top());
				while( !q.empty() ) q.pop();
			}
			putchar('\n');
		}
	}
	return 0;
}
