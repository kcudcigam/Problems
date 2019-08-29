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

int n, m;
long long a[N];

int main ()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int l, r;
	long long s, e, now, cha;
	scanf("%d%d", &n,&m);
	for(register int i=1; i<=m; ++i)
	{
		l=read<int>(), r=read<int>(),
		s=read<long long>(), e=read<long long>();
		now=s, cha= (e-s) / (r-l);
		for(register int j=l; j<=r; ++j) a[j]+=now, now+=cha;
	}
	long long ans=a[1];
	for(register long long i=2; i<=n; ++i) ans^=a[i];
	printf("%lld ", ans);
	return 0;
}
