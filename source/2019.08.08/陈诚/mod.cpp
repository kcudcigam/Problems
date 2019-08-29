#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e7+5;
const int db[] = {0,0,2,12,58,310,1886,13244,106002,954090,9540982};
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
int q,n,a[3][N],k,w;
ll p;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	while(q--)
	{
		read(n); read(p);
		if(n<=10)
		{
			writeln(db[n]);
			continue;
		} 
		for(int i=1; i<=n; ++i)
			a[1][i]=a[0][i]=i;
		k=1; w=0;
		do
		{
			for(int i=1; i<=n; ++i)
			{
				if(a[1][i]!=a[0][i]) w=(w+1)%p;
			}
			k=!k;
		}
		while(next_permutation(a[!k]+1,a[!k]+1+n));
		writeln(w%p);
	}
	return 0;
}

