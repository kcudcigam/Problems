#include <bits/stdc++.h>
using namespace std;

const int N = 15001;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit ( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) + (c&15), c=getchar();
	return num*f;
}

int n;
int a[N];
long long ans;
long long b[N], c[N][N];

int main ()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	scanf("%d", &n);
	for(register int i=1; i<=n; ++i)
	  a[i]=read<int>(), b[i]= b[i-1] + a[i];
	for(register int i=1; i<=n; ++i)
	  for(register int j=1; j<=n; ++j)
	    c[i][j]= b[j] - b[i-1];
	for(register int i=1; i<n; ++i)
	  for(register int j=i+1; j<n; ++j)
	    for(register long int o=j+1; o<=n; ++o)
	      for(register int p=j+1; p<=n; ++p)
	      ans=max(ans, c[o][p]+c[i][j]);
	printf("%lld", ans);
	return 0;
}
