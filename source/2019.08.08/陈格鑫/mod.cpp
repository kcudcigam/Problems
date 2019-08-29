#include <bits/stdc++.h>
using namespace std;

const int N = 3001;

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

bool b[N];
int n, num;
long long ans, p;
int op[N], ui[N][N];

void dfs (int qwe)
{
	if( qwe > n )
	{
		++num;
		for(int i=1; i<=n; ++i) ui[num][i]=op[i];
		return;
	}
	for(int i=1; i<=n; ++i)
	  if( !b[i] ) b[i]=1, op[qwe]=i, dfs(qwe+1), b[i]=0;
}

int main ()
{
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	int q;
	scanf("%d", &q);
	while( q-- )
	{
		n=read<int>(), p=read<long long>();
		dfs(1);
		for(register int i=1; i<num; ++i)
		  for(register int j=1; j<=n; ++j)
		    if( ui[i][j] != ui[i+1][j] ){
		    	++ans;
		    	if( ans>=p ) ans-=p;
			}
		write(ans%p), putchar('\n');
		for(register int i=1; i<=n; ++i) b[i]=0;
	}
	return 0;
}
