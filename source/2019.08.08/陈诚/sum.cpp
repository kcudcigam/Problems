#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5+5;
template <typename T> void read(T &x)
{
    int f=1;x=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-f;
    for(; isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
inline void wrote(int x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10) {putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
inline void writeln(int x)
{
	wrote(x);
	puts("");
}
int n,a[N];
ll s[N],ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1; i<=n; ++i)
	{
		read(a[i]);
		s[i]=a[i]+s[i-1];
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=i; j<=n; ++j)
		{
			for(int k=j+1; k<=n; ++k)
			{
				for(int ii=k; ii<=n; ++ii)
				{
					ans=max(ans,s[j+1]-s[i]+s[ii+1]-s[k]);
				}
			}
		}
	}
	writeln(ans);
	return 0;
}

