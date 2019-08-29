#include <bits/stdc++.h>
using namespace std;

const int N = 500001;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit ( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) + (c&15), c=getchar();
	return num*f;
}
template <typename _Tp> void write (_Tp x)
{
	if( x<0 ) putchar('-'), write<_Tp>(~x+1);
	else
	{
		if( x>9 ) write<_Tp>(x/10);
		putchar(x%10+'0');
	}
}

int n, q;
int f[N];
long long ans[N];

int find (int x) { return f[x]!=x ?f[x]=find(f[x]) :x; }

inline void merge (int x, int y) { f[find(x)]=find(y); }

int main ()
{
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	int op, a;
	scanf("%d%d", &n,&q);
	for(register int i=1; i<=n; ++i) f[i]=i; 
	while( q-- )
	{
		op=read<int>();
		if( op&1 )
		{
			int b;
			a=read<int>(), b=read<int>();
		    if( f[a] != f[b] ) merge(a, b);
		}
		else
		{
			long long b;
			a=read<int>(), b=read<long long>();
			for(register int i=1; i<=n; ++i)
			{
				if( f[i] != f[a] ) continue;
				ans[i]+=b;
			}
		}
	}
	for(register int i=1; i<=n; ++i)
	  write(ans[i]), putchar(' ');
	return 0;
}
