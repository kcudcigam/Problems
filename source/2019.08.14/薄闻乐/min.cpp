#include<bits/stdc++.h>
using namespace std;
int ri() {
char c = getchar(); int x = 0; for(;c < '0' || c > '9'; c = getchar());
for(;c >= '0' && c <= '9'; c = getchar()) x = x * 10 - '0' + c; return x;
}
int ans,n,a,b,c,d,x;
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=ri();
	a=ri();
	b=ri();
	c=ri();
	d=ri();
	for (int i=1;i<=n;i++)
	{
		x=ri();
		ans=ans+x*a*x*x+x*b*x+x*c+d;
	}
	cout<<ans<<endl;
	return 0;
}
