#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
const int M = 600002;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) + (c&15), c=getchar();
	return num*f;
}

int n, m, Q;
int tot=1, head[N], to[M], next[M];
long long d[N];

inline void add (int x, int y)
{
	next[++tot]=head[x], to[tot]=y, head[x]=tot;
	next[++tot]=head[y], to[tot]=x, head[y]=tot;
}

int main ()
{
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	int x, type;
	long long y;
	scanf("%d%d%d", &n,&m,&Q);
	for(register int i=1; i<=m; ++i)
	  add(read<int>(), read<int>());
	while( Q-- )
	{
		type=read<int>();
		if( !type )
		{
			x=read<int>();
			printf("%lld\n", d[x]);
		}
		else
		{
			x=read<int>(), y=read<long long>();
			d[x]+=y;
			for(register int i=head[x]; i; i=next[i]) d[to[i]]+=y;
		}
	}
	return 0;
}
