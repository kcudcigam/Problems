#include <bits/stdc++.h>
using namespace std;

const int N = 10000007;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit( c=getchar() ) ) if( c == '-' ) f=-1;
	while( isdigit(c) ) num= (num<<1) + (num<<3) + (c&15), c=getchar();
	return num*f;
}

struct node
{
	int x, y;
}op[N];
int n, m;
int x1, x2, x3, x4, x5;
long long ans;
long long d[N];

inline bool comp (const node &a, const node &b)
{
	if( a.y != b.y ) return a.y < b.y;
	return a.x < b.x;
}

int main ()
{
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	int x, y;
	scanf("%d%d", &n,&m);
	scanf("%d%d%d%d%d", &x1,&x2,&x3,&x4,&x5);
	for(register int i=1; i<=n; ++i)
	  op[i].x=read<int>(), op[i].y=read<int>();
	sort(op+1, op+n+1, comp);
	for(register int i=1; i<=n; ++i) ++d[i];
	for(register int i=2; i<=n; ++i)
	  for(register int j=1; j<i; ++j)
	  {
	  	  if( op[i].x <= op[j].y )
	  	  {
	  	  	 ++d[j], --d[i]; break;
		  }
      }
    for(register int i=1; i<=n; ++i)
    ans+= x1*d[i] + x2*pow(d[i], 2) + x3*pow(d[i], 3) + x4*pow(d[i], 4) + x5*pow(d[i], 5);
	printf("%lld", ans);
	return 0;
}
