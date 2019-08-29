#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) + (c&15), c=getchar();
	return num*f;
}

int n;
int t[N], x[N], y[N];

inline int abs0 (int a, int b){ return (a-b<0) ?(b-a) :(a-b); }

int main ()
{
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(register int i=1; i<=T; ++i)
	{
		int nowx=0, nowy=0, op=0, nowt;
		n=read<int>();
		for(register int i=1; i<=n; ++i)
		{
			t[i]=read<int>(),
			x[i]=read<int>(),
			y[i]=read<int>();
			if( t[i]<0 ) op=1;
		}
		if( op )
		{
			printf("No\n"); continue;
		}
		for(register int i=1; i<=n; ++i)
		{
			nowt= t[i] - t[i-1] - abs0(x[i], nowx) - abs0(y[i], nowy);
			if( !nowt ) nowx=x[i], nowy=y[i];
			else if( nowt<0 || nowt%2 ){
				printf("No");
				op=1;
				break;
			}
			else nowx=x[i], nowy=y[i];
		}
		if( !op ) printf("Yes");
		putchar('\n');
		memset(t, 0, sizeof(t));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
	}
	return 0;
}
