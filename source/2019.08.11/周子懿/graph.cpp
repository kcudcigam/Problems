#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=300010;
int head[N],size,n,m,q;
struct Arc
{
	Arc(int _u,int _v,int _w,int _next):
	u(_u),v(_v),w(_w),next(_next){}
	Arc(){}
	int u,v,w,next;
}e[N];
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
void add(int u,int v,int w)
{
	e[++size]=Arc(u,v,w,head[u]);
	head[u]=size;
}
void init()
{
	read(n);read(m);read(q);
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);read(z);
		add(x,y,z);
		add(y,x,z);
	}
}
void work()
{
	
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	init();
	work();
	return 0;
}


