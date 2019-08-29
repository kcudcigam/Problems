#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template <typename T> inline void rd(T &x)
{
	x=0; int f=1; char ch=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10) {putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
int t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rd(t);
	for(int i=1; i<=t; ++i)
	{
		wrote(1);puts("");
	}
	return 0;
}

