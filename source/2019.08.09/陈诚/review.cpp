#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
inline int rd()
{
	int x=0; bool s=0; char ch=0;
	while(!isdigit(ch)) {s|=(ch=='-'); ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch-48); ch=getchar();}
	return s?-x:x;
}
inline void wrote(int x)
{
	if(x<0){putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
inline void writeln(int x,int y)
{
	wrote(x); putchar(' '); wrote(y);
	puts("");
}
ll ok(ll y)
{
	for(int i=1; i<=64; ++i)
		if(1<<i==y) return i;
	return 0;
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ll y=rd();
	if(y==1)
	{
		writeln(2,1);
		writeln(1,2);
		return 0;
	}
	if(y==3)
	{
		writeln(4,5);
		writeln(1,2);
		writeln(1,3);
		writeln(1,4);
		writeln(2,4);
		writeln(3,4);
		return 0;
	}
	if(y==5)
	{
		writeln(5,8);
		writeln(1,2);
		writeln(1,3);
		writeln(1,4);
		writeln(2,3);
		writeln(2,4);
		writeln(2,5);
		writeln(3,4);
		writeln(4,5);
		return 0;
	}
	if(ok(y))
	{
		ll n=ok(y)+2;
		writeln(n,n*(n-1)/2);
		for(ll i=1; i<n; ++i)
		{
			for(ll j=i+1; j<=n; ++j)
			{
				writeln(i,j);
			}
		}
		return 0;
	}
	writeln(y+2,y*2);
	for(int i=2; i<=y+1; ++i)
		writeln(1,i);
	return 0;
}


