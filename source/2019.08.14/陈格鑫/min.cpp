#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

template <typename _Tp> _Tp read ()
{
	register int f=1; register _Tp num=0; register char c;
	while( !isdigit(c=getchar()) ) if( c=='-' ) f=-1;
	while( isdigit(c) ) num=(num<<1)+(num<<3)+(c&15), c=getchar();
	return num*f;
}

priority_queue < pair<int, int> > q;
bool b[N];
int n;
long long A, B, C, D;
long long ans;
long long a[N], g[N];

int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d%lld%lld%lld%lld", &n,&A,&B,&C,&D);
	for(register int i=1; i<=n; ++i) a[i]=read<long long>();
	
	for(register int i=1; i<=n; ++i)
	{
		g[i]=A*a[i]*a[i]*a[i]+B*a[i]*a[i]+C*a[i]+D;
		if( g[i]>=0 ) b[i]=1, ans+=g[i];
	}
	for(register int i=1; i<=n; ++i)
	{
		if( !b[i] )
		{
			for(register int j=i; j<=n; ++j)
			{
				if( b[j] )
				{
					int gtx;
					for(register int k=i; k<j; ++k)
						q.push(make_pair(a[k], k));
					while( !q.empty() ) gtx=q.top().second, q.pop();
					ans+=g[gtx];
					i=j;
					break;
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
