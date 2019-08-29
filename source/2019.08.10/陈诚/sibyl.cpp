#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
inline int rd()
{
	int x=0; char ch=0; bool s=0;
	while(!isdigit(ch)){s|=(ch=='-'); ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-48; ch=getchar();}
	return s?-x:x;
}
inline void wrote(int x)
{
	if(x<0){putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
inline void writeln(int x)
{
	wrote(x);
	puts("");
}
vector <int> g[N];
ll val[N],delta[N];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n=rd(),m=rd(),Q=rd();
	for(int i=1; i<=m; ++i)
	{
		int x=rd(),y=rd();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	while(Q--)
	{
		int op=rd();
		if(op==0)
		{
			int x=rd();
			int ans=0;
			for(int i=0; i<g[x].size(); ++i)
				ans+=delta[g[x][i]];
			writeln(ans);
		}
		if(op==1)
		{
			int x=rd(),y=rd();
			val[x]+=y;
			delta[x]+=y;
		}
	}
	return 0;
}



