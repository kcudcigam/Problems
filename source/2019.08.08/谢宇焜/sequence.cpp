#include<bits/stdc++.h>
#define fir(a, b, c) for(register int a =  b; a <= c; a ++)
#define in inline
using namespace std;

template <typename T> void read(T &x)
{
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}

int n, m;
int a[500010];

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n); read(m);
	int l, r, x ,y;
	fir(i, 1, m)
	{
		read(l);read(r);read(x);read(y);
		int t = (y-x)/(r-l);
		fir(i, l, r)
		{
			a[i] += x;
			x += t;
		}
	}
	long long ans = a[1];
	fir(i, 2, n)
		ans = ans ^ a[i];
	cout<<ans<<endl;
	return 0;
}


